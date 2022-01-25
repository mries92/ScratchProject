#include <SDL2/SDL_keyboard.h>
#include "lua_bootstrap.h"
#include "game.h"
#include "sol/sol.hpp"

LuaBootstrap::~LuaBootstrap()
{
    sol::table data = lua_["data"];
    data.clear();
    sol::table game = lua_["game"];
    game.clear();
}

LuaBootstrap::LuaBootstrap(Game& game) : data_(), game_(game)
{
    lua_.open_libraries(sol::lib::base, sol::lib::jit, sol::lib::string, sol::lib::table, sol::lib::package, sol::lib::math, sol::lib::coroutine, sol::lib::os);
    lua_["package"]["path"] = ";./assets/prototypes/?.lua";
    lua_.script_file("./assets/prototypes/prototypes.lua");
    sol::table dat = lua_["data"];
    data_.LoadFromTable(dat);
    lua_.create_named_table("game");
    sol::table game_table = lua_["game"];
}

sol::state& LuaBootstrap::GetLua()
{
    return lua_;
}