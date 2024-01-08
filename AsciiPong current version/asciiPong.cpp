//asciiPong
#include "PlayGame.h"
#include <iostream>

int main(int argc, char* argv[]){
    std::ios_base::sync_with_stdio(false); //optimize cout

    int height = 92; //Default: 55
    int width = 214; //Default: 203
    int numPointsToWin = 3;
    int framesPerSecond = 30;
    int paddleSize = 10;

    playGame(height, width, numPointsToWin, framesPerSecond, paddleSize); //playGame function runs the game logic

}


