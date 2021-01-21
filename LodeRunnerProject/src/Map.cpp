#pragma once

#include "Map.h"

Map::Map() :m_height(0), m_width(0) {}

//-----------------------------------------------
//we use this func when the user press the clear
//botton and we read from it a height and width to
//creat new window and the window will be empty
Map::Map(int height, int width, int time)
{
	init(height, width, time);
}

//-----------------------------------------------
Map::~Map() {
	deleteObjects();
}

//-----------------------------------------------
void Map::deleteObjects() {
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			delete m_map[row][col];
	m_height = 0;
	m_width = 0;
}

//-----------------------------------------------
int Map::load_map(int level, int leftMargin) {
	// deletes the old map if exists
	deleteObjects();
	m_map.clear();
	std::string str = "C:board";
	str += std::to_string(level);
	str += ".txt";
	fs::path p = str;
	std::ifstream ifile(fs::absolute(p));
	int time = read_from_stream(ifile, leftMargin);
	ifile.close();
	return time;
}

//-----------------------------------------------
//here the constructor that we use it if we have 
//a board file we open the file and do stream 
//and we read tha map from the file and print 
//on the window the map to
int Map::read_from_stream(std::ifstream& stream, int leftMarging) {
	stream >> m_height;
	stream >> m_width;
	stream >> m_time;
	char ch;
	//reading the map's chars line by line
	m_map.resize(m_height);
	for (int row = 0; row < m_height; row++) {
		//jumping over the new line char
		stream.get();
		for (int col = 0; col < m_width; col++) {
			m_map[row].push_back(new WorldObject);
			m_map[row][col]->set_position(sf::Vector2f(col * TEXTURE_SIZE + leftMarging, row * TEXTURE_SIZE));
			m_map[row][col]->setType(char_to_type(stream.get()));
		}
	}
	return m_time;
}

//-----------------------------------------------
//this func move on every elment on the array and
//print the elment to present it on the window 
void Map::draw(sf::RenderWindow& window, bool showMoveableObjects) {
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++) {
			ObjectType type = m_map[row][col]->get_type();
			if (showMoveableObjects || type != ObjectType::O_Player && type != ObjectType::O_Enemy)
				m_map[row][col]->draw(window);
		}
}

//-----------------------------------------------
//we use this when we want to print the array
//we chech the char in the array and return the 
//type on ObjectType
ObjectType Map::char_to_type(char ch) const {
	switch (ch) {
	case SPACE:
		return ObjectType::O_Space;
	case WALL:
		return ObjectType::O_Wall;
	case LADDER:
		return ObjectType::O_Ladder;
	case ROPE:
		return ObjectType::O_Rope;
	case COIN:
		return ObjectType::O_Coin;
	case GIFT:
		return ObjectType::O_Gift;
	case PLAYER:
		return ObjectType::O_Player;
	case ENEMY:
		return ObjectType::O_Enemy;
	}
}

//-----------------------------------------------
//take the type and return the char of type
char Map::type_to_char(ObjectType type) const {
	switch (type) {
	case ObjectType::O_Wall:
		return WALL;
	case ObjectType::O_Ladder:
		return LADDER;
	case ObjectType::O_Rope:
		return ROPE;
	case ObjectType::O_Coin:
		return COIN;
	case ObjectType::O_Gift:
		return GIFT;
	case ObjectType::O_Player:
		return PLAYER;
	case ObjectType::O_Enemy:
		return ENEMY;
	}
	return O_Space;
}

//-----------------------------------------------
ObjectType Map::get_type(int row,int col) const {
	return m_map[row][col]->get_type();
}

//-----------------------------------------------
int Map::get_height() const {
	return m_height;
}

//-----------------------------------------------
int Map::get_width() const {
	return m_width;
}

/*
//----------------------------------------------------------------------------------------------
//this func take from the editor the possistion of the mouse 
//and the type that the user choose to add it and the textures
//array to pute the texture that we want to print it
void Map::set_object(ObjectType type, const sf::Vector2f& location, sf::Texture* textures[]) {
	int newCol = int(location.x - BOARD_UI_X) / TEXTURE_SIZE;
	int newRow = int(location.y) / TEXTURE_SIZE;
	int xPos = ((int(location.x) - BOARD_UI_X) / TEXTURE_SIZE) * TEXTURE_SIZE + BOARD_UI_X;
	int yPos = (int(location.y) / TEXTURE_SIZE) * TEXTURE_SIZE;

	if (type == ObjectType::O_Player) {
		//check if the player already exists in the map
		for (int row = 0; row < m_height; row++) {
			for (int col = 0; col < m_width; col++) {
				if (m_map[row][col].get_type() == ObjectType::O_Player) {
					m_map[row][col] = WorldObject(ObjectType::O_Space,
						sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE));
					break;
				}
			}
		}
	}
	//check if the position is inside the board range
	if (newRow < m_height && newCol < m_width)
		m_map[newRow][newCol] = WorldObject(type, sf::Vector2f(xPos, yPos));
}*/

//-----------------------------------------------
void Map::set_object(ObjectType type, const sf::Vector2f& location) {
	*m_map[location.y / TEXTURE_SIZE][location.x / TEXTURE_SIZE] =
		WorldObject(type, location);
}

//-----------------------------------------------
void Map::setObjectWithMargin(ObjectType type, const sf::Vector2f& location, int leftMargin) {
	int col = (location.x - leftMargin) / TEXTURE_SIZE,
		row = location.y / TEXTURE_SIZE;
	if(row < m_height && col < m_width)
		*m_map[row][col] = WorldObject(type, location);
}

//-----------------------------------------------
ObjectType Map::get_type(const sf::Vector2f& points) const {
	return m_map[points.y / TEXTURE_SIZE][points.x / TEXTURE_SIZE]->get_type();
}

void Map::init(int height, int width, int time) {
	deleteObjects();
	m_height = height;
	m_width = width;
	m_time = time;
	m_map.resize(m_height);

	for (int row = 0; row < m_height; row++) {
		//creating a line of objects
		for (int col = 0; col < m_width; col++) {
			m_map[row].push_back(new WorldObject);
			m_map[row][col]->setType(ObjectType::O_Space);
			m_map[row][col]->set_position(
				sf::Vector2f(col * TEXTURE_SIZE + BUTTON_WIDTH + 10, row * TEXTURE_SIZE)
			);
		}
	}
}

//-----------------------------------------------
//save the board (print the object on the board file)
void Map::save(int level) const {
	std::string str = "C:board";
	str += std::to_string(level);
	str += ".txt";
	fs::path p = str;
	std::ofstream ofile(fs::absolute(p));
	ofile << m_height << " " << m_width << " " << m_time << '\n';
	//writing the chars the represent each object 
	for (int row = 0; row < m_height; row++) {
		for (int col = 0; col < m_width; col++) {
			ofile.put(typeToChar(m_map[row][col]->get_type()));
		}
		if (row != m_height - 1)
			ofile.put('\n');
	}
	ofile.close();
}

//-----------------------------------------------
//take the type and return the char of type
char Map::typeToChar(ObjectType type) const {
	switch (type) {
	case ObjectType::O_Space:
		return SPACE;
	case ObjectType::O_Wall:
		return WALL;
	case ObjectType::O_Ladder:
		return LADDER;
	case ObjectType::O_Rope:
		return ROPE;
	case ObjectType::O_Coin:
		return COIN;
	case ObjectType::O_Gift:
		return GIFT;
	case ObjectType::O_Player:
		return PLAYER;
	case ObjectType::O_Enemy:
		return ENEMY;
	}
}