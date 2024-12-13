#include "Init.h"
#include "Pacman.h"
#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <memory>


using namespace game_engine;

int main(int argc, char ** argv){
    GameEngine ses;
    // do we have to create using make_shared?
    std::shared_ptr<Pacman> test = Pacman::getInstance(100,100,32,32);
    ses.add(test);
    ses.run();

    return 0;  
}