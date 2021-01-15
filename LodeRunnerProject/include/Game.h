#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

#include "Menu.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Money.h"

class Game {
public:
	Game();
	void run(sf::RenderWindow&);
	void run_level(sf::RenderWindow& window);
	void open_maps_stream();
	void locate_objects();
private:
	void initializeTextures();
	void move_enemies();
	bool player_get_hit();
	//void pause_menu();
	std::ifstream m_mapsStream;
	//PauseMenu m_pauseMenu;
	int m_level,
		m_numOfLevels,
		m_remainingMoney;
	Map m_map;
	Player m_player;
	std::vector <Enemy> m_enemies;
	std::vector <Money> m_money_packs;
	sf::Texture* m_textures[NUM_OF_TYPES];
};