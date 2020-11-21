#pragma once
#include "Board.h"

//-----------------structor-----------------
//the structor of the board will read from it first
//the size of the map that it gonna be read, then it will
//read all the map's chars line by line and store them
Board::Board(ifstream mapStream) {
	//reading the size of the map that is gonna be read
	mapStream >> m_size;
	//readin the map's chars line by line
	for (int row = 0; row < m_size; row++) {
		for (int col = 0; col < m_size; col++)
			mapStream.get(m_map[row][col]);
	}
}

//-----------------print-----------------
//prints all the map in the console
void Board::print() {
	//printing the map line by line
	for (int row = 0; row < m_size; row++) {
		for (int col = 0; col < m_size; col++)
			cout << m_map[row][col];
	}
}

//-----------------get_char-----------------
//it takes a column and row indexes as integers and returns
//what char exists in the board with the same given indexes
char Board::get_char(int col, int row) {
	//if one of the given indexes is out of the board return wall char
	if (col < 0 || col >= m_size || row < 0 || row >= m_size)
		return WALL;
	return m_map[col][row];
}
