#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "Sprite.h"
#include <memory>
#include <string>
#include <vector>


using namespace std;


namespace game_engine{ 

    class GameEngine{

        public:
            void add(shared_ptr<Sprite> s);
            void remove(shared_ptr<Sprite> s);
            void run();
            void gameOver();

        private:
            vector<std::shared_ptr<Sprite>> sprites;
            vector<std::shared_ptr<Sprite>> removed_sprites;
            bool game_over;

    };

    

    
}
#endif