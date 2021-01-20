#pragma once 

#include "TakeableObject.h"

class Gift : public TakeableObject {
public:
	Gift() : TakeableObject() {}
	Gift(ObjectType t, const sf::Vector2f& p)
		: TakeableObject(t, p) {}
};