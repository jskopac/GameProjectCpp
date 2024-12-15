#include "Sprite.h"
#include "Init.h"
#include <SDL_image.h>
#include <memory>
#include <string>

using namespace std;

namespace game_engine
{

    Sprite ::Sprite(int x, int y, int w, int h) : rect{x, y, w, h} {}
    SDL_Rect &Sprite ::getRect() { return rect; }
    const SDL_Rect &Sprite ::getRect() const { return rect; } // is this a good design?

    SDL_Texture &Sprite ::getTexture() const { return *texture; };
    SDL_Surface &Sprite ::getSurf() const { return *surf; };
    bool Sprite:: isColliding(const std::shared_ptr<Sprite> other) const{return false;};

    void Sprite ::prepareTexture(const string &image)
    {
        surf = IMG_Load(image.c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);

    }

}