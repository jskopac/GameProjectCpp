#include "Wall.h"


using namespace game_engine;


Wall :: Wall(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/blue_wall.png"){
    prepareTexture(imagePath);
}

std::shared_ptr<Wall> Wall :: createInstance(int x, int y, int w, int h){
    return std::shared_ptr<Wall>(new Wall(x,y,w,h));
}

void Wall :: draw(){
    if (SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect()) != 0) {
        std::cerr << "Error rendering Wall: " << SDL_GetError() << std::endl;
    }
}
