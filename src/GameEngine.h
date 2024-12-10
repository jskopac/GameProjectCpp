#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "Sprite.h"
#include <memory>

#include <vector>


using namespace std;


namespace game{

    class GameEngine{

        public:
            void add(std::shared_ptr<Sprite> s);
            void remove(std::shared_ptr<Sprite> s);
            void run();

        private:
        std::vector<std::shared_ptr<Sprite>> sprites;

    };

    
}
#endif