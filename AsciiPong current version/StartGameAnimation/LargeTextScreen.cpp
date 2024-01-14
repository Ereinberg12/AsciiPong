//LargeTextScreen.cpp
#include "LargeTextScreen.h"
#include "Alphabet.h"
#include <iostream>
#include <cstring> //used in moveTextUp and moveTextDown

enum pixelSize{
    widthOfIndividualPixel = 13,
    heightOfIndividualPixel = 7
};

enum textSpacing{
    LINE_GAP_HEIGHT = 2,
    SPACE_WIDTH = 3
};

//function to test printing
void testPrintingToLargeTextScreen();

//largeTextScreen class implementation starts here
//ctor
largeTextScreen::largeTextScreen(int letterWidth, int letterHeight){
    widthPixels = letterWidth;
    heightPixels = letterHeight;
    spaceWidth = SPACE_WIDTH;
    lineGapHeight = LINE_GAP_HEIGHT;
    terminalHeight = heightPixels;


    //allocate memory for pixels
    pixels = new char*[heightPixels];
    for(int i = 0; i < heightPixels; ++i){
        pixels[i] = new char[widthPixels];
    }

    //initialize pixels so all pixels are filled with a space
    for(int i = 0; i < heightPixels; ++i){
        for(int j = 0; j < widthPixels; ++j){
            pixels[i][j] = ' ';
        }
    }
}

largeTextScreen::largeTextScreen(int letterWidth, int letterHeight, int terminalHeightPixels){
    widthPixels = letterWidth;
    heightPixels = letterHeight;
    spaceWidth = SPACE_WIDTH;
    lineGapHeight = LINE_GAP_HEIGHT;
    terminalHeight = terminalHeightPixels;

    //allocate memory for pixels
    pixels = new char*[heightPixels];
    for(int i = 0; i < heightPixels; ++i){
        pixels[i] = new char[widthPixels];
    }

    //initialize pixels so all pixels are filled with a space
    for(int i = 0; i < heightPixels; ++i){
        for(int j = 0; j < widthPixels; ++j){
            pixels[i][j] = ' ';
        }
    }
}

//dtor
largeTextScreen::~largeTextScreen(){
    for(int i = 0; i < heightPixels; ++i){
        delete[] pixels[i];
    }
    delete[] pixels;
}

void largeTextScreen::addLargeText(std::string inputString, int xPos, int yPos){
    Alphabet largeLetters;

    std::vector<std::string> words = parseStringIntoWords(inputString);


    for(int i = 0; i < (int) words.size(); ++i){
        std::string word = words[i];
        if((int) (xPos + (word.length() + 1) * widthOfIndividualPixel + word.length()*spaceWidth) > widthPixels - 1){//move down to the next line if the current word doesn't fit. use word.length() + 1 to account for extra space char needed for word
            xPos = 0;
            yPos += heightOfIndividualPixel + lineGapHeight;
        }
        else if(xPos != 0){//if the current word fits and the cursor is not at the start of the line, add a space
            xPos += widthOfIndividualPixel + spaceWidth;
        }

        for(int j = 0; j < (int) word.length(); ++j){
            char currentChar = word[j]; //get the character at the i'th position in the word
            
            if(currentChar != ' '){//if the current char is not a space

                int alphabetIndex;
                Letter currentLetter; //initialize memory for a letter

                if((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z')){//if the current character is a letter
                    currentChar = toupper(currentChar); //make sure currentChar is uppercase
                    alphabetIndex = currentChar - 'A';
                    currentLetter = largeLetters.Letters[alphabetIndex]; //create a 7x13 large letter of the current character
                }
                else if(currentChar >= '0' && currentChar <= '9'){//if the character is a number
                    alphabetIndex = currentChar - '0'; //convert char to int
                    currentLetter = largeLetters.Numbers[alphabetIndex];
                }
                else{//if the currentChar is a symbol
                    if(currentChar == '.'){alphabetIndex = PERIOD;}
                    else if(currentChar == '!'){alphabetIndex = EXCLAMATION;}
                    else if(currentChar == '+'){alphabetIndex = PLUS;}
                    else if(currentChar == '-'){alphabetIndex = MINUS;}
                    else if(currentChar == '/'){alphabetIndex = DIVISION;}
                    else if(currentChar == '='){alphabetIndex = EQUALS;}
                    else if(currentChar == '*'){alphabetIndex = ASTERISK;}
                    else if(currentChar == '?'){alphabetIndex = QUESTION;}
                    else if(currentChar == ','){alphabetIndex = COMMA;}
                    else if(currentChar == '\''){alphabetIndex = APOSTROPHE;}
                    else if(currentChar == '"'){alphabetIndex = QUOTATIONS;}
                    else if(currentChar == '('){alphabetIndex = OPEN_PARENTHESIS;}
                    else if(currentChar == ')'){alphabetIndex = CLOSED_PARENTHESIS;}
                    else if(currentChar == ';'){alphabetIndex = SEMICOLON;}
                    currentLetter = largeLetters.Symbols[alphabetIndex];//set the current letter equal to the appropriate symbol
                }
                
                addLargeLetter(currentLetter, xPos, yPos); //add the currentLetter to the pixels grid
            }

            if(currentChar == ' ' && xPos <= widthOfIndividualPixel){//if a space is at the start of a line, ignore it
                continue;
            }

            xPos += widthOfIndividualPixel + spaceWidth; //update the xPosition

            if(widthPixels - xPos < widthOfIndividualPixel){//if the xPos will be off the edge of the screen
                xPos = 0;
                yPos += heightOfIndividualPixel + lineGapHeight;
            }
        }

    }

}

void largeTextScreen::addLargeLetter(Letter letter, int xPos, int yPos){
    for(int i = 0; i < heightOfIndividualPixel; ++i){
        for(int j = 0; j < widthOfIndividualPixel; ++j){
            pixels[i + yPos][j + xPos] = letter.pixels[i][j];
        }
    }
}

//print the screen
void largeTextScreen::display(int rowsToPrint, bool printAll){
    int rowsToIndexThrough = std::min(heightPixels, rowsToPrint);
    int heightOfBottomPixel = findLastNonEmptyRow(); //find the bottom pixel (used if the text has gone past the screen)
    bool textExtendsPastBottom = heightOfBottomPixel > terminalHeight; //true if the text goes beyond the terminal height
  
    for(int i = 0; i < rowsToIndexThrough; ++i){//loop through the number of rows to display
        for(int j = 0; j < widthPixels; ++j){//loop through entire i'th row
            if(!textExtendsPastBottom || printAll){//if the text does not extend off the bottom of the screen or we are printing everything
                std::cout << pixels[i][j];
            }
            else{//if the text does extend off the bottom of the screen
                int offSet = (heightOfBottomPixel + spaceWidth - terminalHeight);
                std::cout << pixels[i + offSet][j];
            }
        }
        if(heightPixels != rowsToIndexThrough - 1){//don't add a new line after the last row
            std::cout << '\n';
        }
    }
}

//centers the text on the screen
void largeTextScreen::centerTextHorizontally(){
    //find the height of the first occupied pixel
    int currentHeight = findFirstNonEmptyRow();
    int lineHeight = heightOfIndividualPixel + lineGapHeight;

    while(currentHeight < heightPixels){
        int farthestLeftPixel = widthPixels - 1;
        int farthestRightPixel = 0;
        for(int i = 0; i < lineHeight; ++i){//determine how far over to move the line

            //check bounds
            if(i + currentHeight > heightPixels - 1){
                break;
            }

            for (int j = 0; j < widthPixels; ++j){
                if(pixels[i + currentHeight][j] != ' '){//if there is a dot at the pixel location
                    if(farthestLeftPixel > j){//update farthestLeftPixel
                        farthestLeftPixel = j;
                    }
                    if (farthestRightPixel < j){//update farthestRightPixel
                        farthestRightPixel = j;
                    }
                }
            }
        }

        //move the pixels over
        int numPixelsToMove = ((widthPixels - farthestRightPixel) - farthestLeftPixel) / 2; //figure out how far to move
        if(numPixelsToMove < 0){//make numPixels to move always positive
            numPixelsToMove = -numPixelsToMove;
        }
        //figure out which direction to move pixels
        bool direction = (widthPixels - farthestRightPixel) > farthestLeftPixel; //true = right, false = left

        for(int i = 0; i < lineHeight; ++i){
            //check bounds
            if(i + currentHeight > heightPixels - 1){
                break;
            }

            std::string tempRow = pixels[i+currentHeight];
            std::string spacesToAdd;
            for(int j = 0; j < numPixelsToMove; ++j){
                spacesToAdd += ' ';
            }

            if(direction){//if text is being moved right
                tempRow = spacesToAdd + tempRow;
                tempRow = tempRow.substr(0,widthPixels);
            }
            else{//if test is being moved left
                tempRow = tempRow + spacesToAdd;
                tempRow = tempRow.substr(numPixelsToMove, widthPixels);
            }
            
            //assign the pixels in tempRow to the pixels grid
            for(int j = 0; j < widthPixels; ++j){
                pixels[i+currentHeight][j] = tempRow[j];
            }
        }

        //reset farthest left and right pixel
        farthestLeftPixel = widthPixels - 1;
        farthestRightPixel = 0;
        //update currentHeight
        currentHeight += lineHeight;
    }

}

int largeTextScreen::findFirstNonEmptyRow(){
    //find the height of the first occupied pixel
    int currentHeight = 0;
    bool pixelFound = false;

    for(int i = 0; i < heightPixels; ++i){
        if(pixelFound){//break once the first pixel is found
            break;
        }
        for(int j = 0; j < widthPixels; ++j){
            if(pixels[i][j] != ' '){
                currentHeight = i; 
                pixelFound = true;
                break;
            }
        }
    }

    return currentHeight;
}

int largeTextScreen::findLastNonEmptyRow(){
    int heightOfBottomPixel = 0;
    for(int i = 0; i < heightPixels; ++i){
        for(int j = 0; j < widthPixels; ++j){
            if(pixels[i][j] != ' ' && i > heightOfBottomPixel){
                heightOfBottomPixel = i;
            }
        }
    }//by the time the function reaches here the heights of the top and bottom pixel are known
    return heightOfBottomPixel;
}

void largeTextScreen::centerTextVertically(){
    //figure out the number of pixels to move text up/down
    int heightOfTopPixel = findFirstNonEmptyRow();
    //find the height of the bottom pixel
    int heightOfBottomPixel = findLastNonEmptyRow();

    int numPixelsToMove = (heightOfTopPixel - (terminalHeight - 1 - heightOfBottomPixel)) / 2;
    bool direction = heightOfTopPixel > terminalHeight - 1 - heightOfBottomPixel; //true = move up, false = move down
    if(direction){//move text up by numPixels
        moveTextUp(numPixelsToMove);
    }
    else{//move text down by numPixels
        numPixelsToMove = - numPixelsToMove;
        moveTextDown(numPixelsToMove);
    }
}

void largeTextScreen::moveTextUp(int numRows){
    //validate numRows
    if(numRows <= 0 || numRows >= heightPixels){
        return; // return if numRows is out of valid range
    }

    //move the rows up
    for(int i = 0; i < heightPixels - numRows; ++i){
        memcpy(pixels[i], pixels[i + numRows], widthPixels * sizeof(char));
    }

    //clear the bottom numRows rows
    for(int i = heightPixels - numRows; i < heightPixels; ++i){
        std::fill_n(pixels[i], widthPixels, ' ');
    }
}

void largeTextScreen::moveTextDown(int numRows){
    // Validate numRows
    if(numRows <= 0 || numRows >= heightPixels) {
        return; // Return if numRows is out of valid range
    }

    // Move the rows down in reverse order to avoid overwriting
    for(int i = heightPixels - 1; i >= numRows; --i){
        memcpy(pixels[i], pixels[i - numRows], widthPixels * sizeof(char));
    }

    // Clear the top numRows rows
    for(int i = 0; i < numRows; ++i){
        std::fill_n(pixels[i], widthPixels, ' ');
    }
}

void largeTextScreen::resetAllPixels(){
    for(int i = 0; i < heightPixels; ++i){
        for(int j = 0; j < widthPixels; ++j){
            pixels[i][j] = ' ';
        }
    }
}


//Function to test printing
void testPrintingToLargeTextScreen(){
    int height, width;
    getTerminalSize(width, height);
    height = height - 2; //account for line in terminal used to call
    largeTextScreen screen = largeTextScreen(width, height);

    clearScreen();

    screen.addLargeText("the quick brown fox jumps over the lazy dog! 0123456789. + "); //test all letters and symbols

    screen.display(height);
    wait(1);

    clearScreen();

    screen.centerTextHorizontally();
    screen.display(height);
    wait(1);

    screen.centerTextVertically();
    screen.display(height);

    //printLargeWordTest();
}
















