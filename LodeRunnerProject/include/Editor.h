#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
//----------------------------------
#include "macros.h"
#include "Map.h"
#include "Panel.h"
//----------------------------------
class Editor {
public:
	Editor();
	void run();

private:
	void handle_click(const sf::Vector2f&);
	void init_map();
	//----------------------------------
	sf::RenderWindow m_window;
	Map m_map;
	Panel m_panel;
	UserOption m_clickMode = UserOption::Nothing;
	sf::Texture* m_textures[NUM_OF_TYPES];
};
