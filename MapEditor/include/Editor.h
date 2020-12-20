#pragma once

#include <SFML/Graphics.hpp>

#include "Board.h"

class Editor {
public:
	Editor();
	void run();

private:
	sf::RenderWindow m_window;
	Board m_board;
};