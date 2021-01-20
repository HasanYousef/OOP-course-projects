#pragma once

#include "TakeableObject.h"

//-------------------------------------------------
TakeableObject::TakeableObject() : WorldObject() {}

//-------------------------------------------------
TakeableObject::TakeableObject(ObjectType t,
	const sf::Vector2f& p) : WorldObject(t, p) {}

//-------------------------------------------------
bool TakeableObject::isTaken() const {
	return m_isTaken;
}

//-------------------------------------------------
void TakeableObject::getTaken() {
	m_isTaken = true;
}