#ifndef PACMAN_H
#define PACMAN_H
#include "Sprite.h"
#include <vector>
#include <string>

using namespace std;
using namespace game_engine;

class Pacman : public Sprite{
public:
    static std::shared_ptr<Pacman> createInstance(int x, int y, int w, int h);
    void tick(const SDL_Event& event);
    void draw();
    bool isColliding(const std::shared_ptr<Sprite> other) const;
    bool isGamePlayer(){return true;}
    void onCollision(const std:: shared_ptr<Sprite> other);

private:
    Pacman(int x, int y, int w, int h);
    string imagePath;
    
};
#endif