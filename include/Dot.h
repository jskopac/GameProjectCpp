#ifndef DOT
#define DOT
#include "Sprite.h"
#include "Pacman.h"
#include "Init.h" 
#include <string>
#include <memory>
#include <SDL.h>

    using namespace game_engine;

    class Dot : public Sprite{


        public:
            static std::shared_ptr<Dot> createInstance(int x, int y, int w, int h);
            void draw();
            bool isColliding(const std::shared_ptr<Sprite> other) const;
            void onCollision(const std:: shared_ptr<Sprite> other);
            bool isTarget();
        private:
            Dot(int x, int y, int w, int h);
            std::string imagePath;


    };







#endif
