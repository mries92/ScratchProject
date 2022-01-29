#include "game.h"

Game::Game() : lua_(*this),
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
