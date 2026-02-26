#include <iostream>
#include <snake_game.hpp>


//Todo: Create top walls
//Todo: Create Middle walls w/ snake head & tail
//Todo: Create bottom walls
//Toso: display player score. 
void board::Board::GameRender(std::string PlayerName){

    for(int i = 0; i < WIDTH + 2; i++){
        std::cout<< "-"; 
    }
    std::cout<< std::endl; 
    

    for(int i = 0; i < HEIGHT; i ++){
        for(int j = 0; j < WIDTH; j++){

            //making da walls
            if(j == 0 && j == WIDTH){
                std::cout<<"|";
            }
            //creating snakes head
            if(i == y && j == x){
                std::cout<<"O";
            }
            
            //spawing in the food
            if(i == fruitCoordY && j == fruitCoordX){
                std::cout<<"#";
            }

            //creating the snakes body
            else{
                bool Tail = false;
                for(int f = 0; f < snakeTailLength; f++){
                    //i & j will be set to fruitCoordY & fruitCoordX, therefore, when SnakeTail == i (and j) that means that the snake ate a 
                    // fruit, thus the tail grows. If the snake didn't eat anything, then nothing happens. 
                    if(SnakeTailX[f] == j && SnakeTailY[f] == i){
                        std::cout<< "o";
                        Tail = true;
                    }
                    if(!Tail){
                        std::cout<<" "; 
                    }

                }
            }
        }
        std::cout<<std::endl;
    }

    //creating the bottom walls:
    for(int i = 0; i < WIDTH + 2; i++){
        std::cout<<"-"; 
    }
    std::cout<< std::endl;

    
    std::cout << PlayerName << "'s score = " << playerscore << std::endl; 

}







int main(){

    std::string Playername;
    std::cout << "Enter your name " << '\n';
    std::cin >> Playername;
    std::cout << "Your New name is: " << Playername << '\n';

    board::Board BoardInstance;
    while(!BoardInstance.isGameOver){
        BoardInstance.GameRender(Playername);
        // ...
    } 
}
