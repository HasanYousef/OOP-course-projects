#pragma once 

#include "TakeableObject.h"

class coin : public TakeableObject {
public:
	coin() : TakeableObject() {}
	coin(ObjectType t, const sf::Vector2f& p)
		: TakeableObject(t, p) {}
};