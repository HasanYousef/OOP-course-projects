#pragma once

#include <vector>

#include "WorldObject.h"

class Board {
public:
	Board();
	Board(int, int);
private:
	size_t m_height,
		m_width;
	std::vector<WorldObject> m_worldObjects;
};