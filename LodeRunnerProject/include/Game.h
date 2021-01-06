#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "PauseMenu.h"
#include "Board.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	void run();
	void add_player();
	void add_enemy();
private:
	void start_menu();
	void start_game();
	void run_level();

	PauseMenu m_pauseMenu;
	int m_level,
		m_numOfLevels;
	World m_world;
	Player m_player;
	std::vector<Enemy> m_enemies;
};