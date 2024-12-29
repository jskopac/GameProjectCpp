#ifndef WALL 
#define WALL

#include "Sprite.h"
#include "Init.h"
#include <SDL.h>
#include <memory>
#include <string>

using namespace std;
using namespace game_engine;

class Wall : public Sprite {

public:
    static std::shared_ptr<Wall> createInstance(int x, int y, int w, int h);
    void draw();

private:
    Wall(int x, int y, int w, int h);
    string imagePath;

};




#endif