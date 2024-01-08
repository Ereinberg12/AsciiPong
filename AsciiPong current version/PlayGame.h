#ifndef PLAYGAME
#define PLAYGAME

#include "PongManager.h"

//PROTOTYPES
void playGame(int h, int w, int winScore, int fps, int paddleSize); //runs the game (this function gets called in main)

char detectKeyboardInput(int FPS); //accepts the frames per second

bool checkForWinner(PongManager& pongGrid, int winningScore, int aiParameter); //checks if a player has won

void printStartPage(int h, int w, int winningScore); //prints start page

void printP1Wins(int h, int w); //functions to call to print winner

void printP2Wins(int h, int w); //functions to call to print winner

void printAIWins(int h, int w); //functions to call to print winner

void printAI1Wins(int h, int w); //functions to call to print winner

void printAI2Wins(int h, int w); //functions to call to print winner

void printEndScreen(int h, int w); //prints the end screen

void clearScreen(int numRefreshes = 1); //clears the screen

bool askPlayAgain(int h, int w); //prompts the user if they want to play again after a game completes

int askAiDifficulty(int h, int w, int player, int aiParameter); //asks the user for the AI difficulty (player is which side is being set and aiParameter is the number of AI players)

bool keyboardHit(); //determine if the keyboard was hit and return true if so, false if not

char getImmediateInput(); //used to get input from the user without them hitting enter

#endif