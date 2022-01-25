#include "game.h"

Game::Game(SDL_Window *window) : window_(*window),
                                 registry_(),
                                 lua_(*this),
                                 asset_manager_(*this)
{
}

void Game::Start()
{
}

void Game::Quit()
{
    quit_ = true;
}

AssetManager &Game::GetAssetManager()
{
    return asset_manager_;
}
