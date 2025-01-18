#ifndef INIT_H
#define INIT_H
#include <SDL.h>
#include <iostream>

namespace game_engine {

    class Init {

        public:
            Init();
            ~Init();
            SDL_Renderer* get_ren() const;
            SDL_Window* get_win() const;

        private:
            SDL_Window* window;
            SDL_Renderer* ren;


    };


extern Init sys;

}
#endif
