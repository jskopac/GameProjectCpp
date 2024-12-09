#include "Init.h"
#include <SDL.h>
#include <iostream>
#include "Pacman.h"
#include "GameEngine.h"

using namespace game;

int main(int argc, char ** argv){
    GameEngine sys;
    Pacman* test = Pacman::getInstance(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,100,100);
    sys.add(test);
    sys.run();

    return 0;  
}