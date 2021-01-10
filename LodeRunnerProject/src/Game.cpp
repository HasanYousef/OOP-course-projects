#pragma once

#include "Game.h"

//---------------------------------------------
Game::Game() { 
	initializeTextures();
};

//-----------------start_game-----------------
void Game::start(sf::RenderWindow& window) {
	m_level = 1;
	while (m_level <= m_numOfLevels) {
		m_map.readFromStream(m_mapsStream, m_textures);
		run_level(window);
		m_level++;
		if (m_player.get_health() == 0) {
			exit(EXIT_SUCCESS);
		}
		m_player.add_score(50);
		m_level++;
	}
}

//-----------------run_level-----------------
void Game::run_level(sf::RenderWindow& window) {
	sf::Event event;

	while (window.isOpen())
	{
		window.clear();
		m_map.draw(window);
		window.pollEvent(event);
		window.display();
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		m_player.Player_move(m_map);
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

//--------------------------------------------
//here we load the textures
void Game::initializeTextures() {
	//initing the textures object in the array member
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_textures[i] = new sf::Texture();

	(*m_textures[ObjectType::O_Space]).loadFromFile("space.png");
	(*m_textures[ObjectType::O_Wall]).loadFromFile("wall.png");
	(*m_textures[ObjectType::O_Ladder]).loadFromFile("ladder.png");
	(*m_textures[ObjectType::O_Rope]).loadFromFile("rope.png");
	(*m_textures[ObjectType::O_Money]).loadFromFile("money.png");
	(*m_textures[ObjectType::O_Player]).loadFromFile("player.png");
	(*m_textures[ObjectType::O_Enemy]).loadFromFile("enemy.png");
}
