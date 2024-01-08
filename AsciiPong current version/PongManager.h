#ifndef PONG_MANAGER
#define PONG_MANAGER

#include "Ball.h"

struct PongManager{
        //FUNCTION PROTOTYPES
        PongManager(int h, int w, int paddleSize); //ctor
        ~PongManager(); //dtor

        //prints the grid in height x width resolution
        void printGrid(int aiParameter);

        //functions to update paddle locations
        void updateP1(bool up); //if up is true, move upwards
        void updateP2(bool up); 

        //functions for when the ball bounces
        void reflectRight();
        void reflectLeft();
        void reflectBottom();
        void reflectTop();  

        //functions to check if ball collides with paddles
        bool checkForCollisionWithPaddles();
        bool checkForCollisionWithP1();
        bool checkForCollisionWithP2();

        //function to check if ball collides with the top or bottom of the frame
        bool checkForCollisionWithTopOrBottom();

        //move the ball to its location in the next frame
        void moveBall(int FPS);

        int checkForWinner(); //returns 0 if no winner, 1 if P1 winds, and 2 if P2 wins

        void reset(); //resets the screen. called after a player scores a point

        //functions for the ai system for 0 and 1 player games
        void aiMove(int player, int difficulty1, int difficulty2);
        void aiPredictHitLocation(int player, int difficulty1, int difficulty2);

        //adds the paddles to the grid
        void addPaddles();
        

        //VARIABLES
        int height; //frame height
        int width; //frame width
        int p1Pos; //player 1 paddle vertical position
        int p2Pos; //player 2 paddle vertical position
        char** grid; //the grid of characters to use as an image
        Ball ball;
        bool winner; //winner flag to determine when someone has won
        int p1Score; //player 1's score
        int p2Score; //player 2's score
        int paddleSize; //the height of the paddles
};

#endif