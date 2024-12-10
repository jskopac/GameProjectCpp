#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <memory>

namespace game{

    class Sprite{

        public:

            //maybe we should have these in the game engine, and instead have functions here that is more explanatory like move forward
            // backward etc.
            //virtual void keyDown(const SDL_Event&){};
            //virtual void keyUp(const SDL_Event&){};
            //mouse down 
            //mouse up


            // we should have general movements for sprites in general. Not pacman specifics. 
            

            virtual void draw() const = 0;
            const SDL_Rect& getRect() const;

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
            Sprite(const Sprite&) = delete;
            const Sprite& operator = (const Sprite&) = delete;

    };

}   





#endif