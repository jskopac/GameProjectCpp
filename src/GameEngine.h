#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <vector>


using namespace std;


namespace game{

    class GameEngine{

        public:
            void add(Sprite* s);
            void remove(Sprite* s);
            void run();
            ~GameEngine();


        private:
        vector<Sprite*> sprites;

    };
}
#endif