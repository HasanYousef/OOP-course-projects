#pragma once

#include <vector>
#include <fstream>
#include <iostream>

#include "macros.h"
#include "WorldObject.h"

class Board {
public:
	Board();
	Board(int, int);
	Board(std::ifstream&, int, int);
	void draw(sf::RenderWindow& window) const;
	void set_object(ObjectType, const sf::Vector2f&);

private:
	void initializeTextures();

	size_t m_height = 0,
		m_width = 0;
	std::vector<std::vector<WorldObject>> m_worldObjects;
	sf::Texture m_textures[];
};