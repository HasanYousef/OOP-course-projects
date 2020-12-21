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
	std::vector<TextureButton> m_textureButtons;
	std::vector<TextButton> m_textButtons;
};
