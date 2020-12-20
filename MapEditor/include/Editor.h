#pragma once

#include <SFML/Graphics.hpp>

#include "Board.h"

class Editor {
public:
	Editor();
	void run();

private:
	void handle_board_click(const sf::Vector2f&);

	sf::RenderWindow m_window;
	Board m_board;
	ClickMode m_mode;
};
