#include "Sprite.h"
#include <vector>
#include <string>

using namespace std;

namespace game{

    class Pacman : public Sprite{
    public:
        static Pacman* getInstance(int x, int y, int w, int h);
        void keyDown(const SDL_Event&){};
        void keyUp(const SDL_Event&){};
        void draw() const;


    protected:
        Pacman(int x, int y, int w, int h);

    private:
        vector<string> allImagePaths = {
            "./resources/images/pac-right.png",
            "./resources/images/pac-left.png",
            "./resources/images/pac-down.png",
            "./resources/images/pac-up.png"
        };
        SDL_Texture* texture;

    };

}
