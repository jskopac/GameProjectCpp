#ifndef INIT_H
#define INIT_H
#include <SDL.h>

namespace game_engine {

    class Init {

        public:
            Init();
            ~Init();
            SDL_Renderer* get_ren() const;

        private:
            SDL_Window* window;
            SDL_Renderer* ren;


    };


extern Init sys;

}
#endif
