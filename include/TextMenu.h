#ifndef TEXTMENU
#define TEXTMENU
#include "Init.h"
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

namespace game_engine {
    class TextMenu{

        public:
            static TextMenu* createInstance(int x, int y, int w, int h);
            void setText(const std::string& text);
            void render();
            SDL_Rect& getRect();

            ~TextMenu();


        protected:
            TextMenu(int x, int y, int w, int h);

        private:
            std::string title;
            TTF_Font* font;
            SDL_Texture* text_texture;
            SDL_Rect text_rect;

    };
}



#endif