#pragma once
#define SOL_ALL_SAFETIES_ON 1
#include <memory>
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include "entt/entity/registry.hpp"
#include "asset_manager.h"
#include "lua_bootstrap.h"

class LuaBootstrap;

class Game
{
public:
	Game(SDL_Window* window);
	void Start();
	AssetManager& GetAssetManager();
	entt::registry& GetRegistry() { return registry_; };
	LuaBootstrap& GetLuaBootstrap() { return lua_; };
	void Quit();
private:
	bool quit_ = false;
	SDL_Window& window_;
	entt::registry registry_;
	LuaBootstrap lua_;
	AssetManager asset_manager_;
};