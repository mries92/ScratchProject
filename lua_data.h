#pragma once
#include <typeindex>
#include "sol/sol.hpp"
#include <unordered_map>
#include "prototype.h"

class LuaData
{
public:
    LuaData() {}
    LuaData(const LuaData& d) = delete;
    LuaData& operator=(const LuaData& d) = delete;
    void LoadFromTable(sol::table& t);
    template <typename T>
    T *GetData(std::string id)
    {
        return static_cast<T *>(type_map_[typeid(T)][id].get());
    }
    template <typename T>
    std::unordered_map<std::string, T *> GetAllData()
    {
        std::unordered_map<std::string, T *> data;
        for (auto &pair : type_map_[std::type_index(typeid(T))]) // Fails here in release
        {
            data.try_emplace(pair.first, static_cast<T *>(pair.second.get()));
        }
        return data;
    }
private:
    template <typename T>
    void LoadPrototypes(std::string table_id);
    std::unordered_map<std::type_index, std::unordered_map<std::string, std::unique_ptr<Prototype>>> type_map_;
    sol::table data_table_;
};