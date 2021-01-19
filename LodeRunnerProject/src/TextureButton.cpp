#pragma once

#include "TextureButton.h"

//------------------------------------------------------
//this a copy constructor
void TextureButton::draw(sf::RenderWindow& window) const {
	window.draw(create());
	
	ObjectType type = optionToObjectType();
	auto result = sf::Sprite(*(Textures::instance().get_texture(type)));
	result.setPosition({ m_position.x + 40, m_position.y + 8 });
	window.draw(result);
}

ObjectType TextureButton::optionToObjectType() const {
	switch (m_option)
	{
	case UserOption::AddSpace:
		return ObjectType::O_Space;
	case UserOption::AddWall:
		return ObjectType::O_Wall;
	case UserOption::AddLadder:
		return ObjectType::O_Ladder;
	case UserOption::AddRope:
		return ObjectType::O_Rope;
	case UserOption::AddCoin:
		return ObjectType::O_Coin;
	case UserOption::AddGift:
		return ObjectType::O_Gift;
	case UserOption::AddPlayer:
		return ObjectType::O_Player;
	case UserOption::AddEnemy:
		return ObjectType::O_Enemy;
	default:
		return ObjectType::O_Space;
	}
}