//playGame.cpp
#include "BufferToggle.h"
#include "PlayGame.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>  //used for random seed
#include <thread> //for threading
#include <chrono> //for threading
#include <fcntl.h> // for fcntl() in keyboardHit()

//FUNCTION IMPLEMENTATIONS

//This function manages the functions for running the game
void playGame(int h, int w, int winScore, int fps, int paddleSize){
    int height = h; //game resolution
    int width = w; //game resolution
    int winningScore = winScore; //declare the number of points required to win
    int FPS = fps; //declare the number of frames per second
    int numPlayers;

    //Turn off the input buffer
    BufferToggle toggle;
    toggle.off();

    bool playAgain = true; //set the variable that controls whether the game is played to true
    while(playAgain){
        printStartPage(height, width, winningScore);

        std::cout << std::flush; //flush the buffer to use getImmediateInput()
        numPlayers = getImmediateInput() - '0'; //ask the user for the number of players (subtract '0' since its stored as a char)

        std::this_thread::sleep_for(std::chrono::milliseconds(200)); //load to add suspense

        //determine whether or not you should use AI for player 1 and player 2 based on user input
        int aiParameter = 1;
        if(numPlayers == 2){
            aiParameter = 0;
        }
        else if(numPlayers == 1){
            aiParameter = 1;
        }
        else{
            aiParameter = 2;
        }

        //TO DO: prompt user for ai difficulty if neccessary
        int ai1Difficulty = 0;
        int ai2Difficulty = 0;

        //if the computer is controlling both players
        if(aiParameter == 2){
            ai1Difficulty = askAiDifficulty(height, width, 1, aiParameter); 
            ai2Difficulty =  askAiDifficulty(height, width, 2, aiParameter);   
        }
        else if(aiParameter == 1){//if the computer is only controlling player 2
            ai2Difficulty = askAiDifficulty(height, width, 2, aiParameter); 
        }

        //generate random seed
        time_t timer;
        time(&timer);
        srand(time(nullptr));

        //create a grid of chars to display
        PongManager pongManager(height, width, paddleSize); //57 x 203 is full screen on my computer (2 rows on top for text)
        
        char userInput = 'S'; //set the user input to S for start

        bool startOfGame = true;

        char killKey = 'Q'; //if user types this letter, game terminates

        while(userInput != killKey){
            clearScreen(); //clear the screen
            
            pongManager.printGrid(aiParameter); //print the grid to the user

            if(startOfGame){//if start of game, delay the ball moving by .25 sec
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
                startOfGame = false;
            }

            userInput = detectKeyboardInput(FPS); //recieve user input

            //update P1's vertical position
            if(!(aiParameter == 2)){
                if (userInput == 'w'){
                    pongManager.updateP1(true);
                    pongManager.updateP1(true); //changed to update twice to allow player to move faster
                }
                else if(userInput == 's'){
                    pongManager.updateP1(false);
                    pongManager.updateP1(false); //changed to update twice to allow player to move faster
                }
            }
            else{//if the AI is selected, have it move p1's paddle
                pongManager.aiMove(1, ai1Difficulty, ai2Difficulty);
                pongManager.aiMove(1, ai1Difficulty, ai2Difficulty);
            }

            //Update P2's vertical position
            if(aiParameter == 0){
                if (userInput == 'p'){
                    pongManager.updateP2(true);
                    pongManager.updateP2(true); //changed to update twice to allow player to move faster
                }
                else if(userInput == 'l'){
                    pongManager.updateP2(false);
                    pongManager.updateP2(false); //changed to update twice to allow player to move faster
                }
            }
            else{//if the AI is selected, have it move p2's paddle
                pongManager.aiMove(2, ai1Difficulty, ai2Difficulty);
                pongManager.aiMove(2, ai1Difficulty, ai2Difficulty);
            }

            //update the ball's position
            pongManager.moveBall(FPS);

            //readd the paddles to solve glitch when player wins point and ball gets printed over paddle
            pongManager.addPaddles();

            std::this_thread::sleep_for(std::chrono::milliseconds(250/FPS)); //wait a bit to help eliminate flashing on screen

            //check for winner
            bool isWinner = checkForWinner(pongManager, winningScore, aiParameter);
            if(isWinner){
                clearScreen(); //reset the view if someone won
                pongManager.reset(); //reset the view if someone won
                pongManager.printGrid(aiParameter); //reset the view if someone won
                std::this_thread::sleep_for(std::chrono::milliseconds(250)); //wait a quarter second so the winner doesn't print right away

                if(pongManager.p1Score > pongManager.p2Score){//if player 1 won
                    if(aiParameter == 0 || aiParameter == 1){printP1Wins(height, width);}
                    else{printAI1Wins(height, width);}
                }
                else{//if player 2 won
                    if(aiParameter == 0){printP2Wins(height, width);} 
                    else if (aiParameter == 1){printAIWins(height, width);}
                    else{printAI2Wins(height, width);}
                }

                std::cout << std::flush; //flush the buffer

                std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //wait 2 seconds before asking if the user wants to play again

                clearScreen();
                playAgain = askPlayAgain(height, width); //prompt the user to play again
                if(playAgain){//reset the scores if they choose to play again
                    pongManager.p1Score = 0;
                    pongManager.p2Score = 0;
                    break;
                }
                else{
                    userInput = killKey;
                }
                
            }

            if(userInput == killKey){//if the user hits Q, don't play again regardless of previous input
                playAgain = false;
            }
            
        }
        
    }//end of playAgain loop

    //display end screen
    printEndScreen(height, width);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    //turn the input buffer back on
    toggle.on();
    clearScreen(); //clear the screen when the game is over
    return;
}

//determine if the keyboard was hit and return true if so, false if not
bool keyboardHit() {
    struct termios oldt, newt;
    int oldf;
    int ch;

    //Get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    //Set terminal to non-canonical mode and disable echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    //Set stdin to non-blocking
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    //Restore terminal settings and stdin flags
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF){
        ungetc(ch, stdin);  //Put character back into buffer if it was read
        return true;
    }

    return false;
}

//uses threading to detect keyboard input
char detectKeyboardInput(int FPS) {
    char c = 'n'; // Default input

    std::chrono::milliseconds duration(1000 / FPS);
    auto endTime = std::chrono::steady_clock::now() + duration;

    do {
        if (keyboardHit()) { // Check if a key has been pressed
            c = getchar();   // Read the key
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5)); // Sleep for a bit to prevent busy waiting
    } while (std::chrono::steady_clock::now() < endTime);

    return c;
}

//checks the game for a winner, returns true if a player has won
bool checkForWinner(PongManager& pongManager, int winningScore, int aiParameter){
    //check for winner
    if(pongManager.checkForWinner() == 1){
        pongManager.p1Score++; //increment player1's score

        if(pongManager.p1Score >= winningScore){
            system("clear"); //clear the screen
            pongManager.printGrid(aiParameter);
            return true;
        }

        pongManager.reset(); //reset grid
        clearScreen(); //clear the screen
        pongManager.printGrid(aiParameter); //logic for making ball wait .25 sec after point scored
        std::this_thread::sleep_for(std::chrono::milliseconds(250)); //logic for making ball wait .25 sec after point scored
    }
    else if (pongManager.checkForWinner() == 2){
        pongManager.p2Score++; //increment player2's score

        if(pongManager.p2Score >= winningScore){
            system("clear"); //clear the screen
            pongManager.printGrid(aiParameter);
            return true;
        }

        pongManager.reset(); //reset grid
        clearScreen(); //clear the screen
        pongManager.printGrid(aiParameter); //logic for making ball wait .25 sec after point scored
        std::this_thread::sleep_for(std::chrono::milliseconds(250)); //logic for making ball wait .25 sec after point scored
    }
    return false;
}

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

void printEndScreen(int h, int w){
    clearScreen(); //clear the screen
    for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
    for(int i = 0; i < (w-18)/2; ++i){std::cout << " ";}//horizontal spacing
    std::cout << "Thanks for playing\n";
    for(int i = (w-18)/2; i < w; ++i){std::cout << " ";}//horizontal spacing
    for(int i = (h/2) + 1; i < h - 1; ++i){std::cout << "\n";}//vertical spacing
    std::cout << std::endl; //use endl to flush buffer
}

//clears the screen (only works on linux/mac)
void clearScreen(int numRefreshes){
    for(int i = 0; i < numRefreshes; ++i){
        system("clear"); //clear the screen
    }
}

//prompts the player if they want to play again, returns yes if play again, no if terminate
bool askPlayAgain(int h, int w){
    char userInput; //get user input
    do{
        clearScreen();
        for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
        for(int i = 0; i < (w-35)/2; ++i){std::cout << " ";}//horizontal spacing
        std::cout << "DO YOU WANT TO PLAY AGAIN? (Y OR N)\n";
        for(int i = (w-35)/2; i < w; ++i){std::cout << " ";}//horizontal spacing

        std::cout << "\n";

        for(int i = 0; i < w/2; ++i){std::cout << " ";} //center the user's cursor
        std::cout << std::flush; //flush buffer before using getImmediateInput()
        userInput = getImmediateInput();
        
        userInput = toupper(userInput); //convert the letter the user entered to uppercase
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    } while(userInput != 'Y' && userInput != 'N');
    
    if(userInput == 'Y'){return true;} //if the user choose to play again
    else{return false;} //if the user did NOT choose to play again
}

//ask the user for the AI difficulty
int askAiDifficulty(int h, int w, int player, int aiParameter){
    char userInput; //get user input
    do{
        clearScreen();
        for(int i = 0; i < h/2; ++i){std::cout << "\n";}//vertical spacing
        for(int i = 0; i < (w-29)/2; ++i){std::cout << " ";}//horizontal spacing

        std::cout << "Choose "; 
        if(player == 1 || aiParameter == 1){
            std::cout << "AI1 "; 
        }
        else if (player == 2){
            std::cout << "AI2 ";
        }
        std::cout << "Difficulty [0 - 9]\n"; 

        for(int i = (w-29)/2; i < w; ++i){std::cout << " ";}//horizontal spacing

        std::cout << "\n";

        for(int i = 0; i < w/2; ++i){std::cout << " ";} //center the user's cursor
        std::cout << std::flush; //flush buffer before using getImmediateInput()
        userInput = getImmediateInput();
        
        userInput = toupper(userInput); //convert the letter the user entered to uppercase
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    } while(userInput - '0' < 0 || userInput - '0' > 9);

    //return the user input as a char 0 - 9
    //subtract 48 to make returned char into correct int; '0' is 48 in ascii
    return (int) userInput - 48;
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


