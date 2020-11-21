#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Board.h"
#include "player.h"
#include "enemy.h"

//the Controller class controls the game's objects' relations
class Controller {
public:
	//initializing the player score with 0 and level 1
	Controller() : m_level(1), m_score(0) {}
	void next_frame();
	int get_health() const;
	int get_score() const;
	int get_level() const;
private:
	int m_level,
		m_score,
		m_remainingMoney;	//storing how many money packs are remaining
	ifstream m_mapsStream;	//the maps file stream
	Board m_board;
	Player m_player;
	vector <Enemy> m_enemies;	//storing the enemies as a vector
};