#pragma once

#include <vector>
#include <fstream>
#include <iostream>

#include "macros.h"
#include "WorldObject.h"

class Board {
public:
	Board();
	Board(int, int, sf::Texture* []);
	void readFromStream(std::ifstream&, sf::Texture* []);
	void setNew(int, int, sf::Texture* []);
	void draw(sf::RenderWindow&) const;
	void set_object(ObjectType, const sf::Vector2f&, sf::Texture* []);
	ObjectType charToType(char) const;
	void save() const {}

private:
	size_t m_height = 0,
		m_width = 0;
	std::vector<std::vector<WorldObject>> m_worldObjects;
};