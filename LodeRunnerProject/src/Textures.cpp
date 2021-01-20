#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

sf::Texture* Textures::get_texture(ObjectType textureIndex) const {
	return m_textures[textureIndex];
}

sf::Font* Textures::get_font() const {
	return m_font;
}

Textures::Textures() { 
	// initing the textures object in the array member
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_textures[i] = new sf::Texture;
	m_font = new sf::Font;
	// load the textures from the files
	(*m_textures[ObjectType::O_Space]).loadFromFile("space.png");
	(*m_textures[ObjectType::O_Wall]).loadFromFile("wall.png");
	(*m_textures[ObjectType::O_Ladder]).loadFromFile("ladder.png");
	(*m_textures[ObjectType::O_Rope]).loadFromFile("rope.png");
	(*m_textures[ObjectType::O_Coin]).loadFromFile("coin.png");
	(*m_textures[ObjectType::O_Gift]).loadFromFile("gift.png");
	(*m_textures[ObjectType::O_Player]).loadFromFile("player.png");
	(*m_textures[ObjectType::O_Enemy]).loadFromFile("enemy.png");
	(*m_textures[ObjectType::O_Well]).loadFromFile("space.png");
	// load the font
	(*m_font).loadFromFile(FONT_PATH);
}