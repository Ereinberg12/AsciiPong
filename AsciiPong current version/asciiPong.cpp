//asciiPong.cpp
#include "PlayGame.h"
#include <iostream>

int main(int argc, char* argv[]){
    std::ios_base::sync_with_stdio(false); //optimize cout

    int numPointsToWin = 3;
    int framesPerSecond = 30;

    //prompt the user for the width and height of their terminal
    clearScreen();
    std::cout << "Enter your terminal's width:" << std::endl;
    int width;
    std::cin >> width;
    clearScreen();
    int height;
    std::cout << "Enter your terminal's height:" << std::endl;
    std::cin >> height;
    int paddleSize = (height / 10) + 1; //set the paddle size
    height = height - 6; //account for top text and lines

    //start the game
    playGame(height, width, numPointsToWin, framesPerSecond, paddleSize); //playGame function runs the game logic
}


