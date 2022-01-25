#pragma once
#include "prototype.h"

struct Texture_D : public Prototype
{
	std::string filepath = "";
	std::string texture_id = "";
	bool tileset = false;
	int tile_size = 32;

	void FromLua(sol::table root, const std::string& id)
	{
		SetId(id);
		SetDescription(root.get_or<std::string>("description", ""));
		filepath = root.get_or<std::string>("filepath", "");
		tileset = root.get_or("tileset", false);
		tile_size = root.get_or("tile_size", 32);
	};
};