#pragma once

#include "Player.h"

//-------------------------------------------------
Player::Player() : m_health(INIT_HEALTH) {}

//-------------------------------------------------
Player::Player(ObjectType type, sf::Texture* t,
	                      const sf::Vector2f& p)
	              : MoveableObject(type, t, p) {}

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
			create().move(0, -SPEED);
			m_position.y -= SPEED;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (if_can_move(map, 'D')) {
			create().move(0, SPEED);
			m_position.y += SPEED;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (if_can_move(map, 'L')) {
			create().move(-SPEED, 0);
			m_position.x -= SPEED;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (if_can_move(map, 'R')) {
			create().move(SPEED, 0);
			m_position.x += SPEED;
		}
	}
}

//-------------------------------------------------
//we use this bool func in move player func in this
//func check if the player can go to the place that 
//he want if yes we return true else we return false
bool Player::if_can_move(const Map& map, char way) {
	sf::Vector2f points(get_position());
	//check if we can not go to the way we want
	switch (way) {
	case 'U': //UP
		points.y -= SPEED;
		if (map.get_type(points) != O_Ladder)
		{ return false; }
		break;
	case 'D': //DOWN
		points.y += SPEED;
		if (map.get_type(points) == O_Wall)
		{ return false; }
		break;
	case 'L': //LEFT
		points.x -= SPEED;
		if (map.get_type(points) == O_Wall)
		{ return false; }
		break;
	case 'R': //RIGHT
		points.x += SPEED;
		if (map.get_type(points) == O_Wall)
		{ return false; }
		break;
	}
	return true; //true if we can go
}
