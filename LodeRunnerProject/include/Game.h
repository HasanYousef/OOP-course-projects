#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

#include "Menu.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	void run(sf::RenderWindow&);
	void run_level(sf::RenderWindow& window);
	void add_player();
	void add_enemy();
	void open_maps_stream();
private:
	void initializeTextures();
	void move_enemies();
	bool player_get_hit();
	//void pause_menu();
	std::ifstream m_mapsStream;
	//PauseMenu m_pauseMenu;
	int m_level,
		m_numOfLevels;
	Map m_map;
	Player m_player;
	std::vector <Enemy> m_enemies;
	//std::vector<Enemy> m_enemies;
	sf::Texture* m_textures[NUM_OF_TYPES];
};