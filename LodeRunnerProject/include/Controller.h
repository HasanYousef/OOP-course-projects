#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "macros.h"
#include "Game.h"
//#include "Menu.h"
#include "Editor.h"

class Controller {
public:
	Controller();
	void run();
private:
	//Menu m_menu;
	Game m_game;
	Editor m_editor;
	//Editor m_editor;
	sf::RenderWindow m_window;
};