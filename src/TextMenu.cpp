#include "TextMenu.h"
#include <iostream>

using namespace game_engine;

TextMenu :: TextMenu(int x, int y, int w, int h) : text_rect{x,y,w,h}{
    if (TTF_Init() == -1) {
        std::cerr << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
        return;  
    }

    font = TTF_OpenFont("./resources/fonts/Geneva.ttf", 20);
    if (!font) {
        std::cerr << "Error loading the font: " << TTF_GetError() << std::endl;
        TTF_Quit();
        return; 
    }
}

TextMenu::~TextMenu(){
    if (font) {
        TTF_CloseFont(font);
    }

    TTF_Quit();
    
    if (text_texture) {
        SDL_DestroyTexture(text_texture);
    }
}

TextMenu* TextMenu :: createInstance(int x, int y, int w, int h){
    return new TextMenu(x, y, w, h);
}


void TextMenu :: setText(const std::string& new_text){
    if (text_texture) {
            SDL_DestroyTexture(text_texture);
    }

    title = new_text;
    SDL_Surface *text_surf = TTF_RenderText_Solid(font, title.c_str(), {255, 255, 255});
    if (!text_surf) {
        std::cerr << "Failed to render text surface: " << TTF_GetError() << std::endl;
        return;
    }

    text_texture = SDL_CreateTextureFromSurface(sys.get_ren(), text_surf);
    if (!text_texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(text_surf);
        return;
    }

    SDL_FreeSurface(text_surf);
    SDL_QueryTexture(text_texture, NULL, NULL, &text_rect.w, &text_rect.h); // Query the texture for its size
}

void TextMenu::render() {
    if (text_texture) {
        SDL_RenderCopy(sys.get_ren(), text_texture, nullptr, &text_rect);
    }
}

SDL_Rect& TextMenu :: getRect(){
    return text_rect;
}