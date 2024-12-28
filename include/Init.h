#ifndef INIT_H
#define INIT_H
#include <SDL.h>
#include <SDL_ttf.h>

namespace game_engine {

    class Init {

        public:
            Init();
            ~Init();
            SDL_Renderer* get_ren() const;
            TTF_Font* get_font() const;

        private:
            SDL_Window* window;
            SDL_Renderer* ren;
            TTF_Font* font;	


    };


extern Init sys;

}
#endif
