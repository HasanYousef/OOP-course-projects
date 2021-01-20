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
	void run(sf::RenderWindow&, int level);

private:
	void handle_click(const sf::Vector2f&);
	void initMap();
	void initPanel();
	//----------------------------------
	Map m_map;
	Panel m_panel;
	UserOption m_clickMode;
};
