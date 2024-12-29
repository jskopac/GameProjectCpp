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

    // remove function
    void GameEngine ::remove(std::shared_ptr<Sprite> s)
    {
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
                if (event.type == SDL_QUIT)
                {
                    quit = true;
                }

                for (std::shared_ptr<Sprite> s : sprites)
                {
                    s->tick(event);
                }
            }

            // checks for collision and onCollision method marks the sprite that is supposed to be removed due to the collision
            for (std::shared_ptr<Sprite> s1 : sprites)
            {
                for (std::shared_ptr<Sprite> s2 : sprites)
                {
                    if (s1 != s2 && s1->isColliding(s2))
                    {
                        s1->onCollision(s2);
                        s2->onCollision(s1);
                    }
                }
            }
            // checks for which sprites are marked for removal and adds calls the remove method that pushes the marked sprite to a remove vector.
            // should we pass Sprite& instead of Sprite?
            for (std::shared_ptr<Sprite> s : sprites)
            {
                if (s->isMarkedForRemoval())
                {
                    remove(s);
                    if (s->isGamePlayer())
                    {
                        game_over = true;
                        quit = true;
                    }
                }
            }

            // removes sprites that are in the remove vector and also erase it from the game engine vector.
            for (std::shared_ptr<Sprite> s : removed_sprites)
            {
                for (auto i = sprites.begin(); i != sprites.end();)
                {
                    if (*i == s)
                    {
                        i = sprites.erase(i);
                    }
                    else
                    {
                        i++;
                    }
                }
            }

            removed_sprites.clear();
            SDL_RenderClear(sys.get_ren());
            for (const std::shared_ptr<Sprite> &s : sprites)
            {
                s->auto_move();
                s->draw();
            }
            SDL_RenderPresent(sys.get_ren());

            delay = nextTick - SDL_GetTicks();
            if (delay > 0)
            {
                SDL_Delay(delay);
            }
        }

        if (game_over)
        {
            gameOver();
        }
    }


    //beutify this.

    void GameEngine::gameOver()
    {
        std::string text = "Game Over";
        SDL_Surface *game_over_surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {255, 255, 255});
        SDL_Texture *game_over_text = SDL_CreateTextureFromSurface(sys.get_ren(), game_over_surf);
        SDL_Rect text_rect = {100, 100, 0, 0};
        SDL_QueryTexture(game_over_text, NULL, NULL, &text_rect.w, &text_rect.h); // Query the texture for its size

        SDL_RenderClear(sys.get_ren()); 
        SDL_RenderCopy(sys.get_ren(), game_over_text, nullptr, &text_rect);
        SDL_RenderPresent(sys.get_ren());

        bool quit;
        while (!quit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    quit = true;
                }
            }
        }
    }
    
}

