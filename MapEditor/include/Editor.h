#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
//----------------------------------
#include "macros.h"
#include "Board.h"
#include "Panel.h"
//----------------------------------
class Editor {
public:
	Editor();
	void run();

private:
	void handleClick(const sf::Vector2f&);
	void initBoard();
	void initializeTextures();
	//----------------------------------
	sf::RenderWindow m_window;
	Board m_board;
	Panel m_panel;
	ActionType m_clickMode = ActionType::Nothing;
	sf::Texture* m_textures[NUM_OF_TYPES];
};
