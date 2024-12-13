#include "Init.h"
#include "Pacman.h"
#include "Dot.h"
#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <memory>


using namespace game_engine;

int main(int argc, char ** argv){
    GameEngine ses;
    // do we have to create using make_shared?
    std::shared_ptr<Pacman> test = Pacman::getInstance(100,100,32,32);
    std::shared_ptr<Dot> test1 = Dot::getInstance(100,100,10,10);
    ses.add(test);
    ses.add(test1);
    ses.run();

    return 0;  
}