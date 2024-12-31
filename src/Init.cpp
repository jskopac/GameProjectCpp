#include "Init.h"


namespace game_engine{

    Init::Init(){

        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 650, SDL_WINDOW_SHOWN);
        ren = SDL_CreateRenderer(window, -1, 0);
    }


    Init::~Init(){
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(ren);
        SDL_Quit();

    }

    SDL_Renderer* Init :: get_ren() const {
        return ren;
    }

    SDL_Window* Init :: get_win() const{
        return window;
    }

    Init sys;




}