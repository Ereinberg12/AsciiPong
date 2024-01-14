//Ball.cpp
#include "Ball.h"
#include <cstdlib>
#include <algorithm>

Ball::Ball(){

}

Ball::Ball(int h, int w, char s){
    symbol = s;
    height = h + 2; //add 2 to height to center on screen with top text
    heightDouble = h + 2; //add 2 to height to center on screen with top text
    width = w;
    widthDouble = w;

    //choose a random starting direction (left or right)
    int randInt = rand() % 2;
    if(randInt == 0){horizontalDirection = true;}
    else{horizontalDirection = false;}

    verticalDirection = true; //ball starts moving up (not relevant since v0 = 0)
    //set the initial speed values
    horizontalSpeed = 30; //default value, will be changed depending on frame width
    verticalSpeed = 0;
}