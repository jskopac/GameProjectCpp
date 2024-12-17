#include "Ghost.h"
#include "Init.h"
#include "Sprite.h"
#include <SDL.h>
#include <memory>

using namespace game_engine;

Ghost :: Ghost(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/ghost_left.png"){
    prepareTexture(imagePath);
}

std::shared_ptr<Ghost> Ghost:: getInstance(int x, int y, int w, int h){
    return std::shared_ptr<Ghost>(new Ghost(x, y, w, h));

}

void Ghost :: draw(){
    SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect());
}
