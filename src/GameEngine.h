#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "Sprite.h"

#include <vector>


using namespace std;


namespace game{

    class GameEngine{

        public:
            void add(Sprite* s);
            void remove(Sprite* s);
            void run();

        private:
        vector<Sprite*> sprites;

    };

    
}
#endif