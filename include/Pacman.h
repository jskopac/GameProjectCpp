#ifndef PACMAN_H
#define PACMAN_H

#include "Sprite.h"
#include <vector>
#include <string>

using namespace std;
using namespace game_engine;

class Pacman : public Sprite
{
public:
    static std::shared_ptr<Pacman> getInstance(int x, int y, int w, int h);
    virtual void moveDown();
    virtual void moveUp();
    virtual void moveRight();
    virtual void moveLeft();
    void draw();
    bool isColliding(const std::shared_ptr<Sprite> other) const;
    void onCollision(const std:: shared_ptr<Sprite> other);

private:
    Pacman(int x, int y, int w, int h);
    string imagePath;
    bool wallFlag;
};
#endif