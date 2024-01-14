//playGame.cpp
#include "../TerminalCommands/BufferToggle.h"
#include "PlayGame.h"
#include "ScreensToPrint.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>  //used for random seed
#include <thread> //for threading
#include <chrono> //for threading

//FUNCTION IMPLEMENTATIONS

//This function manages the functions for running the game
void playGame(int h, int w, int winScore, int fps, int paddleSize){
    int height = h; //game resolution
    int width = w; //game resolution
    int winningScore = winScore; //declare the number of points required to win
    int FPS = fps; //declare the number of frames per second
    int numPlayers; //set to something other than 0, 1, or 2 to enter the loop prompting the player for the number of players

    //Turn off the input buffer
    BufferToggle toggle;
    toggle.off();

    bool playAgain = true; //set the variable that controls whether the game is played to true
    while(playAgain){
        numPlayers = -1; //set to -1 so user is prompted when replaying game
        //prompt the user for the number of players until they enter 0, 1, or 2
        while(numPlayers != 0 && numPlayers != 1 && numPlayers != 2){
            clearScreen();
            printStartPage(height, width, winningScore);

            std::cout << std::flush; //flush the buffer to use getImmediateInput()
            numPlayers = getImmediateInput() - '0'; //ask the user for the number of players (subtract '0' since its stored as a char)

            std::this_thread::sleep_for(std::chrono::milliseconds(200)); //load to add suspense
        }

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

        //prompt user for ai difficulty if neccessary
        int ai1Difficulty = 0;
        int ai2Difficulty = 0;

        //if the computer is controlling both players
        if(aiParameter == 2){
            ai1Difficulty = askAiDifficulty(height, width, 1, aiParameter);
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); //load to add suspense 
            ai2Difficulty =  askAiDifficulty(height, width, 2, aiParameter);
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); //load to add suspense   
        }
        else if(aiParameter == 1){//if the computer is only controlling player 2
            ai2Difficulty = askAiDifficulty(height, width, 2, aiParameter); 
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); //load to add suspense
        }

        //generate random seed
        time_t timer;
        time(&timer);
        srand(time(nullptr));

        //create a grid of chars to display
        PongManager pongManager(height, width, paddleSize); //57 x 203 is full screen on my computer (2 rows on top for text)

        pongManager.ball.horizontalSpeed = pongManager.width / 6;
        
        char userInput = 'S'; //set the user input to S for start

        bool startOfGame = true;

        char killKey = 'Q'; //if user types this symbol, game terminates

        char pauseKey = ' '; //if user types this symbol, game pauses

        while(userInput != killKey){
            //check if the game is paused
            bool paused = false;
            bool quitFromPause = false;
            bool userPressedPauseKeyAgain = false;
            while(userInput == pauseKey && !userPressedPauseKeyAgain){
                paused = true;
                userInput = detectKeyboardInput(FPS);
                if(userInput == 27){//27 is ascii for esc key which is the default key returned if no key is pressed
                    userInput = pauseKey;
                }
                else if(userInput == pauseKey){
                    paused = false;
                    userPressedPauseKeyAgain = true;
                }
                else if(userInput != killKey){
                    paused = false;
                }
                else{//if the user wants to quit the game while it's paused
                    paused = false;
                    quitFromPause = true;
                }

                clearScreen(); //clear the screen
                pongManager.printGrid(aiParameter, killKey, pauseKey, paused); //update the grid now that pause button has changed

                std::this_thread::sleep_for(std::chrono::milliseconds(200)); //wait .2 sec so game runs at 5fps when paused
            }//if the code reaches here, the game is not paused
            if(quitFromPause){//code to check if game should continue after pause
                playAgain = false;
                break;
            }

            clearScreen(); //clear the screen
            
            pongManager.printGrid(aiParameter, killKey, pauseKey, paused); //print the grid to the user

            if(startOfGame){//if start of game, delay the ball moving by .25 sec
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
                startOfGame = false;
            }

            userInput = detectKeyboardInput(FPS); //recieve user input

            int numSpacesToMovePaddle = std::max((paddleSize / 3), 1); //decide how many positions to move the paddle when moving

            //update P1's vertical position
            if(!(aiParameter == 2)){
                if (userInput == 'w'){
                    for(int i = 0; i < numSpacesToMovePaddle; ++i){
                        pongManager.updateP1(true); //move up  
                    }
                }
                else if(userInput == 's'){
                    for(int i = 0; i < numSpacesToMovePaddle; ++i){
                        pongManager.updateP1(false); //move down
                    }
                }
            }
            else{//if the AI is selected, have it move p1's paddle
                for(int i = 0; i < numSpacesToMovePaddle; ++i){
                    pongManager.aiMove(1, ai1Difficulty, ai2Difficulty);
                }
            }

            //Update P2's vertical position
            if(aiParameter == 0){
                if (userInput == 'p'){
                    for(int i = 0; i < numSpacesToMovePaddle; ++i){
                        pongManager.updateP2(true); //move up
                    }
                }
                else if(userInput == 'l'){
                    for(int i = 0; i < numSpacesToMovePaddle; ++i){
                        pongManager.updateP2(false); //move down
                    }
                }
            }
            else{//if the AI is selected, have it move p2's paddle
                for(int i = 0; i < numSpacesToMovePaddle; ++i){
                    pongManager.aiMove(2, ai1Difficulty, ai2Difficulty);
                }
            }

            //update the ball's position
            pongManager.moveBall(FPS);

            //readd the paddles to solve glitch when player wins point and ball gets printed over paddle
            pongManager.addPaddles();

            std::this_thread::sleep_for(std::chrono::milliseconds(300/FPS)); //wait a bit to help eliminate flashing on screen

            //check for winner
            bool isWinner = checkForWinner(pongManager, winningScore, aiParameter, killKey, pauseKey, paused);
            if(isWinner){
                clearScreen(); //reset the view if someone won
                pongManager.reset(); //reset the view if someone won
                pongManager.printGrid(aiParameter, killKey, pauseKey, paused); //reset the view if someone won
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
                else{//set the userInput to the killKey if the user chooses not to play again
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
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    //turn the input buffer back on
    toggle.on();
    clearScreen(); //clear the screen when the game is over (might remove later so end screen stays on)
    return;
}

//checks the game for a winner, returns true if a player has won
bool checkForWinner(PongManager& pongManager, int winningScore, int aiParameter, char killKey, char pauseKey, bool paused){
    //check for winner
    if(pongManager.checkForWinner() == 1){
        pongManager.p1Score++; //increment player1's score

        if(pongManager.p1Score >= winningScore){
            system("clear"); //clear the screen
            pongManager.printGrid(aiParameter, killKey, pauseKey, paused);
            return true;
        }

        pongManager.reset(); //reset grid
        clearScreen(); //clear the screen
        pongManager.printGrid(aiParameter, killKey, pauseKey, paused); //logic for making ball wait .25 sec after point scored
        std::this_thread::sleep_for(std::chrono::milliseconds(250)); //logic for making ball wait .25 sec after point scored
    }
    else if (pongManager.checkForWinner() == 2){
        pongManager.p2Score++; //increment player2's score

        if(pongManager.p2Score >= winningScore){
            system("clear"); //clear the screen
            pongManager.printGrid(aiParameter, killKey, pauseKey, paused);
            return true;
        }

        pongManager.reset(); //reset grid
        clearScreen(); //clear the screen
        pongManager.printGrid(aiParameter, killKey, pauseKey, paused); //logic for making ball wait .25 sec after point scored
        std::this_thread::sleep_for(std::chrono::milliseconds(250)); //logic for making ball wait .25 sec after point scored
    }
    return false;
}

//prompts the player if they want to play again, returns yes if play again, no if terminate
bool askPlayAgain(int h, int w){
    char userInput = ' '; //get user input
    while(userInput != 'Y' && userInput != 'N'){
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
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); //delay so text updates at 5 fps if user enters invald input
    }
    
    if(userInput == 'Y'){return true;} //if the user choose to play again
    else{return false;} //if the user did NOT choose to play again
}

int askAiDifficulty(int h, int w, int player, int aiParameter){
    char userInput = ' '; //get user input
    while(userInput - '0' < 0 || userInput - '0' > 9){
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
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); //delay so text updates at 5 fps if user enters invald input
    }

    //return the user input as a char 0 - 9
    //subtract 48 to make returned char into correct int; '0' is 48 in ascii
    return (int) userInput - 48;
}


