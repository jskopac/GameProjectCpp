#include "Init.h"


namespace game_engine{

    Init::Init(){
        //Initializes SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
            std::cerr << "Error with SDL_Init: " << SDL_GetError() << std::endl;
        }

        //Creating the window
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 650, SDL_WINDOW_SHOWN);
        if (!window) {
            SDL_Quit(); 
            std::cerr << "Error creating the SDL window: " << SDL_GetError() << std::endl;
            return;
        }

        //Creating the renderer
        ren = SDL_CreateRenderer(window, -1, 0);
        if (!ren) {
            std::cerr << "Error creating the SDL renderer: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window); 
            SDL_Quit();
            return;
        }
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