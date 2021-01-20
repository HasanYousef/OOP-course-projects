#pragma once


#include <vector>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include "Map.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "StandartEnemy.h"
#include "SmartEnemy.h"
#include "Enemy.h"
#include "Textures.h"
#include "Sounds.h"

class Game {
public:
	Game();
	void run(sf::RenderWindow&, int);
	void run_level(sf::RenderWindow& window);
	void locate_objects();
private:
	//---Functions----------
	void draw_enemies(sf::RenderWindow&);
	void move_enemies();
	bool player_get_hit();
	void drawInfoBar(sf::RenderWindow&, sf::Time) const;
	//---Members------------
	int m_level,
		m_remainingMoney,
		m_time;
	Map m_map;
	Player* m_player;
	//---Arrays_for_members-
	std::vector <Enemy*> m_enemies;
};