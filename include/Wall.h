#ifndef WALL 
#define WALL

#include "Sprite.h"
#include <string>

using namespace std;
using namespace game_engine;

class Wall : public Sprite {

public:
    static std::shared_ptr<Wall> getInstance(int x, int y, int w, int h);
    void draw();

private:
    Wall(int x, int y, int w, int h);
    string imagePath;

};




#endif