#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
using namespace std;
#include "PauseMenu.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	void start(sf::RenderWindow&);
	void run_level(sf::RenderWindow& window);
	void add_player();
	void add_enemy();
	void open_maps_stream();
private:
	void initializeTextures();
	//void pause_menu();
	ifstream m_mapsStream;
	//PauseMenu m_pauseMenu;
	int m_level,
		m_numOfLevels;
	Map m_map;
	Player m_player;
	//std::vector<Enemy> m_enemies;
	sf::Texture* m_textures[NUM_OF_TYPES];
};