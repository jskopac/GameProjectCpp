#ifndef DOTS
#define DOTS
#include "Sprite.h"
#include <string>
#include <memory>


    using namespace std;
    using namespace game_engine;

    class Dot : public Sprite{


        public:
            static std::shared_ptr<Dot> getInstance(int x, int y, int w, int h);
            void draw();


        protected:
            Dot(int x, int y, int w, int h);


        private:
            string imagePath;


    };







#endif
