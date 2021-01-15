#pragma once

#include "Game.h"

//---------------------------------------------
Game::Game() { 
	initializeTextures();
	
	//m_numOfLevels = 5;
};

//-----------------start_game------------------
void Game::run(sf::RenderWindow& window) {
	m_level = 1;
	while (m_level <= m_numOfLevels) {
		m_map.readFromStream(m_mapsStream, m_textures);   //check if its work
		run_level(window);
		m_level++;
		if (m_player.get_health() == 0) {
			exit(EXIT_SUCCESS);
		}
		m_player.add_score(50);
		m_level++;
	}
}

//-----------------run_level-------------------
void Game::run_level(sf::RenderWindow& window) {
	sf::Event event;
	//add panel (bottons)
	//need to allocate objects
	//need to add players and enemies
	while (window.isOpen()) {
		window.clear();
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
			* check if panel bottons presser
			*/
			break;
		//case:
			//break;
		}
		m_player.move(m_map);
		move_enemies();
		//have to add to be able remove block
		if (m_player.getCoin(m_map)) {
			m_player.add_score(10); //need to add a const for coin value
			m_remainingMoney--;
		}
		if (m_player.getGift(m_map)) {
			//give him a gift
		}
		if (player_get_hit()) {
			m_player.die();
			//replay the level ***
		}
		if (m_remainingMoney == 0) {
			return;
		}
	}
	
}

//---------------------------------------------
void Game::open_maps_stream() {
	// opens the text file that contains the initial maps
	m_mapsStream = ifstream(MAP_PATH);
	//if the file didn't open print an error message and exit
	if (!m_mapsStream.is_open()) {
		cerr << "Cannot open the map file\n";
		exit(EXIT_FAILURE);
	}
}

//---------------------------------------------
//here we load the textures
void Game::initializeTextures() {
	//initing the textures object in the array member
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_textures[i] = new sf::Texture();
	//here we initialize all the Textures we need
	(*m_textures[ObjectType::O_Space]).loadFromFile("space.png");
	(*m_textures[ObjectType::O_Wall]).loadFromFile("wall.png");
	(*m_textures[ObjectType::O_Ladder]).loadFromFile("ladder.png");
	(*m_textures[ObjectType::O_Rope]).loadFromFile("rope.png");
	(*m_textures[ObjectType::O_Money]).loadFromFile("money.png");
	(*m_textures[ObjectType::O_Player]).loadFromFile("player.png");
	(*m_textures[ObjectType::O_Enemy]).loadFromFile("enemy.png");
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
	for (int row = 0; row < m_map.getHeight(); row++) {
		for (int col = 0; col < m_map.getWidth(); col++) {
			switch (m_map.get_type({ row,col })) {
			case O_Player: //we add the player
				m_player.set_position({ row,col });
				break;
			case O_Enemy: //we add the enemy
				m_enemies.push_back(Enemy());
				break;
			case O_Money: //we add money
				m_money_packs.push_back(Money(O_Money,
					m_textures[O_Money],
					{ row,col }));
				m_remainingMoney++;
				break;
			}
		}
	}
}
