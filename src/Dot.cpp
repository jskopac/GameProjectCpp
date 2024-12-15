#include "Dot.h"
#include "Init.h"
#include <memory>
#include <string>
#include <SDL.h>

using namespace game_engine;


Dot::Dot(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/purple_dot.png"){
    prepareTexture(imagePath);
}

std::shared_ptr<Dot> Dot:: getInstance(int x, int y, int w, int h){
    return std::shared_ptr<Dot>(new Dot(x, y, w, h));
}

void Dot :: draw(){
    SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect());
}

bool Dot :: isColliding(const std::shared_ptr<Sprite> other) const{
    SDL_Rect thisRect = getRect();
    SDL_Rect otherRect = other -> getRect();
    return SDL_HasIntersection(&thisRect, &otherRect);   
}
