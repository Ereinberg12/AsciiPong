//Ball.cpp
#include "Ball.h"
#include <cstdlib>
#include <algorithm>

Ball::Ball(){

}

Ball::Ball(int h, int w, char s){
    symbol = s;
    height = h + 2;
    heightDouble = h + 2;
    width = w;
    widthDouble = w;

    //choose a random starting direction (left or right)
    int randInt = rand() % 2;
    if(randInt == 0){horizontalDirection = true;}
    else{horizontalDirection = false;}

    verticalDirection = true; //ball starts moving up (not relevant since v0 = 0)
    //set the initial speed values
    horizontalSpeed = 40;
    verticalSpeed = 0;
}