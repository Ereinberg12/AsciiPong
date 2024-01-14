#ifndef PLAYGAME
#define PLAYGAME

#include "PongManager.h"
#include "../TerminalCommands/TerminalCommands.h"

//PROTOTYPES
void playGame(int h, int w, int winScore, int fps, int paddleSize); //runs the game (this function gets called in main)

bool checkForWinner(PongManager& pongGrid, int winningScore, int aiParameter, char killKey, char pauseKey, bool paused); //checks if a player has won

bool askPlayAgain(int h, int w); //prompts the user if they want to play again after a game completes

int askAiDifficulty(int h, int w, int player, int aiParameter); //asks the user for the AI difficulty (player is which side is being set and aiParameter is the number of AI players)

#endif