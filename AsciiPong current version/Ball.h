#ifndef BALL
#define BALL

struct Ball{
    Ball();
    Ball(int h, int w, char s);

    char symbol; //the ASCII character to be displayed as the ball
    int height; //y position at any given time
    int width; //x position at any given time
    bool horizontalDirection; //true = left, false = right
    bool verticalDirection; // true = up, false = down
    int horizontalSpeed;
    int verticalSpeed;

    double heightDouble; //more accurate height for calculation
    double widthDouble; //more accurate width for calculation
};

#endif