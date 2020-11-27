#pragma once

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include "Coord.h"
#include "Macros.h"
#include "Money.h"

//the Controller class controls the game's objects' relations
class Controller {
public:
	//initializing the player score with 0 and level 1
	Controller();
	void run();
	//void next_frame();
private:
	void move_player(const struct Coord);
	void move_enemies();
	bool get_hit();
	bool getcoin();
	void run_level();
	void locate_objects();
	void open_maps_stream();
	void print_ui();
	void get_money();
	void set_gold_on_map();
	int m_level = 0,
		m_score = 0,
		m_remainingMoney = 0;	//storing how many money packs are remaining
	ifstream m_mapsStream;	//the maps file stream
	Board m_originBoard = Board(),
		m_board = Board();
	Player m_player;
	vector <Enemy> m_enemies = {};	//storing the enemies as a vector
	vector <Money> m_money_packs = {};
};