#include "GameEngine.h"
#include "Sprite.h"
#include "Init.h"
#define FPS 60 

namespace game
{

    void GameEngine ::add(Sprite *s)
    {
        sprites.push_back(s);
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

                case SDL_KEYDOWN:
                    for (Sprite* s : sprites){
                        //metod som kallar action och skickar med event
                    }
                    break;

                case SDL_KEYUP:
                    for (Sprite* s : sprites){
                        //metod som kallar action och skickar med event
                    }
                    
                }
                delay = nextTick - SDL_GetTicks();
                if (delay > 0){
                    SDL_Delay(delay);
                }
            }
        }
    }

}