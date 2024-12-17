#include "GameEngine.h"
#include "Sprite.h"
#include "Init.h"
#include <iostream>
#include <string>
#include <memory>


#define FPS 60 

namespace game_engine
{

    void GameEngine ::add(std::shared_ptr<Sprite> s)
    {
        sprites.push_back(s);
    }

    //remove function
    void GameEngine :: remove(std::shared_ptr<Sprite> s){
        removed_sprites.push_back(s);
    }

    void GameEngine ::run()
    {
        const int tickInterval = 100 / FPS;
        Uint32 nextTick;
        int delay;
        bool quit = false;
        while (!quit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                nextTick = SDL_GetTicks() + tickInterval;
                switch (event.type)
                {
                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_KEYDOWN:
                    for (const std::shared_ptr<Sprite>& s : sprites){
                        if (event.key.keysym.sym == SDLK_RIGHT) {
                            s -> moveRight();
                        } if (event.key.keysym.sym == SDLK_LEFT){
                            s -> moveLeft();
                        } if (event.key.keysym.sym == SDLK_UP){
                            s -> moveUp();
                        } if (event.key.keysym.sym == SDLK_DOWN){
                            s -> moveDown();
                        }
                    }
                    break;
                }
            }

            for (std::shared_ptr<Sprite> s1 : sprites){
                for(std::shared_ptr<Sprite> s2 : sprites){
                    if (s1 != s2 && s1 -> isColliding(s2)){
                        s1 -> onCollision(s2);
                        s2 -> onCollision(s1);
                    }
                }
            }
            //should we pass Sprite& instead of Sprie?
            for (std::shared_ptr<Sprite> s : sprites){
                if (s -> isMarkedForRemoval()){
                    remove(s);
                    s -> unmarkForRemoval();
                }
            } 



            for (std::shared_ptr<Sprite> s : removed_sprites){
                for (auto i = sprites.begin(); i != sprites.end();){
                    if (*i == s){
                        i = sprites.erase(i);
                    }
                    else{
                        i++;
                    }

                }
                
            }


            removed_sprites.clear();
            SDL_RenderClear(sys.get_ren());
            for (const std::shared_ptr<Sprite>&  s : sprites){
			    s->draw();
            }  
            SDL_RenderPresent(sys.get_ren()); 


            delay = nextTick - SDL_GetTicks();
            if (delay > 0){
                SDL_Delay(delay);
            }
        }
    }

}