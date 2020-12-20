#pragma once

#include <vector>

#include "WorldObject.h"

class Board {
public:
	Board();
	Board(int = 0, int = 0);
	Board(ifstream& = nullptr, int = 0, int = 0);

private:
	size_t m_height = 0,
		m_width = 0;
	std::vector<std::vector<WorldObject>> m_worldObjects;
	sf::Texture m_textures[];
};