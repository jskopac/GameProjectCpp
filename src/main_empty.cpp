#include "Init.h"
#include <SDL.h>
#include <iostream>
#include "Pacman.h"
#include "GameEngine.h"

using namespace game;

int main(int argc, char ** argv){
    GameEngine ses;
    Pacman* test = new Pacman(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,100,100);
    ses.add(test);
    ses.run();

    return 0;  
}