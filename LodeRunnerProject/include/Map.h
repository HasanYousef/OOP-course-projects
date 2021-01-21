#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
#include "TakeableObject.h"
#include "macros.h"
#include "WorldObject.h"

class Map {
public:
	Map();
	Map(int, int, int);
	~Map();
	//----------------------------------
	void deleteObjects();
	ObjectType get_type(int, int) const;
	ObjectType get_type(const sf::Vector2f& ) const;
	int load_map(int, int);
	int read_from_stream(std::ifstream&, int);
	void draw(sf::RenderWindow&, bool);
	void set_object(ObjectType, const sf::Vector2f&);
	void setObjectWithMargin(ObjectType, const sf::Vector2f&, int);
	//void set_object(ObjectType, const sf::Vector2f&, sf::Texture* textures[]);
	//ObjectType get_object_type(const sf::Vector2f& location) const;
	ObjectType char_to_type(char) const;
	int get_width() const;
	int get_height() const;
	char type_to_char(ObjectType) const;
	void init(int, int, int);
	void save(int) const;
	char typeToChar(ObjectType) const;
	Map& operator=(const Map&);

private:
	size_t m_height,
		m_width;
	int m_time;
	std::vector<std::vector<WorldObject*>> m_map;
};