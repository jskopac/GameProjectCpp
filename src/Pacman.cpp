#include "Pacman.h"
#include "Ghost.h"
#include <SDL.h>
#include <string>
#include "Init.h"
#include "Sprite.h"
#include <iostream>

using namespace std;
using namespace game_engine;

Pacman::Pacman(int x, int y, int w, int h) : Sprite(x, y, w, h), imagePath("./resources/images/pac_right.png")
{
    const std::vector<std::string> imagePaths = {
        "./resources/images/pac_down.png",
        "./resources/images/pac_up.png",
        "./resources/images/pac_right.png",
        "./resources/images/pac_left.png"
    };
    
    for (const auto& path : imagePaths) {
        prepareTexture(path);
    }

}

void Pacman::moveDown()
{
    getRect().y++;
    
}

void Pacman::moveUp()
{
    getRect().y--;
}

void Pacman ::moveRight()
{
    getRect().x++;
}

void Pacman ::moveLeft()
{
    getRect().x--;
}

void Pacman::draw()
{
    SDL_RenderCopy(sys.get_ren(), &getTexture(), NULL, &getRect());
}

std::shared_ptr<Pacman> Pacman::getInstance(int x, int y, int w, int h)
{
    return std::shared_ptr<Pacman>(new Pacman(x, y, w, h));
    
}

bool Pacman:: isColliding(const std::shared_ptr<Sprite> other) const{
    SDL_Rect thisRect = getRect();
    SDL_Rect otherRect = other -> getRect();
    return SDL_HasIntersection(&thisRect, &otherRect);  

}

void Pacman ::  onCollision(const std:: shared_ptr<Sprite> other){
    if (dynamic_pointer_cast<Ghost>(other)){
            markForRemoval();
        }
}

