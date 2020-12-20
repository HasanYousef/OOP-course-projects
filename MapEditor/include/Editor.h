#pragma once

#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Button.h"
#include "EditButton.h"

class Editor {
public:
	Editor();
	void run();

private:
	void handle_panel_click(const sf::Vector2f&);

	sf::RenderWindow m_window;
	Board m_board;
	ObjectType m_clickMode;
	EditButton m_editButtons[];
	Button m_saveButton;
	Button m_clearButton;
};
