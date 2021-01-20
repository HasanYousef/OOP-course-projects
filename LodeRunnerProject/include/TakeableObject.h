#pragma once 

#include "WorldObject.h"

class TakeableObject : public WorldObject {
public:
	TakeableObject();
	TakeableObject(ObjectType, const sf::Vector2f&);
	bool isTaken() const;
	void getTaken();
private:
	bool m_isTaken = false;
};