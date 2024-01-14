//StartGameAnimation.cpp
#include "LargeTextScreen.h"

void startGameAnimation(){
    int frameRate = 10;

    //get the user's terminal size
    int height, width;
    getTerminalSize(width, height);
    int maxHeight = 5*height;
    //initialize the screen
    largeTextScreen screen = largeTextScreen(width, maxHeight, height);

    std::string textToDisplay = "Welcome to ascii-pong by Ethan Reinberg";
    std::string textCurrentlyOnScreen;

    for(int i = 0; i < (int) textToDisplay.length(); ++i){
        //clear screen and reset pixel grid
        screen.resetAllPixels();
        clearScreen();

        //add the next letter
        textCurrentlyOnScreen += textToDisplay[i];

        //add the letters
        screen.addLargeText(textCurrentlyOnScreen);
        //center the text
        screen.centerTextHorizontally();
        screen.centerTextVertically();
        //display the text to the user
        screen.display(height);

        double timeToWait = 1.0 / (double) frameRate;
        wait(timeToWait);
    }

    //wait so the user can read the into screen
    wait(3);
    //clear the screen
    clearScreen();
}
