#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "macros.h"
#include "Game.h"
#include "Editor.h"
#include "Panel.h"

class Controller {
public:
	Controller();
	void run();
	UserOption runMenu();
private:
	Game m_game;
	Editor m_editor;
	sf::RenderWindow m_window;
};