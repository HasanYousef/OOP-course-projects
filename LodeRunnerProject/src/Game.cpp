#pragma once

#include "Game.h"

//---------------------------------------------
Game::Game() :
	m_level(1),
	m_remainingMoney(0),
	m_time(-1),
	m_player(nullptr)
{}

//-----------------start_game------------------
void Game::run(sf::RenderWindow& window, int numOfLevels) {
	while (m_level <= numOfLevels) {
		run_level(window);
		if (m_player->get_health() == 0) {
			for (int i = 0; i < m_enemies.size(); i++)
				delete m_enemies[i];
			delete m_player;
			m_player = nullptr;
			break;
		}
		m_player->add_score(50);
		if (m_remainingMoney == 0)
			m_level++;
	}
}

//-----------------run_level-------------------
void Game::run_level(sf::RenderWindow& window) {
	sf::Event event;
	sf::Clock clock;
	int remaining_coins = 0;
	//add panel (bottons)
	m_time = m_map.load_map(m_level, 0);
	locate_objects();
	while (window.isOpen()) {
		window.clear();
		sf::Time time = clock.getElapsedTime();
		window.pollEvent(event);
		//we draw the objects
		m_map.draw(window);
		draw_enemies(window);
		m_player->draw(window);
		drawInfoBar(window, time);
		window.display();
		//we check different cases
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		}
		//move the moveAbleObjects
		m_player->move(m_map);
		m_player->fall(m_map);
		move_enemies();
		//m_player->dig(m_map);
  		if (m_player->getCoin(m_map)) {
			m_player->add_score(2*m_level); //need to add a const for coin value
			m_remainingMoney--;
			m_map.set_object(O_Space, m_player->get_position());
		}
		if (m_player->getGift(m_map)) {
			//give him a gift
		}
		if (((time.asSeconds() >= m_time && m_time != -1)) || player_get_hit()) {
			m_player->die();
			if (m_player->get_health() == 0) {
				return;
			}
			clock.restart();
			locate_objects();
		}
		if (m_remainingMoney == 0) {
			return;
		}
	}
}

//---------------------------------------------
void Game::draw_enemies(sf::RenderWindow& window) {
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		m_enemies[enemy]->draw(window);
	}
}

//---------------------------------------------
void Game::move_enemies() {
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		m_enemies[enemy]->move(m_map, m_player->get_position());
		m_enemies[enemy]->fall(m_map);
	}
}

//---------------------------------------------
bool Game::player_get_hit() {
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		if (m_enemies[enemy]->create().getGlobalBounds()
			.intersects(m_player->create().getGlobalBounds()) ) {
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
	m_enemies.clear();
	for (int row = 0; row < m_map.get_height(); row++) {
		for (int col = 0; col < m_map.get_width(); col++) {
			sf::Vector2f points(col * TEXTURE_SIZE, row * TEXTURE_SIZE);
			StandartEnemy* enemy1;
			StupidEnemy* enemy2;
			SmartEnemy* enemy3;
			switch (m_map.get_type(row,col)) {
			case O_Player: //we add the player
				if (!m_player) {
					m_player = new Player;
					m_player->set_position(points);
					m_player->setType(ObjectType::O_Player);
				}
				else {
					m_player->set_position(points);
				}
				break;
			case O_Enemy: //we add the enemy
				switch (1) {
				case 0:
					enemy1 = new StandartEnemy;
					enemy1->setType(ObjectType::O_Enemy);
					enemy1->set_position(points);
					m_enemies.push_back(enemy1);
					break;
				case 1:
					enemy2 = new StupidEnemy;
					enemy2->setType(ObjectType::O_Enemy);
					enemy2->set_position(points);
					m_enemies.push_back(enemy2);
					break;
				case 2:
					enemy3 = new SmartEnemy;
					enemy3->setType(ObjectType::O_Enemy);
					enemy3->set_position(points);
					m_enemies.push_back(enemy3);
					break;
				};
				break;
			case O_Coin: //we add money
				m_remainingMoney++;
				break;
			}
		}
	}
}

void Game::drawInfoBar(sf::RenderWindow& window, sf::Time time) const {
	std::string str = "Health: ";
	str += std::to_string(m_player->get_health());
	str += "   Score: ";
	str += std::to_string(m_player->get_score());
	str += "   Level: ";
	str += std::to_string(m_level);
	str += "   Time: ";
	str += std::to_string(int(time.asSeconds()));
	auto text = sf::Text(str, *(Textures::instance().get_font()));
	text.setPosition({ 10, 400 });
	window.draw(text);
}