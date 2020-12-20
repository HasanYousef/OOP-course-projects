#pragma once

#include <vector>
#include <fstream>
#include <iostream>

#include "macros.h"
#include "WorldObject.h"

class Board {
public:
	Board();	// MAYBE THERE IS NO NEED FOR THIS
	Board(int, int);
	Board(std::ifstream&, int = 0, int = 0);
	void draw(sf::RenderWindow& window) const;

private:
	void initializeTextures();
	sf::Vector2f indexes_to_location(int, int);

	size_t m_height = 0,
		m_width = 0;
	std::vector<std::vector<WorldObject>> m_worldObjects;
	sf::Texture m_textures[];
};