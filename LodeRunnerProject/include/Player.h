#pragma once

#include "macros.h"
#include "Map.h"
#include "SFML/Graphics.hpp"
#include <MoveableObject.h>

class Player : public MoveableObject {
public:
	//---Constructors---------------------
	Player();
	Player(ObjectType, const sf::Vector2f&);
	//---functions--------------
	void move(const Map&);
	sf::Vector2f* dig(Map&);
	void die();
	void set_health(int);
	bool getCoin(const Map&);
	bool getGift(const Map&);
	//---get-functions----------
	int get_health() const;
	int get_score() const;
	//---add-functions----------
	void add_health(int);
	void add_score(int);
	//bool getGift(const Map&);
private:
	int m_health = INIT_HEALTH;
	int m_score = 0;
};
