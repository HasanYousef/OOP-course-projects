#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

#include "macros.h"
#include "WorldObject.h"

class Map {
public:
	Map();
	Map(int, int);
	//----------------------------------
	ObjectType get_type(int, int) const;
	ObjectType get_type(const sf::Vector2f& ) const;
	WorldObject get_object(const sf::Vector2f&);
	int read_from_stream(std::ifstream&);
	void draw(sf::RenderWindow&) const;
	void set_object(ObjectType, const sf::Vector2f&);
	//void set_object(ObjectType, const sf::Vector2f&, sf::Texture* textures[]);
	//ObjectType get_object_type(const sf::Vector2f& location) const;
	ObjectType char_to_type(char) const;
	int get_width() const;
	int get_height() const;
	char type_to_char(ObjectType) const;

private:
	size_t m_height,
		m_width;
	std::vector<std::vector<WorldObject>> m_map;
};