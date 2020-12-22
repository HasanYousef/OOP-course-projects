#pragma once

#include "WorldObject.h"

//-------------------------------------------------
//this is the constructor that we save the type
//and the textare and the possistion of object
WorldObject::WorldObject(ObjectType type,
	sf::Texture *texture,
	const sf::Vector2f &position) :
	m_objectType(type), m_texture(texture), m_position(position) {}

//-------------------------------------------------
//this func draw the object
void WorldObject::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

//-------------------------------------------------
//this operator = that let us copy another object
 WorldObject& WorldObject::operator=(const WorldObject& other) {
	m_objectType = other.m_objectType;
	m_texture = other.m_texture;
	m_position = other.m_position;
	return *this;
}

 //-------------------------------------------------
 //here we check if we pressed on the object or not
bool WorldObject::handleClick(const sf::Vector2f& location)
{
	return create().getGlobalBounds().contains(location);
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite WorldObject::create() const {
	auto result = sf::Sprite(*m_texture);
	result.setPosition(m_position);
	return result;
}

//-------------------------------------------------
//we get the type of the object(player,enemy....)
ObjectType WorldObject::getType() const {
	return m_objectType;
}