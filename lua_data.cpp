#include "lua_data.h"
#include "texture_d.h"

void LuaData::LoadFromTable(sol::table& t)
{
    data_table_ = t;
    LoadPrototypes<Texture_D>("textures");
}

template <typename T>
void LuaData::LoadPrototypes(std::string table_id)
{
    sol::object ta = data_table_[table_id];
    if (ta != sol::nil)
    {
        auto type_map = this->type_map_.try_emplace(std::type_index(typeid(T)));
        if (type_map.second)
        {
            auto& map = (*type_map.first).second;
            ta.as<sol::table>().for_each([&map](sol::object key, sol::object value) mutable
                {
                    auto element = map.try_emplace(key.as<std::string>(), std::make_unique<T>());
                    if (element.second)
                        (*element.first).second->FromLua(value.as<sol::table>(), key.as<std::string>()); });
        }
    }
    else
    {
        printf("Table not found in lua state: %s", table_id.c_str());
    }
}