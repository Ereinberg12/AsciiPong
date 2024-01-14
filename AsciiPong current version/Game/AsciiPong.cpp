//asciiPong.cpp
#include "PlayGame.h"
#include "../StartGameAnimation/StartGameAnimation.h" 
#include <iostream>

void askUserForTerminalSize(int& width, int& height); //not used by default but can be used to manually set the window size

int main(int argc, char* argv[]){
    int numPointsToWin = 3;
    int framesPerSecond = 30;

    //play the start animation
    startGameAnimation();

    //get the size of the terminal
    clearScreen();
    int height;
    int width;
    getTerminalSize(width, height);
    //askUserForTerminalSize(width, height); //not used by default but can be used to manually set the window size

    height = height - 6; //account for top text and lines
    int paddleSize = (height / 10) + 1; //set the paddle size

    //start the game
    playGame(height, width, numPointsToWin, framesPerSecond, paddleSize); //playGame function runs the game logic
}

void askUserForTerminalSize(int& width, int& height){
    std::cout << "Enter your terminal's width:" << std::endl;
    std::cin >> width;
    clearScreen();
    std::cout << "Enter your terminal's height:" << std::endl;
    std::cin >> height;
}

