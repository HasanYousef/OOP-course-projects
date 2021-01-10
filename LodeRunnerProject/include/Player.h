#pragma once

#include <iostream>
#include "macros.h"
#include "Map.h"
#include "SFML/Graphics.hpp"
#include <MoveableObject.h>

class Player : public MoveableObject {
public:
	//---Constructors---------------------
	Player();
	Player(ObjectType , sf::Texture*,
		          const sf::Vector2f&);
	//---functions--------------
	void move(const Map&);
	void die();
	void set_health(int);
	//---get-functions----------
	int get_health() const;
	int get_score() const;
	//---add-functions----------
	void add_health(int);
	void add_score(int);
private:
	int m_health = INIT_HEALTH;
	int m_score = 0;
	//---help-functions-------------------
	bool if_can_move(const Map&, char);
};
