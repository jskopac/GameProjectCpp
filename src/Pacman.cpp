#include "Pacman.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Init.h"
#include "Sprite.h"

namespace game{

    Pacman* Pacman::getInstance(int x, int y, int w, int h){
        return new Pacman(x,y,w,h);
    }        
    void Pacman::keyDown(const SDL_Event&){

    }
    void Pacman::keyUp(const SDL_Event&){

    }
    void Pacman::draw() const{

    }

    Pacman::Pacman(int x, int y, int w, int h) : Sprite(x,y,w,h){
        string imagePath = "./resources/images/pac-right.png";
        SDL_Surface* surf = IMG_Load(imagePath.c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect()); 
    }

}