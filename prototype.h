#pragma once
#include <string>
#include <sol/sol.hpp>

class Prototype
{
public:
	std::string GetId() { return id_; };
	void SetId(std::string id) { id_ = id; };
	std::string GetDescription() { return description_; };
	void SetDescription(std::string description) { description_ = description; };
	virtual void FromLua(sol::table root, const std::string& id) = 0;
private:
	std::string id_;
	std::string description_;
};