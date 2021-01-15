#pragma once

#include "Money.h"

//---------------------------------------------
Money::Money() : m_isTaken(false) {}

//---------------------------------------------
Money::Money(ObjectType type,
	const sf::Vector2f& position) :
	StaticObject(type, position),
	m_isTaken(false) {}

//---------------------------------------------
