#include "Init.h"
#include <SDL.h>
#include <iostream>
#include "Pacman.h"
#include "GameEngine.h"

using namespace game;

int main(int argc, char ** argv){
    GameEngine ses;
    Pacman* test = Pacman::getInstance(100,100,100,100);
    ses.add(test);
    ses.run();

    return 0;  
}