#include "Sprite.h"

using namespace std;

namespace game_engine
{

    Sprite ::Sprite(int x, int y, int w, int h) : rect{x, y, w, h}, remove(false) {}

    Sprite ::~Sprite(){
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }

    SDL_Rect &Sprite ::getRect() { return rect; }

    const SDL_Rect &Sprite ::getRect() const { return rect; }

    SDL_Texture &Sprite ::getTexture() const { return *texture; };

    SDL_Surface &Sprite ::getSurf() const { return *surf; };

    void Sprite ::prepareTexture(const string &image)
    {
        //loads image and creates a SDL_surface
        surf = IMG_Load(image.c_str());
        if (!surf) {
            std::cerr << "Error creating SDL_surface: " << IMG_GetError() << std::endl;
            return;
        }

        //creates texture out of the surface
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        if (!texture) {
            std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surf);
            return;
        }

        // free the surface to avoid memory leaks
        SDL_FreeSurface(surf);
    }
    
    bool Sprite:: isColliding(const std::shared_ptr<Sprite> other) const{ return false; }

    const bool Sprite:: isMarkedForRemoval(){ return remove; }

    void Sprite :: markForRemoval(){ remove = true; }

    void Sprite :: unmarkForRemoval(){ remove = false; }

}