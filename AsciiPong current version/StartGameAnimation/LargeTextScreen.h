#ifndef LARGE_TEXT_SCREEN
#define LARGE_TEXT_SCREEN

#include "ParseStringIntoWords.h"
#include "LargeTextLibrary.h"
#include "../TerminalCommands/TerminalCommands.h"
#include "Letter.h"

class largeTextScreen{
    public:
    largeTextScreen(); //ctor
    largeTextScreen(int letterWidth, int letterHeight); //ctor
    largeTextScreen(int letterWidth, int letterHeight, int terminalHeightPixels); //ctor
    ~largeTextScreen(); //dtor

    void addLargeText(std::string word, int xPos = 0, int yPos = 0); //add a word with the top left corner starting at xPos, yPos

    void centerTextHorizontally();
    void centerTextVertically();

    int findFirstNonEmptyRow();
    int findLastNonEmptyRow();

    void moveTextUp(int numRows); //moves all text up by one character
    void moveTextDown(int numRows); //moves all text down by one character

    void resetAllPixels(); //resets all pixels in the pixels grid to ' '

    void display(int rowsToPrint, bool printAll = false); //prints the grid of pixels in the terminal

    private:
    //variables
    int widthPixels; //the screen width in ascii characters
    int heightPixels; //the screen height in ascii characters
    int terminalHeight; //the height of the terminal in pixels
    char** pixels; //the grid of pixels to display
    int spaceWidth; //the number of ascii characters between letters in the same word
    int lineGapHeight; //the number of ascii characters between lines

    //Private helper functions
    void addLargeLetter(Letter letter, int xPos, int yPos); //helper function used to add one letter
};

#endif