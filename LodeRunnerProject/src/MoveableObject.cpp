
#pragma once

#include "MoveableObject.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------
MoveableObject::MoveableObject() {}

//-------------------------------------------------
MoveableObject::MoveableObject(ObjectType type,
	                       const sf::Vector2f& p)
	: WorldObject(type, p), m_originPosition(p) {}

//-------------------------------------------------
void MoveableObject::move(const Map& map) {}

//-------------------------------------------------
void MoveableObject::fall(const Map& map) {
	sf::Vector2f BLpoints(m_position.x, m_position.y + TEXTURE_SIZE - 1),
		BRpoints(m_position.x + TEXTURE_SIZE - 1, m_position.y + TEXTURE_SIZE - 1);
	BLpoints.y += 3 * SPEED;
	BRpoints.y += 3 * SPEED;
	if (map.get_type(m_position) != O_Rope &&
		map.get_type(m_position) != O_Ladder &&
		map.get_type(m_position) != O_Well &&
		map.get_type(BLpoints) != O_Wall &&
		map.get_type(BRpoints) != O_Wall) {
		m_position.y += 3 * SPEED;
	}
}

//------------------------------------------------------------
//this func check if the player on the top of the ladder
//returne false if not and true if its on last H 
bool MoveableObject::on_ladder(const Map& map, char way) {
	sf::Vector2 TRpoints(m_position.x + TEXTURE_SIZE - 1, m_position.y),
		Rpoints(m_position.x + TEXTURE_SIZE, m_position.y + TEXTURE_SIZE + (TEXTURE_SIZE / 2)),
		Lpoints(m_position.x - TEXTURE_SIZE, m_position.y + TEXTURE_SIZE + (TEXTURE_SIZE / 2));
	switch (way) {
	case 'L':
		return map.get_type(TRpoints) == O_Ladder &&
			map.get_type(Lpoints) != O_Wall &&
			map.get_type(m_position.y / TEXTURE_SIZE,
				(m_position.x - TEXTURE_SIZE) / TEXTURE_SIZE) != O_Rope;
	case 'R':
		return map.get_type(m_position) == O_Ladder
			&& map.get_type(Rpoints) != O_Wall &&
			map.get_type(m_position.y / TEXTURE_SIZE,
				Rpoints.x / TEXTURE_SIZE) != O_Rope;
	}
	return false;
}

//-------------------------------------------------
//we use this bool func in move player func in this
//func check if the player can go to the place that 
//he want if yes we return true else we return false
bool MoveableObject::if_can_move(const Map& map, char way) {
	sf::Vector2f TLpoints(m_position),
		TRpoints(m_position.x + TEXTURE_SIZE - 1, m_position.y),
		BLpoints(m_position.x, m_position.y + TEXTURE_SIZE - 1),
		BRpoints(m_position.x + TEXTURE_SIZE - 1, m_position.y + TEXTURE_SIZE - 1);
	if (map.get_type(m_position) == O_Well){
		return false;
	}
	//check if we can not go to the way we want
	switch (way) {
	case 'U': //UP
		TLpoints.y -= SPEED;
		TRpoints.y -= SPEED;
		if ((map.get_type(TLpoints) == O_Ladder ||
			map.get_type(TRpoints) == O_Ladder) &&
			map.get_type(TLpoints) != O_Wall &&
			map.get_type(TRpoints) != O_Wall) {
			if (map.get_type(m_position) == O_Ladder) {
				m_position.x = int(m_position.x / TEXTURE_SIZE);
				m_position.x *= TEXTURE_SIZE;
			}
			else {
				m_position.x += TEXTURE_SIZE;
				m_position.x = int(m_position.x / TEXTURE_SIZE);
				m_position.x *= TEXTURE_SIZE;
			}
			return true;
		}
		break;
	case 'D': //DOWN
		BLpoints.y += SPEED;
		BRpoints.y += SPEED;
		if (map.get_type(BLpoints) != O_Wall &&
			map.get_type(BRpoints) != O_Wall &&
			map.get_type(m_position) != O_Well)
		{
			return true;
		}
		break;
	case 'L': //LEFT
		TLpoints.x -= SPEED;
		BLpoints.x -= SPEED;
		if (map.get_type(TLpoints) != O_Wall &&
			map.get_type(BLpoints) != O_Wall &&
			!on_ladder(map, way))
		{
			return true;
		}
		break;
	case 'R': //RIGHT
		TRpoints.x += SPEED;
		BRpoints.x += SPEED;
		if (map.get_type(TRpoints) != O_Wall &&
			map.get_type(BRpoints) != O_Wall &&
			!on_ladder(map, way))
		{
			return true;
		}
		break;
	}
	return false; //true if we can go
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite MoveableObject::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_texture(m_objectType));
	result.setPosition(m_position);
	result.getPosition();
	return result;
}