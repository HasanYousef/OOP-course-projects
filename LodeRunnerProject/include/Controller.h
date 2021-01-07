#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <vector>

#include "macros.h"
#include "Game.h"
#include "MainMenu.h"
#include "Board.h"
#include "Player.h"

class Controller {
public:
	Controller();
	void run();
private:

	Game m_game;
	MainMenu m_menu;
	sf::RenderWindow m_window;
	ifstream m_mapsStream;
};