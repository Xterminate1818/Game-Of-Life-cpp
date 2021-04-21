#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "rendering/App.h"
#include "geometry/Rect.h"

int main(int argc, char* args[]) {
    App::init();
    Rect r(0, 0, 25, 25);
    bool quit = false;
    SDL_Event e;
    
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(App::renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(App::renderer);
        Drawable::add(&r);
        Drawable::drawScreen();
        SDL_RenderPresent(App::renderer);
    }
    App::cleanup();
    return 0;
}