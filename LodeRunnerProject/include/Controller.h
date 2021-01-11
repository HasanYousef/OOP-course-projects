#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>			//?????
#include <vector>
#include <iostream>

#include "macros.h"
#include "Game.h"
#include "MainMenu.h"
#include "Editor.h"

class Controller {
public:
	Controller();
	void run();
private:
	MainMenu m_menu;
	Game m_game;
	Editor m_editor;
	sf::RenderWindow m_window;
	//std::ifstream m_mapsStream;
};