#include "Sprite.h"
#include <memory>

namespace game{
    

    Sprite :: Sprite(int x, int y, int w, int h) : rect{x,y,w,h}{};
    
    SDL_Rect& Sprite :: getRect() {return rect;};

}