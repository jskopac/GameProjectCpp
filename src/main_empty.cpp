#include "Init.h"
#include "Wall.h"
#include "Pacman.h"
#include "Dot.h"
#include "Ghost.h"
#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <memory>


using namespace game_engine;

int main(int argc, char ** argv){


    GameEngine ses;
    //create game board with walls -> dots should be on the non walls x and y.
    for (int h = 0; h < 800; h+=30){
        for (int w = 0; w < 600; w+=30){
            std::shared_ptr<Dot> d = Dot::getInstance(h,w,10,10);
            ses.add(d);
            if(h == 0 || h == 770 || w == 0 || w == 570){
                std::shared_ptr<Wall> t= Wall::getInstance(h,w,30,30);
                ses.add(t);
            }
        }
    }
    


    //create sprites
    // do we have to create using make_shared?
    std::shared_ptr<Pacman> test = Pacman::getInstance(100,100,32,32);
    std::shared_ptr<Ghost> test2 = Ghost::getInstance(300,0, 32, 32);
    std::shared_ptr<Wall> test3 = Wall::getInstance(50,50,20,20);

    //add sprites to session. 
    ses.add(test);
    ses.add(test2);

    //run
    ses.run();

    return 0;  
}