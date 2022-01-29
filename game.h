#pragma once
#define SOL_ALL_SAFETIES_ON 1
#include <memory>
#include <SDL2/SDL.h>
#include "asset_manager.h"
#include "lua_bootstrap.h"

class LuaBootstrap;

class Game
{
public:
	Game();
	void Start();
	AssetManager& GetAssetManager();
	LuaBootstrap& GetLuaBootstrap() { return lua_; };
	void Quit();
private:
	bool quit_ = false;
	LuaBootstrap lua_;
	AssetManager asset_manager_;
};