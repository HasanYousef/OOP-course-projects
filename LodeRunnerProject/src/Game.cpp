#pragma once

#include "Game.h"

//---------------------------------------------
Game::Game() :
	m_level(1), m_numOfLevels(5), m_remainingMoney(0), m_time(-1) {}

//-----------------start_game------------------
void Game::run(sf::RenderWindow& window) {
	while (m_level <= m_numOfLevels) {
		run_level(window);
		if (m_player.get_health() == 0) {
			exit(EXIT_SUCCESS);
		}
		m_player.add_score(50);
		//m_level++;         //added
	}
}

void Game::load_map() {
	//we open the level we in
	//The infinty levels reader
	char file[] = "C:board1.txt";
	file[7] = char(m_level + '0');
	fs::path p = file;
	std::ifstream ifile(fs::absolute(p));
	m_time = m_map.read_from_stream(ifile);
	ifile.close();
}

//-----------------run_level-------------------
void Game::run_level(sf::RenderWindow& window) {
	sf::Event event;
	sf::Clock clock;
	int remaining_coins = 0;
	//add panel (bottons)
	load_map();
	//locate_objects();
	while (window.isOpen()) {
		window.clear();
		sf::Time time = clock.getElapsedTime();
		/*--- WE PRINT THE TIME ---*/
		m_map.draw(window);
		window.pollEvent(event);
		//draw panel
		window.display();
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonReleased:
			/*
			* check if panel bottons pressed
			*/
			break;
		//case:
			//break;
		}
		m_player.move(m_map);
		move_enemies();
		//have to add to be able remove block
		if (m_player.getCoin(m_map)) {
			m_player.add_score(2*m_level); //need to add a const for coin value
			m_remainingMoney--;
		}
		if (m_player.getGift(m_map)) {
			//give him a gift
		}
		if (time.asSeconds() >= m_time && m_time != -1 || player_get_hit()) {
			m_player.die();
			//we reset the map
			load_map();
			locate_objects();
		}
		if (m_remainingMoney == 0) {
			return;
		}
	}
	
}

//---------------------------------------------
void Game::move_enemies() {
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		m_enemies[enemy].move(m_map);
	}
}

//---------------------------------------------
bool Game::player_get_hit() {
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		if (m_enemies[enemy].get_position() == m_player.get_position()) {
			return true;
		}
	}
	return false;
}

//-----------------locate_objects--------------
//this func move on the board (array) and locate
//the object we have for example if the elment x.y
//have a enemy we add to the vector of enemy a enemy
//if we find a coin we add to the integer of 
//m_remainingMoney 1 this is how its work
void Game::locate_objects() {
	m_remainingMoney = 0;
	for (int row = 0; row < m_map.get_height(); row++) {
		for (int col = 0; col < m_map.get_width(); col++) {
			switch (m_map.get_type(row,col)) {
			case O_Player: //we add the player
				m_player.set_position(sf::Vector2f(row, col));
				break;
			case O_Enemy: //we add the enemy
				//m_enemies.push_back(Enemy());
				break;
			case O_Coin: //we add money
				m_remainingMoney++;
				break;
			}
		}
	}
}
