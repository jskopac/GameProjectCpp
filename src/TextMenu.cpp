#include "TextMenu.h"

using namespace game_engine;

TextMenu :: TextMenu(int x, int y, int w, int h) : text_rect{x,y,w,h}{
    font = TTF_OpenFont("/System/Library/Fonts/Geneva.ttf", 36);
}



TextMenu* TextMenu :: createInstance(int x, int y, int w, int h){
    return new TextMenu(x, y, w, h);
}


void TextMenu :: setText(const std::string& new_text){

    if (title != new_text){
        title = new_text;
        SDL_Surface *surf = TTF_RenderText_Solid(font, title.c_str(), {255, 255, 255});
        SDL_Texture *text_texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
        SDL_QueryTexture(text_texture, NULL, NULL, &text_rect.w, &text_rect.h); // Query the texture for its size
        SDL_RenderCopy(sys.get_ren(), text_texture, nullptr, &text_rect);
    

    }

}


TextMenu::~TextMenu(){
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyTexture(text_texture);
}