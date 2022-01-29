#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "game.h"

int main(int argc, char *args[])
{
    // Start game
    Game game;
    game.Start();


    return 0;
}