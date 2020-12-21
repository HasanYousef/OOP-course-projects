#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Board.h"
#include "TextButton.h"
#include "TextureButton.h"

class Editor {
public:
	Editor();
	void run();

private:
	void handle_panel_click(const sf::Vector2f&);

	sf::RenderWindow m_window;
	Board m_board;
	ObjectType m_clickMode;
	TextureButton m_textureButtons[NUM_OF_TYPES];
	TextButton m_saveButton;
	TextButton m_clearButton;
};
