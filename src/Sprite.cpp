#include "Sprite.h"

namespace game{
    

    Sprite :: Sprite(int x, int y, int w, int h) : rect{x,y,w,h}{};
    
    const SDL_Rect& Sprite :: getRect(){return rect;};

}