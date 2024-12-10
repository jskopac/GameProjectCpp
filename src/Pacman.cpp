#include "Pacman.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Init.h"
#include "Sprite.h"
#include <iostream>

namespace game{

    Pacman* Pacman::getInstance(int x, int y, int w, int h){
        return new Pacman(x,y,w,h);
    }        
   /*  void Pacman::keyDown(const SDL_Event& event){
        switch(event.key.keysym.sym){
            case SDLK_RIGHT: getRect().x++; break;
            case SDLK_LEFT: getRect().x--; break;
            case SDLK_DOWN: getRect().y++; break;
            case SDLK_UP: getRect().y--; break;
        }
    }

    void Pacman::keyUp(const SDL_Event&){

    } */

    void Pacman :: moveRight(){
        getRect().x++;
    }



    void Pacman::draw() {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect()); 
    }

    Pacman::Pacman(int x, int y, int w, int h) : Sprite(x,y,w,h){
        string imagePath = "./resources/images/pac_right.png";
        SDL_Surface* surf = IMG_Load(imagePath.c_str());

        if (surf == NULL) {
            std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        }

        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        if (texture == NULL) {
            std::cerr << "Failed to load texture: " << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface(surf);
    }

}