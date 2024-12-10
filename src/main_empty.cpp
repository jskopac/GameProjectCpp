#include "Init.h"
#include "Pacman.h"
#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <memory>


using namespace game;

int main(int argc, char ** argv){
    GameEngine ses;
    std::shared_ptr<Pacman> test = std::make_shared<Pacman>(100,100,32,32);
    ses.add(test);
    ses.run();

    return 0;  
}