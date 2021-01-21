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
	UserOption run(sf::RenderWindow&, int, int);

private:
	UserOption handle_click(const sf::Vector2f&, sf::RenderWindow&);
	void initMap(sf::RenderWindow&);
	void initPanel();
	//----------------------------------
	Map m_map;
	Panel m_panel;
	UserOption m_clickMode;
	int m_level, m_numOfLevels;
};
