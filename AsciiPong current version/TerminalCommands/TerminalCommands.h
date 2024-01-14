//terminalCommands.h
#ifndef TERMINAL_COMMANDS
#define TERMINAL_COMMANDS

//clears the screen (only works on linux/mac)
//use numRefreshes parameter to refresh terminal multiple times
void clearScreen(int numRefreshes = 1);

//gets the size in ascii characters of the user's terminal and returns in the width and height parameters by reference
void getTerminalSize(int& width, int& height);

//pauses the terminal for seconds seconds
void wait(double seconds);

//detects if the keyboard has been hit by the user
bool keyboardHit();

//returns what char was pressed on the keyboard
char detectKeyboardInput(int FPS);

//function to get a keyboard input with no buffer
char getImmediateInput();

#endif