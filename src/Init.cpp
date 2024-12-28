#include "Init.h"
#include <SDL.h>

namespace game_engine{

    Init::Init(){

        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
        ren = SDL_CreateRenderer(window, -1, 0);
        TTF_Init();
		font = TTF_OpenFont("/System/Library/Fonts/Geneva.ttf", 36);
    }


    Init::~Init(){
        TTF_CloseFont(font);
		TTF_Quit();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(ren);
        SDL_Quit();

    }

    SDL_Renderer* Init :: get_ren() const {
        return ren;
    }

    TTF_Font* Init :: get_font() const{
		return font;
	}


    Init sys;




}