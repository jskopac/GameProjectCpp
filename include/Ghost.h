#ifndef GHOST
#define GHOST
#include "Sprite.h"
#include "Init.h"
#include <SDL.h>
#include <memory>

using namespace game_engine;

class Ghost : public Sprite{

public:
    static std::shared_ptr<Ghost> createInstance(int x, int y, int w, int h);
    void draw();
    void auto_move();

private:
    Ghost(int x, int y, int w, int h);
    std::string imagePath;
    bool directionFlag;

};





#endif