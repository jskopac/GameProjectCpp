#include "GameEngine.h"
#include "Init.h"
#include "Sprite.h"
#include <SDL.h>
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

        const int tickInterval = 1000 / FPS;
        Uint32 nextTick;
        int delay;
        bool quit = false;
        while (!quit)
        {
            nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT){
                    quit = true;
                }

                for (std::shared_ptr<Sprite> s: sprites){
                    s -> tick(event);
                }
            }


            //checks for collision and onCollision method marks the sprite that is supposed to be removed due to the collision
            for (std::shared_ptr<Sprite> s1 : sprites){
                for(std::shared_ptr<Sprite> s2 : sprites){
                    if (s1 != s2 && s1 -> isColliding(s2)){
                        s1 -> onCollision(s2);
                        s2 -> onCollision(s1);
                    }
                }
            }
            //checks for which sprites are marked for removal and adds calls the remove method that pushes the marked sprite to a remove vector. 
            //should we pass Sprite& instead of Sprite?
            for (std::shared_ptr<Sprite> s : sprites){
                if (s -> isMarkedForRemoval()){
                    remove(s);
                    if (s->isGamePlayer()){
                        gameOver();
                    }
                }
            } 
            //removes sprites that are in the remove vector and also erase it from the game engine vector.
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
                s -> auto_move();
			    s->draw();
            }  
            SDL_RenderPresent(sys.get_ren());


            delay = nextTick - SDL_GetTicks();
            if (delay > 0){
                SDL_Delay(delay);
            }
        }
    }


    void GameEngine::gameOver(){

        //SDL_Window* game_over_win = SDL_CreateWindow("Game Over", SDL_WINDOWPOS_CENTERED, 600, 500, SDL_WINDOW_SHOWN);



    }
}

