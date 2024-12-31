#ifndef PACMAN_H
#define PACMAN_H
#include "Sprite.h"
#include "Wall.h"
#include "Ghost.h"
#include "Init.h"
#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace game_engine;

class Pacman : public Sprite{
public:
    //points static variable
    static std::shared_ptr<Pacman> createInstance(int x, int y, int w, int h);
    void tick(const SDL_Event& event);
    void draw();
    bool isColliding(const std::shared_ptr<Sprite> other) const;
    bool isGamePlayer(){return true;}
    void onCollision(const std:: shared_ptr<Sprite> other);

private:
    Pacman(int x, int y, int w, int h);
    std::string imagePath;

    
};
#endif