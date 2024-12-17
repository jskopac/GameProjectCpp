#include "Wall.h"
#include "Sprite.h"
#include "Init.h"
#include <string>
#include <SDL.h>
#include <memory>

using namespace game_engine;


Wall :: Wall(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/blue_wall.png"){
    prepareTexture(imagePath);
}

std::shared_ptr<Wall> Wall :: getInstance(int x, int y, int w, int h){
    return std::shared_ptr<Wall>(new Wall(x,y,w,h));
}


void Wall :: draw(){
    SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect());
}
