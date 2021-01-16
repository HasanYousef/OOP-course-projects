#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

sf::Texture* Textures::get_texture(ObjectType textureIndex) const {
	return m_textures[textureIndex];
}

Textures::Textures() { 
	//initing the textures object in the array member
	for (int i = 0; i < m_textures.size(); i++)
		m_textures[i] = new sf::Texture();

	(*m_textures[ObjectType::O_Space]).loadFromFile("space.png");
	(*m_textures[ObjectType::O_Wall]).loadFromFile("wall.png");
	(*m_textures[ObjectType::O_Ladder]).loadFromFile("ladder.png");
	(*m_textures[ObjectType::O_Rope]).loadFromFile("rope.png");
	(*m_textures[ObjectType::O_Coin]).loadFromFile("coin.png");
	(*m_textures[ObjectType::O_Gift]).loadFromFile("gift.png");
	(*m_textures[ObjectType::O_Player]).loadFromFile("player.png");
	(*m_textures[ObjectType::O_Enemy]).loadFromFile("enemy.png");
}