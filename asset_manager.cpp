#include "asset_manager.h"
#include "game.h"
#include "texture_d.h"

AssetManager::AssetManager(Game& game) : game_(game)
{
    for (auto& [id, texture] : game_.GetLuaBootstrap().GetAllData<Texture_D>())
    {
        printf("LOADED ASSET: {id: %s}\n", id.c_str());
    }
}