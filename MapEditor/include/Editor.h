#pragma once

#include <SFML/Graphics.hpp>

#include "Board.h"

class Editor {
public:
	Editor();
	void run();

private:
	sf::Vector2f indexes_to_location(int col, int row);

	sf::RenderWindow m_window;
	Board m_board;
};
