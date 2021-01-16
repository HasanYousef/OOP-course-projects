#pragma once

#include "Map.h"

Map::Map() :m_height(0), m_width(0) {}

//-----------------------------------------------
//we use this func when the user press the clear
//botton and we read from it a height and width to
//creat new window and the window will be empty
Map::Map(int height, int width) {
	m_height = height;
	m_width = width;
	std::vector<std::vector<WorldObject>> newBoard;
	for (int row = 0; row <= m_height; row++) {
		std::vector<WorldObject> tempRow;
		//creating a line of objects
		for (int col = 0; col <= m_width; col++) {
			tempRow.push_back(WorldObject(ObjectType::O_Space,
				sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE)));
		}
		newBoard.push_back(tempRow);
	}
	m_map = newBoard;
}

//-----------------------------------------------
//here the constructor that we use it if we have 
//a board file we open the file and do stream 
//and we read tha map from the file and print 
//on the window the map to
void Map::readFromStream(std::ifstream& stream) {
	int row = 0,
		col = 0;
	std::vector<std::vector<WorldObject>> newBoard;
	ObjectType type;
	char ch;
	//reading the map's chars line by line
	ch = stream.get();
	while (true) {
		std::vector<WorldObject> tempRow;
		col = 0;
		while (ch != '\n' && !stream.eof()) {
			type = charToType(ch);
			//adding the object according to the char in the file
			if (type != O_Player && type != O_Enemy) {
				tempRow.push_back(WorldObject(
					type,
					sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE)
				));
			}
			col++;
			ch = stream.get();
		}
		// inserting the objects vector to the local member
		newBoard.push_back(tempRow);
		if (stream.eof())
			break;
		row++;
		ch = stream.get();
	}
	//setting the board to the local member
	m_map = newBoard;
	m_height = m_map.size();
	m_width = (m_height > 0 ? m_map[0].size() : 0);
}

//-----------------------------------------------
//this func move on every elment on the array and
//print the elment to present it on the window 
void Map::draw(sf::RenderWindow& window) const {
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			m_map[row][col].draw(window);
}

//-----------------------------------------------
//we use this when we want to print the array
//we chech the char in the array and return the 
//type on ObjectType
ObjectType Map::charToType(char ch) const {
	switch (ch) {
	case SPACE:
		return ObjectType::O_Space;
	case WALL:
		return ObjectType::O_Wall;
	case LADDER:
		return ObjectType::O_Ladder;
	case ROPE:
		return ObjectType::O_Rope;
	case MONEY:
		return ObjectType::O_Money;
	case PLAYER:
		return ObjectType::O_Player;
	case ENEMY:
		return ObjectType::O_Enemy;
	}
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
	case ObjectType::O_Money:
		return MONEY;
	case ObjectType::O_Player:
		return PLAYER;
	case ObjectType::O_Enemy:
		return ENEMY;
	}
}

//-----------------------------------------------
ObjectType Map::get_type(const sf::Vector2f& points) const {
	return m_map[points.y/TEXTURE_SIZE][points.x/ TEXTURE_SIZE].getType();
}

//-----------------------------------------------
int Map::getHeight() const {
	return m_height;
}

//-----------------------------------------------
int Map::getWidth() const {
	return m_width;
}

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
				if (m_map[row][col].getType() == ObjectType::O_Player) {
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
}

