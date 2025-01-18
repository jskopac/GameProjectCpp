#include "Init.h"
#include "Wall.h"
#include "Pacman.h"
#include "Dot.h"
#include "Ghost.h"
#include "GameEngine.h"
#include <SDL.h>
#include <memory>
#include <vector>


using namespace game_engine;

int main(int argc, char ** argv){

    GameEngine ses;

    //create game board with walls and dots
    int wall_height = 30, wall_width = 30;

    for (int y = 0; y < 600; y += 30) {
        for (int x = 0; x < 800; x += 30) {
            std::shared_ptr<Dot> d = Dot::createInstance(x, y, 10, 10);
            ses.add(d);

            if (y == 0 || y >= (600 - wall_height) || x == 0 || x >= (800 - wall_width)) { // left, right, top, bottom
                std::shared_ptr<Wall> t = Wall::createInstance(x, y, wall_height, wall_width);
                ses.add(t);
            }
        }
    }

    //create and add pacman to the sprites vector
    std::shared_ptr<Pacman> pac = Pacman::createInstance(70,70,32,32);
    ses.add(pac);

    //create ghosts and add them to the sprites vector
    for(int x = wall_width; x < (800-wall_width); x += 90){
        int y = rand() % 540 + wall_height;
        
        std::shared_ptr<Ghost> ghost = Ghost::createInstance(x, y, 32, 32);
        ses.add(ghost);
    }


    //run the game
    ses.run();

    return 0;  
}