#ifndef ALPHABET
#define ALPHABET

#include "Letter.h"

//Key for letters, symbols, and numbers
enum letterKey{
    A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14, P = 15,
    Q = 16, R = 17, S = 18, T = 19, U = 20, V = 21, W = 22, X = 23, Y = 24, Z = 25
};

enum symbolKey{
    SPACE = 0, PERIOD = 1, EXCLAMATION = 2, PLUS = 3, MINUS = 4, DIVISION = 5, EQUALS = 6, ASTERISK = 7, QUESTION = 8, COMMA = 9, APOSTROPHE = 10, QUOTATIONS = 11,
    OPEN_PARENTHESIS = 12, CLOSED_PARENTHESIS = 13, SEMICOLON = 14
};

enum numberKey{
    ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9
};

//Alphabet Struct
struct Alphabet{

    Alphabet(); //ctor

    void initializeLetters(char dot);
    void initializeNumbers(char dot);
    void initializeSymbols(char dot);

    //variables
    Letter Letters[26];
    Letter Symbols[20];
    Letter Numbers[10];
};

#endif