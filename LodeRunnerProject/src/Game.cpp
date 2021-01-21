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
	Sounds::instance().getSound(SoundType::Theme)->play();
	m_level = 1;
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
	Sounds::instance().getSound(SoundType::Theme)->stop();
}

//-----------------run_level-------------------
void Game::run_level(sf::RenderWindow& window) {
	sf::Event event;
	sf::Clock clock;
	int remaining_coins = 0;
		m_currWell = -1;
	//add panel (bottons)
	m_time = m_map.load_map(m_level, 0);
	locate_objects();
	while (window.isOpen()) {
		window.clear();
		sf::Time time = clock.getElapsedTime();
		window.pollEvent(event);
		//we draw the objects
		m_map.draw(window, false);
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
		//Player Diging
		sf::Vector2f* p = get_dig_points();
		fillWell();
		//--------------------
		if (m_player->getCoin(m_map)) {
			Sounds::instance().getSound(SoundType::GetCoin)->play();
			m_player->add_score(2*m_level); //need to add a const for coin value
			m_remainingMoney--;
			m_map.set_object(O_Space, m_player->get_position());
		}
		if (m_player->getGift(m_map)) {
			switch (rand() % 2)
			{
			case 0:
				m_player->add_score(20);
				break;
			case 1:
				m_player->add_health(1);
				break;
			}

			m_map.set_object(O_Space, m_player->get_position());
		}
		if (((time.asSeconds() >= m_time && m_time != -1)) || player_get_hit()) {
			Sounds::instance().getSound(SoundType::GetHit)->play();
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
				switch (rand() % 2) {
				case 0:
					enemy3 = new SmartEnemy;
					enemy3->setType(ObjectType::O_Enemy);
					enemy3->set_position(points);
					m_enemies.push_back(enemy3);
					break;
				case 1:
					enemy2 = new StupidEnemy;
					enemy2->setType(ObjectType::O_Enemy);
					enemy2->set_position(points);
					m_enemies.push_back(enemy2);
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

//---------------------------------------------
void Game::drawInfoBar(sf::RenderWindow& window, sf::Time time) const {
	std::string str = "Health: ";
	str += std::to_string(m_player->get_health());
	str += "   Score: ";
	str += std::to_string(m_player->get_score());
	str += "   Level: ";
	str += std::to_string(m_level);
	if (m_time != -1) {
		str += "   Time: ";
		str += std::to_string(m_time - int(time.asSeconds()));
	}
	auto text = sf::Text(str, *(Textures::instance().get_font()));
	text.setPosition(sf::Vector2f(10, m_map.get_height() * TEXTURE_SIZE + 5));
	window.draw(text);
}

//---------------------------------------------
sf::Vector2f* Game::get_dig_points() {
	sf::Vector2f* p = m_player->dig(m_map);
	if (p != NULL) {
		Well* well = new Well;
		p->x = int(p->x / TEXTURE_SIZE);
		p->y = int(p->y / TEXTURE_SIZE);
		p->x *= TEXTURE_SIZE;
		p->y *= TEXTURE_SIZE;
		m_map.set_object(O_Well, *p);
		well->setPosition(*p);
		m_wells.push_back(well);
		if (m_currWell == -1) { m_currWell++; }
	}
	return p;
}

//---------------------------------------------
void Game::fillWell() {
	if (m_currWell > -1 && m_currWell < m_wells.size() &&
		m_wells[m_currWell]->stillWell(m_map)) {
		sf::Vector2f p(*m_wells[m_currWell]->getPosition());
		get_out_well(p);
		m_map.set_object(O_Wall, p);
		delete m_wells[m_currWell];
		m_currWell++;
	}
}

//---------------------------------------------
void Game::get_out_well(sf::Vector2f& p) {
	sf::Vector2f leftP(p.x - TEXTURE_SIZE, p.y),
		rightP(p.x + TEXTURE_SIZE, p.y),
		playerP, enemyP;
	//we creat the right points for enemy
	playerP.x = int(m_player->get_position().x) / TEXTURE_SIZE;
	playerP.y = int(m_player->get_position().y) / TEXTURE_SIZE;
	playerP.x *= TEXTURE_SIZE;
	playerP.y *= TEXTURE_SIZE;
	if (playerP == p) {
		//we check if its the same points
		if (m_map.get_type((p.y - TEXTURE_SIZE) / TEXTURE_SIZE,
			rightP.x / TEXTURE_SIZE) != O_Wall
			&& m_map.get_type(rightP) == O_Wall) {
			m_player->set_position({ rightP.x, p.y - TEXTURE_SIZE });
		}
		else{
			m_player->set_position({ leftP.x, p.y - TEXTURE_SIZE });
		}
	}
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		//we creat the right points for enemy
		enemyP.x = int(m_enemies[enemy]->get_position().x) / TEXTURE_SIZE;
		enemyP.y = int(m_enemies[enemy]->get_position().y) / TEXTURE_SIZE;
		enemyP.x *= TEXTURE_SIZE;
		enemyP.y *= TEXTURE_SIZE;
		//we check if its the same points
		if (enemyP == p) {
			if (m_map.get_type({ rightP.x, p.y - TEXTURE_SIZE }) != O_Wall
				&& m_map.get_type(rightP) == O_Wall) {
				m_enemies[enemy]->set_position({ rightP.x, p.y - TEXTURE_SIZE });
			}
			else {
				m_enemies[enemy]->set_position({ leftP.x, p.y - TEXTURE_SIZE });
			}
		}
	}
}