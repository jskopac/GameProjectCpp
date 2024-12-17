#ifndef DOT
#define DOT
#include "Sprite.h"
#include <string>
#include <memory>


    using namespace std;
    using namespace game_engine;

    class Dot : public Sprite{


        public:
            static std::shared_ptr<Dot> getInstance(int x, int y, int w, int h);
            void draw();
            bool isColliding(const std::shared_ptr<Sprite> other) const;
            void onCollision(const std:: shared_ptr<Sprite> other);

        private:
            Dot(int x, int y, int w, int h);
            string imagePath;


    };







#endif
