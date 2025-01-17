#include "GameEngine.h"
#include "TextMenu.h"


#define FPS 60

namespace game_engine
{
    // add function
    void GameEngine ::add(std::shared_ptr<Sprite> s){
        sprites.push_back(s);
    }

    // remove function
    void GameEngine ::remove(std::shared_ptr<Sprite> s){
        removed_sprites.push_back(s);
    }


    static int score = 0;

    void GameEngine ::run(){
        TextMenu* text = TextMenu::createInstance(350,605,200,100);
        const int tickInterval = 1000 / FPS;
        Uint32 nextTick;
        int delay;
        bool quit = false;
        while (!quit){
            nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT){
                    quit = true;
                }

                for (std::shared_ptr<Sprite> s : sprites){
                    s->tick(event);
                }
            }

            // checks for collision and onCollision method marks the sprite that is supposed to be removed due to the collision
            for (std::shared_ptr<Sprite> s1 : sprites){
                for (std::shared_ptr<Sprite> s2 : sprites){
                    if (s1 != s2 && s1->isColliding(s2)){
                        s1->onCollision(s2);
                        s2->onCollision(s1);
                    }
                }
            }
            // checks for which sprites are marked for removal and adds calls the remove method that pushes the marked sprite to a remove vector.
            // should we pass Sprite& instead of Sprite?
            for (std::shared_ptr<Sprite> s : sprites){
                if (s->isMarkedForRemoval()){
                    remove(s);
                    if (s->isGamePlayer()){
                        game_over = true;
                        quit = true;
                    }
                    if (s->isTarget()){
                        score++;
                    }
                }
            }

            // removes sprites that are in the remove vector and also erase it from the game engine vector.
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

            // updates the sprites with their new position
            removed_sprites.clear();
            SDL_RenderClear(sys.get_ren());
            for (const std::shared_ptr<Sprite> &s : sprites){
                s->auto_move();
                s->draw();
            }

            // updates the score text
            text->setText("Score: " + std::to_string(score)); 
            text->render();

            // display the new positions/score
            SDL_RenderPresent(sys.get_ren());

            delay = nextTick - SDL_GetTicks();
            if (delay > 0){
                SDL_Delay(delay);
            }
        }

        // game over screen
        if (game_over){
            bool quit;
            while (!quit){
                SDL_Event event;
                while (SDL_PollEvent(&event)){
                    if (event.type == SDL_QUIT){
                        quit = true;
                    }
                }
                SDL_RenderClear(sys.get_ren());
                text->setText("Game Over! \n You got: " + std::to_string(score) + " points");
                text->getRect().y = 300; 
                text->getRect().x = 250;
                text->render();
                SDL_RenderPresent(sys.get_ren());
            }
            
        }        
    }
}

