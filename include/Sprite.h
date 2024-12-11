#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <memory>
#include <string>

namespace game_engine{

    class Sprite{

        public: 
            virtual void moveDown(){}
            virtual void moveUp(){}
            virtual void moveRight(){}
            virtual void moveLeft(){}
            virtual void draw() = 0;


            SDL_Texture& getTexture();
            void prepareTexture(std::string& image);
            SDL_Surface& getSurf();
            SDL_Rect& getRect();

            //creates a shared_ptr that the subclasses can use.
            template <typename T, typename...Args>
            static std::shared_ptr<T>create(Args&& ... args){
                //checks condition at runtime to ensure that the type T must inherit from Sprite. 
                static_assert(std::is_base_of<Sprite, T> :: value, "T must be a subclass of Sprite");
                // returns a created subclass object of Sprite that is stored on the heap. the shared_ptr is in charge of managing it. 
                return std::make_shared<T>(std::forward<Args>(args)...);
            }


        protected:
            Sprite(int x, int y, int w, int h);

        private:
            SDL_Rect rect;
            SDL_Texture *texture; 
            SDL_Surface *surf;
            Sprite(const Sprite&) = delete;
            const Sprite& operator = (const Sprite&) = delete;

    };

}   





#endif