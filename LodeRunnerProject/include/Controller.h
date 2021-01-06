#pragma once

#include <filesystem>
#include <vector>

#include "Board.h"
#include "Player.h"

class Controller {
public:
	Controller();
	void run();
	void add_player();
	void add_enemy();
private:
	void start_menu();
	void start_game();
	void run_level();
	ifstream m_mapsStream;

	int m_level,
		m_numOfLevels;
	World m_world;
	Player m_player;
	std::vector<Enemy> m_enemies;
};