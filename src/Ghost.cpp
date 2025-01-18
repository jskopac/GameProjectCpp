#include "Ghost.h"


using namespace game_engine;

Ghost :: Ghost(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/ghost_left.png"){
    //Loads the texture into the sprite
    prepareTexture(imagePath);
}

std::shared_ptr<Ghost> Ghost:: createInstance(int x, int y, int w, int h){
    return std::shared_ptr<Ghost>(new Ghost(x, y, w, h));

}

void Ghost :: draw(){
    if (SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect()) != 0) {
        std::cerr << "Error rendering Ghost: " << SDL_GetError() << std::endl;
    }
}

void Ghost :: auto_move(){
    if (getRect().y <= 30){ 
        directionFlag = true;
    }
    if(getRect().y == 540){ 
        directionFlag = false;    
    } 

    if (directionFlag){
        getRect().y++;
    } else {
        getRect().y--;
    }
}
