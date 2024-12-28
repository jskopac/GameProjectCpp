#include "Sprite.h"
#include "Init.h"
#include <SDL_image.h>
#include <string>

using namespace std;

namespace game_engine
{

    Sprite ::Sprite(int x, int y, int w, int h) : rect{x, y, w, h}, remove(false) {}

    Sprite ::~Sprite(){SDL_DestroyTexture(texture);}

    SDL_Rect &Sprite ::getRect() { return rect; }

    const SDL_Rect &Sprite ::getRect() const { return rect; } // is this one really needed? We are getting error messages without it. 

    SDL_Texture &Sprite ::getTexture() const { return *texture; };

    SDL_Surface &Sprite ::getSurf() const { return *surf; };

    bool Sprite:: isColliding(const std::shared_ptr<Sprite> other) const{return false;};

    void Sprite ::prepareTexture(const string &image)
    {
        surf = IMG_Load(image.c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);

    }

    const bool Sprite:: isMarkedForRemoval(){
        return remove;
    }

    void Sprite :: markForRemoval(){
        remove = true;
    }

    void Sprite :: unmarkForRemoval(){
        remove = false;
    }

}