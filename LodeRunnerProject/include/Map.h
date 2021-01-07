#pragma once

#include <vector>

#include "macros.h"
#include "GameObject.h"

class Map {
public:
	Map();
	//----------------------------------
	void readFromStream(std::ifstream&, sf::Texture* []);
	void draw(sf::RenderWindow&) const;
	ObjectType get_object_type(const sf::Vector2f& location) const;

private:
	size_t m_height,
		m_width;
	std::vector<std::vector<GameObject>> m_map;
};