#pragma once

#include "Player.h"

//-------------------------------------------------
Player::Player() :
	m_health(INIT_HEALTH)
{}

//-------------------------------------------------
Player::Player(ObjectType type, const sf::Vector2f& p)
	              : MoveableObject(type, p) {}

//-------------------------------------------------
int Player::get_score() const {
	return m_score;
}

//-------------------------------------------------
//here we return the helth number of the Player
int Player::get_health() const {
	return m_health;
}

//-------------------------------------------------
//here we sub 1 from the helth of the player when 
//the player get damged from a enemy
void Player::die() {
	m_health -= 1;
}

//-------------------------------------------------
void Player::set_health(int currHealth) {
	m_health = currHealth;
}

//-------------------------------------------------
//give the player more health when get a gift
void Player::add_health(int more_health) {
	m_health += more_health;
}

//-------------------------------------------------
//add the score when the player get a coin
void Player::add_score(int more_score) {
	m_score += more_score;
}

//-------------------------------------------------
//this func move the player we get input from the 
//user we check if the input is arrows and check if
//we can go to the way that the user want if yes we 
//move it and set the new points else still same points
void Player::move(const Map& map) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (if_can_move(map, 'U')) {
			m_position.y -= SPEED;
			get_on_floor(map);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (if_can_move(map, 'D')) {
			m_position.y += SPEED;
			get_on_floor(map);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (if_can_move(map, 'L')) {
			m_position.x -= SPEED;
			get_on_floor(map);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (if_can_move(map, 'R')) {
			m_position.x += SPEED;
			get_on_floor(map);
		}
	}
}

//-------------------------------------------------
bool Player::getCoin(const Map& map) {
	return (map.get_type(m_position) == O_Coin);
}

//-------------------------------------------------
bool Player::getGift(const Map& map) {
	return (map.get_type(m_position.x / TEXTURE_SIZE, m_position.y / TEXTURE_SIZE) == O_Gift);
}

