#include "Dot.h"


using namespace game_engine;


Dot::Dot(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/purple_dot.png"){
    prepareTexture(imagePath);
}

std::shared_ptr<Dot> Dot:: createInstance(int x, int y, int w, int h){
    return std::shared_ptr<Dot>(new Dot(x, y, w, h));
}

void Dot :: draw(){
    if (SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect()) != 0) {
        std::cerr << "Error rendering Dot: " << SDL_GetError() << std::endl;
    }
}

bool Dot :: isColliding(const std::shared_ptr<Sprite> other) const{
    SDL_Rect thisRect = getRect();
    SDL_Rect otherRect = other -> getRect();
    return SDL_HasIntersection(&thisRect, &otherRect);   
}

void Dot :: onCollision(const std:: shared_ptr<Sprite> other){
        if (std::dynamic_pointer_cast<Pacman>(other)){
            markForRemoval();
        }
}

bool Dot:: isTarget(){
    return true;
}
