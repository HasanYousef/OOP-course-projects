#pragma once

#include "Map.h"

Map::Map() :m_height(0), m_width(0) {}

//-----------------------------------------------
//here the constructor that we use it if we have 
//a board file we open the file and do stream 
//and we read tha map from the file and print 
//on the window the map to
void Map::readFromStream(std::ifstream& stream, sf::Texture* textures[]) {
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
			tempRow.push_back(WorldObject(
				type,
				textures[type],
				sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE)
			));
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
	m_worldObjects = newBoard;
	m_height = m_worldObjects.size();
	m_width = (m_height > 0 ? m_worldObjects[0].size() : 0);
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
//
ObjectType Map::get_object_type(const sf::Vector2f& location) const {
	
}