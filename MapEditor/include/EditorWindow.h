#pragma once

#include <SFML/Graphics.hpp>

#include "Board.h"

class EditorWindow {
public:
	EditorWindow();
	void run();

private:
	sf::RenderWindow m_window;
	Board m_board;
};