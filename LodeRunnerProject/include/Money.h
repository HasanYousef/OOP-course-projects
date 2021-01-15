#pragma once

#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Money : StaticObject {
public:
	Money();
	Money(ObjectType, const sf::Vector2f&);
private:
	bool m_isTaken = false;
};