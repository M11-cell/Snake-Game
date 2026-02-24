#pragma once

/*
    - Don’t hit a wall and don’t bite your own tail.
    - Crashing into a wall or your tail will end the game immediately.
    - 10 points will be added to the player's score for eating the fruit (#).
    - The player's total score is calculated based on the number of fruits the snake consumed.
    - The length of the snake will be increased after eating the fruits.
    - Use w, a, s, d to move the snake
*/

#include <string>


namespace board {

    class Board{

        private:    

            int WIDTH = 80;
            int HEIGHT = 20; 
            
            //Initialized snake head coordinates 
            int x,y;

            //Initialized fruit coordinates
            int fruitCoordX, fruitCoordY;

            // Initialized player score
            int playerscore; 

            // Initialized incremental varibakle to increase tail length 
            int snakeTailLength;

            // Set max size of the length of the tail (stores the coordinates). 
            int SnakeTailX[100], SnakeTailY[100]; 

            //Used for recording snakes direction along the map
            enum SnakeDirection{
                STOP = 0, LEFT, RIGHT, UP, DOWN
            }; 

            SnakeDirection sDir; 

            //Bool variable for checking game is over or not. 
            bool isGameOver;  

        public: 
            
            //the board constructor initializes all of the variables needed in order to start the game. 
            Board(){
                //ensures the head of the snake starts in the center of the map. 
                x = WIDTH/2;
                y = HEIGHT/2;

                //Setting the fruit to spawn in a random location
                fruitCoordX = rand() % WIDTH;
                fruitCoordY = rand() % HEIGHT; 

                //initializing player score
                playerscore = 0; 

                //Setting tail length to 0
                snakeTailLength = 0;

                //setting default direction to stopped
                sDir = STOP; 
                
                isGameOver = false; 
    

            }

            //The game render function creates the game board and also renders the game.
            // @param PlayerName will be used to keep track/ display the player name & their score
            void GameRender(std::string PlayerName); 
    };

} //namespace board