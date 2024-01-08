//Pong.cpp
#include "PongManager.h"
#include <iostream>
#include <climits>
#include <cmath>

PongManager::PongManager(int h, int w, int paddleSize){
    //set height and width
    height = h;
    width = w;

    //set the initial position of P1 and P2's paddles
    p1Pos = h / 2;
    p2Pos = p1Pos;
    //initialize the ball
    ball = Ball(height / 2, width / 2, 'o');

    //Allocate memory
    grid = new char*[height];

    //Allocate memory for each row
    for(int i = 0; i < height; ++i){
        grid[i] = new char[width];

        //Initialize each character to ' '
        for(int j = 0; j < width; ++j){
            grid[i][j] = ' ';
        }
    }

    //set the paddleSize
    this -> paddleSize = paddleSize;
    //add the player paddles
    addPaddles();

    //add the ball
    grid[ball.height][ball.width] = ball.symbol;

    //set the winner to false
    winner = false;
    
    //set the scores to 0
    p1Score = 0;
    p2Score = 0;
}

PongManager::~PongManager(){
    //Delete each row
    for(int i = 0; i < height; i++){
        delete[] grid[i];
    }

    //Delete the array of pointers
    delete[] grid;
}

void PongManager::printGrid(int aiParameter){
    //print the header
    for (int i = 0; i < (width - 28)/2; ++i){
        std::cout << "~";
    }
    std::cout << "ASCII PONG BY ETHAN REINBERG";
    for (int i = (width - 28)/2; i < width - 28; ++i){
        std::cout << "~";
    }
    std::cout << "\n";

    //print player1's score
    if(!(aiParameter == 2)){
        for (int i = 0; i < (width - 16)/2; ++i){
            std::cout << " ";
        }
        std::cout << "Player 1 Score: " << p1Score;
    }
    else{//Print AI1's score
        for (int i = 0; i < (width - 12)/2; ++i){
            std::cout << " ";
        }
        std::cout << "AI 1 Score: " << p1Score;
    }
    std::cout << "\n";

    //print player2's score 
    if(aiParameter == 0){
        for (int i = 0; i < (width - 16)/2; ++i){
            std::cout << " ";
        }
        std::cout << "Player 2 Score: " << p2Score;
    }//print AI's score 
    else if (aiParameter == 1){
        for (int i = 0; i < (width - 10)/2; ++i){
            std::cout << " ";
        }
        std::cout << "AI Score: " << p2Score;
    }//print AI2's score 
    else{
        for (int i = 0; i < (width - 12)/2; ++i){
            std::cout << " ";
        }
        std::cout << "AI 2 Score: " << p2Score;
    }
    std::cout << "\n";

    //print the grid
    for(int i = 0; i < width; ++i){
        std::cout << "-";
    }
    std::cout << "\n";

    for (int i = 0; i < height; ++i){
        std::cout << grid[i] << "\n";
    }

    for(int i = 0; i < width; ++i){
        std::cout << "-";
    }
    std::cout << "\n";

    std::cout << std::flush; //clear the buffer so "\n" can be used instead of std::endl
}

void PongManager::updateP1(bool up){
    //if the paddle cannot be moved, return
    if(up && p1Pos == 0){return;}
    else if(!up && p1Pos == height - paddleSize){return;}

    //move paddle up
    if(up){
        grid[p1Pos - 1][0] = '|';
        grid[p1Pos + paddleSize - 1][0] = ' ';
        --p1Pos;
    }

    //move paddle down
    if(!up){
        grid[p1Pos + paddleSize][0] = '|';
        grid[p1Pos][0] = ' ';
        ++p1Pos;
    }
    return;
}

void PongManager::updateP2(bool up){
    //if the paddle cannot be moved return
    if(up && p2Pos == 0){return;}
    else if(!up && p2Pos == height - paddleSize){return;}

    //move paddle up
    if(up){
        grid[p2Pos - 1][width - 1] = '|';
        grid[p2Pos + paddleSize - 1][width - 1] = ' ';
        --p2Pos;
    }

    //move paddle down
    if(!up){
        grid[p2Pos + paddleSize][width - 1] = '|';
        grid[p2Pos][width - 1] = ' ';
        ++p2Pos;
    }
    return;
}

void PongManager::reflectLeft(){
    //adjust the horizontal direction
    ball.horizontalDirection = !ball.horizontalDirection;
    //apply change in vertical speed
    //generate a random int between 0 and 15
    int intRand = rand() % 16;
    //generate a number either 1 or -1
    int temp = rand();
    int oneOrNegOne;
    if(temp % 2 == 0){oneOrNegOne = 1;}
    else{oneOrNegOne = -1;}
    //adjust the vertical speed
    ball.verticalSpeed = ball.verticalSpeed + intRand*oneOrNegOne;
}

void PongManager::reflectRight(){
    //adjust the horizontal direction
    ball.horizontalDirection = !ball.horizontalDirection;
    //apply change in vertical speed
    //generate a random int between 0 and 15
    int intRand = rand() % 16;
    //generate a number either 1 or -1
    int temp = rand();
    int oneOrNegOne;
    if(temp % 2 == 0){oneOrNegOne = 1;}
    else{oneOrNegOne = -1;}
    //adjust the vertical speed
    ball.verticalSpeed = ball.verticalSpeed + intRand*oneOrNegOne;
}

void PongManager::reflectTop(){
    //adjust the vertical direction
    ball.verticalDirection = !ball.verticalDirection;
}

void PongManager::reflectBottom(){
    //adjust the vertical direction
    ball.verticalDirection = !ball.verticalDirection;
}

bool PongManager::checkForCollisionWithPaddles(){
    if(checkForCollisionWithP1()){
        addPaddles(); //add paddles to solve visual glitch with ball going into paddle
        return true;
    }
    else if(checkForCollisionWithP2()){
        addPaddles(); //add paddles to solve visual glitch with ball going into paddle
        return true;
    }

    return false;
}

bool PongManager::checkForCollisionWithP1(){
    //check if the ball is at a place where it can collide
    if (ball.width != 0 && ball.width != 1){
        return false;
    }

    for(int i = 0; i < paddleSize; ++i){
        if ((ball.width == 0 && p1Pos + i  == ball.height) || (ball.width == 1 && p1Pos + i  == ball.height)){
            return true;
        }
    }

    //no collision with paddle 1
    return false;

}
bool PongManager::checkForCollisionWithP2(){
    //check if the ball is at a place where it can collide
    if (ball.width != width - 1 && ball.width != width - 2){
        return false;
    }

    for(int i = 0; i < paddleSize; ++i){
        if ((ball.width == width - 1 && p2Pos + i  == ball.height) || (ball.width == width - 2 && p2Pos + i  == ball.height)){
            return true;
        }
    }

    //no collision with paddle 2
    return false;
}

bool PongManager::checkForCollisionWithTopOrBottom(){
    if(ball.height == 0 || ball.height == height - 1){
        return true;
    }
    return false;
}

void PongManager::moveBall(int FPS){
    //remove the old ball
    if(!(ball.width == 0 && checkForCollisionWithP1()) && !(ball.width == width - 1 && checkForCollisionWithP2())){//ensure the ball isn't where the paddle is
        if(ball.height >= 0 && ball.height <= height - 1){//account for out of bounds errors when ball changes direction
            grid[ball.height][ball.width] = ' ';
        }
        else{//avoid lingering ball when ball.height is past bounds
            if(ball.height < 0){grid[0][ball.width] = ' ';}
            else if(ball.height > height - 1){grid[height - 1][ball.width] = ' ';}
        }  
    }

    //calculate the number of indices to move
    double numIndicesHorizontalDouble = ball.horizontalSpeed / 10.0; //Default: 20.0

    double numIndicesVerticalDouble = ball.verticalSpeed / 30.0; //Default: 60.0

    //calculate where to place the ball
    if(ball.verticalDirection){//if the ball is moving up
        ball.heightDouble -= numIndicesVerticalDouble;
        ball.height = std::max(0, (int) round(ball.heightDouble));
    }
    else{//if the ball is moving down
        ball.heightDouble += numIndicesVerticalDouble;
        ball.height = std::min(height - 1, (int) round(ball.heightDouble));
    }

    if(ball.horizontalDirection){//if ball is moving left
        ball.widthDouble -= numIndicesHorizontalDouble;
        ball.width = std::max(0, (int)round(ball.widthDouble));
    }
    else{//if the ball is moving right
        ball.widthDouble += numIndicesHorizontalDouble;
        ball.width = std::min(width - 1, (int) round(ball.widthDouble));
    }

    //reflect if necessary
    if(ball.width <= 1 && checkForCollisionWithP1()){//if the ball reflects off the left side
        reflectLeft();
    }
    else if(ball.width >= width - 2 && checkForCollisionWithP2()){//if the ball reflects off of the right side
        reflectRight();
    }

    if(ball.height >= height - 1){//if the ball reflects off the bottom
        reflectBottom();
    }
    else if(ball.height <= 0){//if the ball reflects off the top
        reflectTop();
    }

    //add the new ball
    if(ball.height > height - 1){grid[height - 1][ball.width] = ball.symbol;}
    else if(ball.height < 0){grid[0][ball.width] = ball.symbol;}
    else{grid[ball.height][ball.width] = ball.symbol;}
}

int PongManager::checkForWinner(){
    if(ball.width != 0 && ball.width != width - 1){return 0;}
    else if(ball.width == width - 1 && !checkForCollisionWithPaddles()){return 1;}
    else if(ball.width == 0 && !checkForCollisionWithPaddles()){return 2;}
    return 0;
}

void PongManager::reset(){
    //set the initial position of P1 and P2's paddles
    p1Pos = height / 2;
    p2Pos = p1Pos;
    //initialize the ball
    int prevBallSpeed = ball.horizontalSpeed;
    ball = Ball(height / 2, width / 2, ball.symbol);
    ball.horizontalSpeed = prevBallSpeed;

    //reset the grid
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            grid[i][j] = ' ';
        }
    }

    //add the player paddles
    addPaddles();

    //add the ball
    grid[ball.height][ball.width] = ball.symbol;
}

void PongManager::aiMove(int player, int difficulty1, int difficulty2){
    if(player == 2){
        //if the ball is moving towards P1, move P2 towards the center
        if(ball.horizontalDirection == true){
            if(p2Pos == (height / 2) - (paddleSize / 2)){
                return;
            }
            else if(p2Pos < (height / 2) - (paddleSize / 2)){
                updateP2(false);
                return;
            }
            else{
                updateP2(true);
                return;
            }
        }
        else{//otherwise predict where the ball is going to go and move to there
            aiPredictHitLocation(2, difficulty1, difficulty2);
        }
    }
    else{
        //if the ball is moving towards P2, move P1 towards the center
        if(ball.horizontalDirection == false){
            if(p1Pos == (height / 2) - (paddleSize / 2)){
                return;
            }
            else if(p1Pos < (height / 2) - (paddleSize / 2)){
                updateP1(false);
                return;
            }
            else{
                updateP1(true);
                return;
            }
        }
        else{//otherwise predict where the ball is going to go and move to there
            aiPredictHitLocation(1, difficulty1, difficulty2);
        }

    }

}

void PongManager::aiPredictHitLocation(int player, int difficulty1, int difficulty2){
    //change vertical ball speed modifier to make AI easier/harder
    double verticalBallSpeedModifier1 = 3*ball.horizontalSpeed - (9-difficulty1)*floor(3*ball.horizontalSpeed/9); 
    double verticalBallSpeedModifier2 = 3*ball.horizontalSpeed - (9-difficulty2)*floor(3*ball.horizontalSpeed/9);

    if(player == 2){//if we are moving player 2's paddle
        double location;
        //if the ball is moving up
        if(ball.verticalDirection == true){
            location = ball.heightDouble - (ball.verticalSpeed / verticalBallSpeedModifier2)*(width - ball.widthDouble);
        }
        else{//if the ball is moving down
            location = ball.heightDouble + (ball.verticalSpeed / verticalBallSpeedModifier2)*(width - ball.widthDouble);
        }
        int prediction = (int) location; //cast prediction to integer

        if(prediction < 0){prediction = -prediction;} //account for prediction going past bounds
        else if(prediction > height){prediction = ball.height - (prediction - ball.height);} //account for prediction going past bounds

        //use p2Pos + (paddleSize / 2) for center of paddle since p2Pos is the first of  indices for the paddle
        if(p2Pos + (paddleSize / 2) == prediction){//if the paddle is already at the predicted location
            return;
        }

        else if(p2Pos + (paddleSize / 2)  < prediction){//if the paddle is above the predicted location
            updateP2(false);
            return;
        }
        else{//if the paddle is below the predicted location
            updateP2(true);
            return;
        }
    }
    else{//if we are moving player 1's paddle
        double location;
        //if the ball is moving up
        if(ball.verticalDirection == true){
            location = ball.heightDouble - (ball.verticalSpeed / verticalBallSpeedModifier1)*(ball.widthDouble);
        }
        else{//if the ball is moving down
            location = ball.heightDouble + (ball.verticalSpeed / verticalBallSpeedModifier1)*(ball.widthDouble);
        }
        int prediction = (int) location; //cast prediction to integer

        if(prediction < 0){prediction = -prediction;} //account for prediction going past bounds
        else if(prediction > height){prediction = ball.height - (prediction - ball.height);} //account for prediction going past bounds


        //use p1Pos + (paddleSize / 2) for center of paddle since p1Pos is the first of paddleSize indices for the paddle
        if(p1Pos + (paddleSize / 2) == prediction){//if the paddle is already at the predicted location
            return;
        }

        else if(p1Pos + (paddleSize / 2)  < prediction){//if the paddle is above the predicted location
            updateP1(false);
            return;
        }
        else{//if the paddle is below the predicted location
            updateP1(true);
            return;
        }

    }
    
}

//add the paddles to the grid
void PongManager::addPaddles(){
    for(int i = 0; i < paddleSize; ++i){
        grid[p1Pos + i][0] = '|';
        grid[p2Pos + i][width - 1] = '|';
    }
}