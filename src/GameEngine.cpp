#include "GameEngine.h"
#include "Sprite.h"
#include "Init.h"

namespace game
{

    void GameEngine ::add(Sprite *s)
    {
        sprites.push_back(s);
    }

    void GameEngine ::run()
    {
        bool quit = false;
        while (!quit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
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
            }
        }
    }

}