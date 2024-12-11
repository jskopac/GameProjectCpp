#include "Pacman.h"
#include <SDL.h>
#include <string>
#include "Init.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

using namespace game_engine;

Pacman::Pacman(int x, int y, int w, int h) : Sprite(x, y, w, h), imagePath("./resources/images/pac_right.png")
{
    prepareTexture(imagePath);

}

Pacman *Pacman::getInstance(int x, int y, int w, int h)
{
    return new Pacman(x, y, w, h);
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

