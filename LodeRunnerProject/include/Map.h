#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "macros.h"
#include "StaticObject.h"

class Map {
public:
	Map();
	Map(int, int, sf::Texture* textures[]);
	//----------------------------------
	ObjectType get_type(const sf::Vector2f&) const;
	void readFromStream(std::ifstream&, sf::Texture* []);
	void draw(sf::RenderWindow&) const;
	void set_object(ObjectType, const sf::Vector2f&, sf::Texture* textures[]);
	//ObjectType get_object_type(const sf::Vector2f& location) const;
	ObjectType charToType(char) const;
	int getWidth() const;
	int getHeight() const;
	char typeToChar(ObjectType) const;

private:
	size_t m_height,
		m_width;
	std::vector<std::vector<WorldObject>> m_map;
};