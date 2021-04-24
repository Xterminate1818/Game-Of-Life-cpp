#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "App.h"
#include "Grid.h"

int main(int argc, char* args[]) {
    App::init(800, 800);
    Grid grid(25, 25);
    bool quit = false;
    SDL_Event e;
    
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (SDL_BUTTON_LEFT) {
                    int x = 0, y = 0;
                    SDL_GetMouseState(&x, &y);
                    x /= App::getWidth() / grid.gridWidth; y /= App::getHeight() / grid.gridHeight;
                    grid.set(x, y, true);
                }
                break;

            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_SPACE) grid.step();
                break;
            }
        }
        SDL_SetRenderDrawColor(App::renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(App::renderer);
        SDL_SetRenderDrawColor(App::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        App::add(&grid);
        App::drawScreen();
        SDL_RenderPresent(App::renderer);
    }
    App::cleanup();
    return 0;
}