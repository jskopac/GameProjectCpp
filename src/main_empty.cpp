#include "Init.h"
#include "Wall.h"
#include "Pacman.h"
#include "Dot.h"
#include "Ghost.h"
#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <memory>
#include <vector>


using namespace game_engine;

int main(int argc, char ** argv){


    GameEngine ses;
    //create game board with walls -> dots should be on the non walls x and y.
    for (int h = 0; h < 600; h += 30) {
        for (int w = 0; w < 800; w += 30) {
            std::shared_ptr<Dot> d = Dot::createInstance(w, h, 10, 10);
            ses.add(d);

            if (h == 0 || h == 570 || w == 0 || w > 770) { // Top, bottom, left, right
                std::shared_ptr<Wall> t = Wall::createInstance(w, h, 30, 30);
                ses.add(t);
            }
        }
    }
    //create sprites
    std::shared_ptr<Pacman> pac = Pacman::createInstance(100,100,32,32);
    std::shared_ptr<Ghost> ghost1 = Ghost::createInstance(140,0, 32, 32);
    std::shared_ptr<Ghost> ghost2 = Ghost::createInstance(300,0, 32, 32);
    std::shared_ptr<Ghost> ghost3 = Ghost::createInstance(500,300, 32, 32);
    std::shared_ptr<Ghost> ghost4 = Ghost::createInstance(700,200, 32, 32);
    std::shared_ptr<Ghost> ghost5 = Ghost::createInstance(800,500, 32, 32);
    std::shared_ptr<Ghost> ghost6 = Ghost::createInstance(600,600, 32, 32);
    std::shared_ptr<Ghost> ghost7 = Ghost::createInstance(160,500, 32, 32);
    std::shared_ptr<Ghost> ghost8 = Ghost::createInstance(200,600, 32, 32);


    //add sprites to session. 
    ses.add(pac);
    ses.add(ghost1);
    ses.add(ghost2);
    ses.add(ghost3);
    ses.add(ghost4);
    ses.add(ghost5);
    ses.add(ghost6);
    ses.add(ghost7);
    ses.add(ghost8);

    //run
    ses.run();

    return 0;  
}