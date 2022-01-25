#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "game.h"
#include <glad/glad.h>

void quit(std::string message)
{
    printf("%s SDL: %s", message.c_str(), SDL_GetError());
    SDL_Quit();
    exit(1);
}

int main(int argc, char *args[])
{
    // SDL and OpenGL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        quit("Could not initialize SDL.");
    else
    {
        SDL_Window *window = nullptr;
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        window = SDL_CreateWindow("Incursion", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL);
        if (!window)
            quit("Could not create window.");
        SDL_GL_CreateContext(window);
        gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
        SDL_GL_SetSwapInterval(1);
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_FALSE);
        glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DEBUG_TYPE_ERROR, GL_DONT_CARE, 0, NULL, GL_TRUE);

        // Start game
        Game game(window);
        game.Start();

        SDL_DestroyWindow(window);
        SDL_Quit();
    }    

    return 0;
}