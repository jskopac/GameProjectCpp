#include "Ghost.h"


using namespace game_engine;

Ghost :: Ghost(int x, int y, int w, int h) : Sprite(x,y,w,h), imagePath("./resources/images/ghost_left.png"){
    prepareTexture(imagePath);
}

std::shared_ptr<Ghost> Ghost:: createInstance(int x, int y, int w, int h){
    return std::shared_ptr<Ghost>(new Ghost(x, y, w, h));

}

void Ghost :: draw(){
    SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect());
}

void Ghost :: auto_move(){
    if (getRect().y <= 30){ // hard coded the walls this can be improved
        directionFlag = true;
    }
    if(getRect().y == 538){ //hard coded the walls this can be improved
        directionFlag = false;    
    } 

    if (directionFlag){
        getRect().y++;
    } else {
        getRect().y--;
    }
}
