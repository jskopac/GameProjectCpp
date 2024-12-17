#include "Init.h"
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
    // do we have to create using make_shared?
    std::shared_ptr<Pacman> test = Pacman::getInstance(100,100,32,32);
    std::shared_ptr<Dot> test1 = Dot::getInstance(200,200,10,10);
    std::shared_ptr<Ghost> test2 = Ghost::getInstance(300,300, 32, 32);
    ses.add(test);
    ses.add(test1);
    ses.add(test2);
    ses.run();

    return 0;  
}