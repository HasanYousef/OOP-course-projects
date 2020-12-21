#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

#include "macros.h"
#include "Board.h"
#include "Panel.h"

class Editor {
public:
	Editor();
	void run();

private:
	void handleClick(const sf::Vector2f&);
	void initButtons();
	void saveBoard() const;

	sf::RenderWindow m_window;
	Board m_board;
	Panel m_panel;
	ObjectType m_clickMode;
};
