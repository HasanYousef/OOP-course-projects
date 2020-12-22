#pragma once

#include "Board.h"

//-----------------------------------------------
Board::Board() :
	m_height(0), m_width(0) {}

//-----------------------------------------------
//this the constructor of the board that take a 
//height and width of the window and take a pointer
//to a texturs we use in this construcor the setnew
//func to build and put a spaces in the array 
Board::Board(int height, int width, sf::Texture* textures[]) {
	setNew(height, width, textures);
}

//-----------------------------------------------
//here the constructor that we use it if we have 
//a board file we open the file and do stream 
//and we read tha map from the file and print 
//on the window the map to
void Board::readFromStream(std::ifstream& stream, sf::Texture* textures[]) {
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
void Board::draw(sf::RenderWindow& window) const {
	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			m_worldObjects[row][col].draw(window);
}

//-----------------------------------------------
//we use this func when the user press the clear
//botton and we read from it a height and width to
//creat new window and the window will be empty
void Board::setNew(int height, int width, sf::Texture* textures[]) {
	m_height = height;
	m_width = width;
	std::vector<std::vector<WorldObject>> newBoard;
	for (int row = 0; row <= m_height; row++) {
		std::vector<WorldObject> tempRow;
		//creating a line of objects
		for (int col = 0; col <= m_width; col++) {
			tempRow.push_back(WorldObject(ObjectType::Space, textures[ObjectType::Space], 
				sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE)));
		}
		newBoard.push_back(tempRow);
	}
	m_worldObjects = newBoard;
}

//----------------------------------------------------------------------------------------------
//this func take from the editor the possistion of the mouse 
//and the type that the user choose to add it and the textures
//array to pute the texture that we want to print it
void Board::set_object(ObjectType type, const sf::Vector2f& location, sf::Texture* textures[]) {
	int newCol = int(location.x - BOARD_UI_X) / TEXTURE_SIZE;
	int newRow = int(location.y) / TEXTURE_SIZE;
	int xPos = ((int(location.x) - BOARD_UI_X) / TEXTURE_SIZE) * TEXTURE_SIZE + BOARD_UI_X;
	int yPos = (int(location.y) / TEXTURE_SIZE) * TEXTURE_SIZE;

	if (type == ObjectType::Player) {
		//check if the player already exists in the map
		for (int row = 0; row < m_height; row++) {
			for (int col = 0; col < m_width; col++) {
				if (m_worldObjects[row][col].getType() == ObjectType::Player) {
					m_worldObjects[row][col] = WorldObject(ObjectType::Space, textures[ObjectType::Space],
						sf::Vector2f(col * TEXTURE_SIZE + BOARD_UI_X, row * TEXTURE_SIZE));
					break;
				}
			}
		}
	}

	//check if the position is inside the board range
	if(newRow < m_height && newCol < m_width)
		m_worldObjects[newRow][newCol] = WorldObject(type, textures[type], sf::Vector2f(xPos, yPos));
}

//-----------------------------------------------
//we use this when we want to print the array
//we chech the char in the array and return the 
//type on ObjectType
ObjectType Board::charToType(char ch) const {
	switch (ch) {
	case SPACE:
		return ObjectType::Space;
	case WALL:
		return ObjectType::Wall;
	case LADDER:
		return ObjectType::Ladder;
	case ROPE:
		return ObjectType::Rope;
	case MONEY:
		return ObjectType::Money;
	case PLAYER:
		return ObjectType::Player;
	case ENEMY:
		return ObjectType::Enemy;
	}
}

//-----------------------------------------------
//save the board (print the object on the board file)
void Board::save() const {
	//opening the output file stream
	fs::path p = "C:board.txt";
	std::ofstream ofile(fs::absolute(p));
	//writing the chars the represent each object 
	for (int row = 0; row < m_height; row++) {
		for (int col = 0; col < m_width; col++) {
			ofile.put(typeToChar(m_worldObjects[row][col].getType()));
		}
		if (row != m_height - 1)
			ofile.put('\n');
	}
	ofile.close();
}

//-----------------------------------------------
//take the type and return the char of type
char Board::typeToChar(ObjectType type) const {
	switch (type) {
	case ObjectType::Space:
		return SPACE;
	case ObjectType::Wall:
		return WALL;
	case ObjectType::Ladder:
		return LADDER;
	case ObjectType::Rope:
		return ROPE;
	case ObjectType::Money:
		return MONEY;
	case ObjectType::Player:
		return PLAYER;
	case ObjectType::Enemy:
		return ENEMY;
	}
}

//-----------------------------------------------
int Board::getHeight() const {
	return m_height;
}

//-----------------------------------------------
int Board::getWidth() const {
	return m_width;
}