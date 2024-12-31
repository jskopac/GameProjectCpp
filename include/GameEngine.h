#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "Sprite.h"
#include "Init.h"
#include <SDL.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace game_engine{ 

    class GameEngine{

        public:
            void add(std::shared_ptr<Sprite> s);
            void remove(std::shared_ptr<Sprite> s);
            void run();
            void gameOver();

        private:
            std::vector<std::shared_ptr<Sprite>> sprites;
            std::vector<std::shared_ptr<Sprite>> removed_sprites;
            bool game_over;

    };

    

    
}
#endif