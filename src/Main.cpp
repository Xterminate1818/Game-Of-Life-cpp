#include <iostream>
#include <SDL.h>
#include "rendering/App.h"
#include "entity/Grid.h"


int main(int argc, char* argv[]) {
    App app(800, 800);
    Grid grid(800, 800);
    app.addChild(&grid);
    app.start();
    return 0;
}