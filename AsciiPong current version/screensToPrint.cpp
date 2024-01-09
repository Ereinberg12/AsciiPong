//screensToPrint.cpp
#include "PlayGame.h"

#include <iostream>
#include <string>

//prints the starting page
void printStartPage(int h, int w, int winningScore){
    clearScreen(); //clear the screen

    //top spacing
    for(int i = 0; i < (h - 10) /2; ++i){std::cout << "\n";}

    for(int i = 0; i < (w - 39) / 2; ++i){std::cout << " ";}
    std::cout << "WELCOME TO ASCII PONG BY ETHAN REINBERG";
    for(int i = (w - 39) / 2; i < w - 39; ++i){std::cout << " ";}

    std::cout << "\n";

    for(int i = 0; i < w; ++i){std::cout << "~";}
    std::cout << "\n";

    std::cout << "\n";

    for(int i = 0; i < (w - 31) / 2; ++i){std::cout << " ";}
    std::cout << "USE W AND S TO CONTROL PLAYER 1";
    for(int i = (w - 31) / 2; i < w - 31; ++i){std::cout << " ";}
    std::cout << "\n";

    std::cout << "\n";

    for(int i = 0; i < (w - 31) / 2; ++i){std::cout << " ";}
    std::cout << "USE P AND L TO CONTROL PLAYER 2";
    for(int i = (w - 31) / 2; i < w - 31; ++i){std::cout << " ";}
    std::cout << "\n";

    std::cout << "\n";

    for(int i = 0; i < (w - 29) / 2; ++i){std::cout << " ";}
    std::cout << "FIRST PLAYER TO " << winningScore << " POINTS WINS";
    for(int i = (w - 29) / 2; i < w - 29; ++i){std::cout << " ";}
    std::cout << "\n";

    std::cout << "\n";

    for(int i = 0; i < (w - 27) / 2; ++i){std::cout << " ";}
    std::cout << "ENTER THE NUMBER OF PLAYERS";
    for(int i = (w - 27) / 2; i < w - 27; ++i){std::cout << " ";}
    std::cout << "\n";

    std::cout << "\n";

    for(int i = 0; i < w / 2; ++i){std::cout << " ";} //center the user's cursor
}

//Functions to print winners
void printP1Wins(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
    for(int i = 0; i < (w-13)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "Player 1 Wins\n";
    for(int i = (w-13)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    for(int i = (h/2) + 1; i < h; ++i){std::cout << "\n";}//vertical spacing
}

void printP2Wins(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
    for(int i = 0; i < (w-13)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "Player 2 Wins\n";
    for(int i = (w-13)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    for(int i = (h/2) + 1; i < h; ++i){std::cout << "\n";}//vertical spacing
}

void printAIWins(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
    for(int i = 0; i < (w-14)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "AI Player Wins\n";
    for(int i = (w-14)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    for(int i = (h/2) + 1; i < h; ++i){std::cout << "\n";}//vertical spacing
}

void printAI1Wins(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
    for(int i = 0; i < (w-16)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "AI Player 1 Wins\n";
    for(int i = (w-16)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    for(int i = (h/2) + 1; i < h; ++i){std::cout << "\n";}//vertical spacing
}

void printAI2Wins(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
    for(int i = 0; i < (w-16)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "AI Player 2 Wins\n";
    for(int i = (w-16)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    for(int i = (h/2) + 1; i < h; ++i){std::cout << "\n";}//vertical spacing
}

//prints the end screen
void printEndScreen(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < (h/2) + 2; ++i){std::cout << "\n";}//vertical spacing (add + 2 to center given that top text is gone)
    for(int i = 0; i < (w-18)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "Thanks for playing";
    for(int i = (w-18)/2; i < w; ++i){std::cout << " ";}//horizontal spacing

    std::cout << "\n";

    for(int i = 0; i < (w-61)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "Check for updates at https://github.com/Ereinberg12/AsciiPong";
    for(int i = (w-61)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    
    for(int i = (h/2) + 1; i < h ; ++i){std::cout << "\n";}//vertical spacing (add extra space to center given that top text is gone)
    std::cout << std::endl; //use endl to flush buffer
}