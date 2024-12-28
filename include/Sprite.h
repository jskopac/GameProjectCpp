#ifndef SPRITE_H
#define SPRITE_H
#include "Init.h"
#include <SDL_image.h>
#include <SDL.h>
#include <memory>
#include <vector>
#include <string>


namespace game_engine{

    class Sprite{

        public: 
            virtual bool isGamePlayer(){return false;}

            virtual void tick(const SDL_Event& event){}
            virtual void draw() = 0;
            virtual void auto_move(){}

            virtual bool isColliding(const std::shared_ptr<Sprite> other) const;
            virtual void onCollision(const std:: shared_ptr<Sprite> other){}

            const bool isMarkedForRemoval(); 
            void markForRemoval();
            void unmarkForRemoval();
            virtual ~Sprite();

            SDL_Texture& getTexture() const;
            void prepareTexture(const std::string& image);
            SDL_Surface& getSurf() const;
            SDL_Rect& getRect();
            const SDL_Rect& getRect() const; // is this one really needed? We are getting error messages without it. 

            //creates a shared_ptr that the subclasses can use.
            template <typename T, typename...Args>
            static std::shared_ptr<T>create(Args&& ... args){
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
            bool remove;

    };

}   
#endif