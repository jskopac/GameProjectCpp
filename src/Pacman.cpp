#include "Pacman.h"
#include "Dot.h"


using namespace std;
using namespace game_engine;

Pacman::Pacman(int x, int y, int w, int h) : Sprite(x, y, w, h), imagePath("./resources/images/pac_right.png"){ 
    //Loads the texture into the sprite
    prepareTexture(imagePath);
}

void Pacman::tick(const SDL_Event& event){

    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_LEFT) {
            if (getRect().x < 800){
                getRect().x -= 2; 
            }
        }
        if (event.key.keysym.sym == SDLK_RIGHT) {
            if (getRect().x > 0){
                getRect().x += 2; 
            }
        }
        if (event.key.keysym.sym == SDLK_UP) {
            if (getRect().y > 0){
                getRect().y -= 2; 
            }
        }
        if (event.key.keysym.sym == SDLK_DOWN) {
            if (getRect().y < 800){
                getRect().y += 2; 
            } 
        }
    }
}

void Pacman::draw(){
    if (SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect()) != 0) {
        std::cerr << "Error rendering Pacman: " << SDL_GetError() << std::endl;
    }
}

std::shared_ptr<Pacman> Pacman::createInstance(int x, int y, int w, int h){
    return std::shared_ptr<Pacman>(new Pacman(x, y, w, h));
    
}

bool Pacman:: isColliding(const std::shared_ptr<Sprite> other) const{
    SDL_Rect thisRect = getRect();
    SDL_Rect otherRect = other -> getRect();
    return SDL_HasIntersection(&thisRect, &otherRect);

}

void Pacman :: onCollision(const std:: shared_ptr<Sprite> other){
    if (dynamic_pointer_cast<Ghost>(other)){
        markForRemoval();
    }   
}

bool Pacman :: isGamePlayer() { return true; }


