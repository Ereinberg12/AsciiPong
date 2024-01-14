//terminalCommands.cpp
#include "TerminalCommands.h"
#include "BufferToggle.h"
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
#include <stdlib.h> 
#include <thread> //for threading
#include <chrono> //for threading
#include <fcntl.h> // for fcntl() in keyboardHit()
#include <termios.h>


//clears the screen (only works on linux/mac)
void clearScreen(int numRefreshes){
    for(int i = 0; i < numRefreshes; ++i){
        system("clear"); //clear the screen
    }
}

//gets the size in ascii characters of the user's terminal and returns in the width and height parameters by reference
void getTerminalSize(int& width, int& height){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    height = (int) w.ws_row;
    width = (int )w.ws_col;
}

void wait(double seconds){
    int milliSeconds = seconds * 1000;
    std::this_thread::sleep_for(std::chrono::milliseconds(milliSeconds));
}


//determine if the keyboard was hit and return true if so, false if not
bool keyboardHit(){
    struct termios oldt, newt;
    int oldf;
    int ch;

    //get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    //set terminal to non-canonical mode and disable echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    //set stdin to non-blocking
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    //restore terminal settings and stdin flags
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF){
        ungetc(ch, stdin);  //put character back into buffer if it was read
        return true;
    }

    return false;
}

//uses threading to detect keyboard input
char detectKeyboardInput(int FPS){
    char c = 27; //default input (esc key in ascii)

    std::chrono::milliseconds duration(1000 / FPS);
    auto endTime = std::chrono::steady_clock::now() + duration;

    do {
        if (keyboardHit()) { //check if a key has been pressed
            c = getchar();   //read the key
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5)); //sleep for a bit to prevent busy waiting
    } while (std::chrono::steady_clock::now() < endTime);

    return c;
}

//receives input from the user without them hitting enter
char getImmediateInput(){
    char buf = 0;
    struct termios old = {0}, newt;

    //get current terminal settings
    if(tcgetattr(0, &old) < 0){
        perror("tcgetattr()");
    }

    //copy settings to newt
    newt = old;

    //modify newt for raw input
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;

    //set new settings
    if(tcsetattr(0, TCSANOW, &newt) < 0){
        perror("tcsetattr ICANON");
    }

    //read character
    if(read(0, &buf, 1) < 0){
        perror("read()");
    }

    //restore old settings
    if(tcsetattr(0, TCSANOW, &old) < 0){
        perror("tcsetattr ~ICANON");
    }
    return buf;
}