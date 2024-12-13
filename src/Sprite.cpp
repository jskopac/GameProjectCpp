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
    SDL_Texture &Sprite ::getTexture() { return *texture; };
    SDL_Surface &Sprite ::getSurf() { return *surf; };

    void Sprite ::prepareTexture(const string &image)
    {
        surf = IMG_Load(image.c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);

    }

}