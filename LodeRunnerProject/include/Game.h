#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

//#include "Menu.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	void run(sf::RenderWindow&);
	void load_map();
	void run_level(sf::RenderWindow& window);
	void locate_objects();
private:
	//---Functions----------
	void move_enemies();
	bool player_get_hit();
	//void pause_menu();
	//PauseMenu m_pauseMenu;
	//---Members------------
	int m_level,
		m_numOfLevels,
		m_remainingMoney,
		m_time;
	Map m_map;
	Player m_player;
	//---Arrays_for_members-
	std::vector <Enemy> m_enemies;
};