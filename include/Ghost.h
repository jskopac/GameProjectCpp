#ifndef GHOST
#define GHOST

#include "Sprite.h"

using namespace std;
using namespace game_engine;

class Ghost : public Sprite{

public:
    static std::shared_ptr<Ghost> getInstance(int x, int y, int w, int h);
    void draw();
    void auto_move();

private:
    Ghost(int x, int y, int w, int h);
    string imagePath;
    bool directionFlag;

};





#endif