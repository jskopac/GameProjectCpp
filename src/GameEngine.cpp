#include "GameEngine.h"
#include "Sprite.h"
#include "Init.h"
#include "Pacman.h"
#include <iostream>
#include <memory>


#define FPS 60 

namespace game
{

    void GameEngine ::add(std::shared_ptr<Sprite> s)
    {
        sprites.push_back(s);
        //std::cout << "Something was added!" << std::endl;
    }

    void GameEngine ::run()
    {
        const int tickInterval = 1000 / FPS;
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
/*
                case SDL_KEYDOWN:
                    for (const std::shared_ptr<Sprite>& s : sprites){
                        //metod som kallar action och skickar med event
                    }
                    break;

                case SDL_KEYUP:
                    for (const shared_ptr<Sprite>& s : sprites){
                        //metod som kallar action och skickar med event
                    }
*/
                }
            }

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