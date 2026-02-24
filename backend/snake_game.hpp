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
            enum class SnakeDirection{
                STOP = 0, LEFT, RIGHT, UP, DOWN
            } SnakeDir;

            //Bool variable for checking game is over or not. 
            bool isGameOver();  

        public: 
            
            Board(){

            }


            void GameStart();

            void GameRender(std::string PlayerName); 
    };

} //namespace board