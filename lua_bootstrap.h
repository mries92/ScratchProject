#pragma once
#include <lua.hpp>
#include "lua_data.h"
#include <entt/entity/registry.hpp>

class Game;

class LuaBootstrap
{
public:
	LuaBootstrap(Game& game);
	~LuaBootstrap();
	sol::state& GetLua();
	template <typename T>
	T* GetData(std::string id) { return data_.GetData<T>(id); }
	template <typename T>
	std::unordered_map<std::string, T*> GetAllData() { return data_.GetAllData<T>(); }
	sol::function update, init, notify;
	sol::table key_pressed_event_, key_released_event_, mouse_wheel_event_;
private:
	LuaData data_;
	Game& game_;
	sol::state lua_;
};