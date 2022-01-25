#pragma once

class Game;

class AssetManager
{
public:
	AssetManager(Game& game);
private:
	Game& game_;
};