#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <vector>

#include "Game.h"
#include "MainMenu.h"
#include "Board.h"
#include "Player.h"

class Controller {
public:
	Controller();
	void run();
	void start_game();
	void 
	void add_player();
	void add_enemy();
private:

	Game m_game;
	MainMenu m_menu;
	sf::RenderWindow m_window;
	ifstream m_mapsStream;
};