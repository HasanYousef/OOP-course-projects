#pragma once

#include "Rectangle.h";

//----------------------------------------------------------------------
//this func take the bottomLeft and the topRight points and check if
//this points are valued if yes we save it in private points if no
//we set the private points on the default values
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) {
	setVartexes(bottomLeft, topRight);
}

//----------------------------------------------
//this func read a array that have two points 
//point of bottomLeft and point of topRight
//and check if this points are valued if yes 
//we save it in private points if no set
//the private points on the default values
Rectangle::Rectangle(const Vertex verticles[2]) {
	setVartexes(verticles[0], verticles[1]);
}

//-----------------------------------------------------------------
//this func read 4 points (x and y) ffwo of them to the bottomLeft
//and the other two points to topRight after that we check if this 
//points are valued if yes we save it in private points if no set
//the private points on the default values
Rectangle::Rectangle(double x0, double y0, double x1, double y1) {
	Vertex bottomLeft(x0, y0);  //point of bottomLeft
	Vertex topRight(x1, y1);  //point of topRight
	setVartexes(bottomLeft, topRight);
}

//----------------------------------------------------------------------
//this func take the center point of the Rectangle , the width and the
//height, by this info we can conclude the bottomLeft point and the
//topRight point by a simple equation after that we check if
//this points are valued if yes we save it in private points if no
//we set the private points on the default values
Rectangle::Rectangle(const Vertex& center, double width, double height) {
	Vertex bottomLeft(center.m_col - width / 2, center.m_row - height / 2);
	Vertex topRight(center.m_col + width / 2, center.m_row + height / 2);
	setVartexes(bottomLeft, topRight);
}

//---------------------------------------
//this fnc return the BottomLeft point
Vertex Rectangle::getBottomLeft() const {
	return m_bottomLeft;
}

//------------------------------------
//this fnc return the TopRight point
Vertex Rectangle::getTopRight() const {
	return m_topRight;
}

//--------------------------------------------
//this func return the Width of the Rectangle
double Rectangle::getWidth() const {
	return m_topRight.m_col - m_bottomLeft.m_col;
}

//---------------------------------------------
//this func return the Height of the Rectangle
double Rectangle::getHeight() const {
	return m_topRight.m_row - m_bottomLeft.m_row;
}

//----------------------------------------
//this func draw the Rectangle by using a
//drawline func from the board class
void Rectangle::draw(Board& board) const {
	Vertex topLeft(m_bottomLeft.m_col, m_topRight.m_row);
	Vertex bottomRight(m_topRight.m_col, m_bottomLeft.m_row);
	board.drawLine(topLeft, m_bottomLeft);		// left edge
	board.drawLine(m_bottomLeft, bottomRight);	// bottom edge
	board.drawLine(bottomRight, m_topRight);	// right edge
	board.drawLine(m_topRight, topLeft);		// top edge
}

//-----------------------------------------------------
//this func return the points of the Rectangle that
//surround the Rectangle and we get the same Rectangle
Rectangle Rectangle::getBoundingRectangle() const {
	return *this;
}

//----------------------------------
//this func return the area of the
//Rectangle we use a simple equation
//to conclude the area
double Rectangle::getArea() const {
	return (this->getWidth() * this->getHeight());
}

//--------------------------------------
//this func return the Perimeter of the
//Rectangle by simple equation
double Rectangle::getPerimeter() const {
	return (this->getWidth() * 2) + (this->getHeight() * 2);
}

//-----------------------------------
//this func return the center point
Vertex Rectangle::getCenter() const {
	return Vertex(
		m_bottomLeft.m_col + (m_topRight.m_col - m_bottomLeft.m_col) / 2,
		m_bottomLeft.m_row + (m_topRight.m_row - m_bottomLeft.m_row) / 2
	);
}

//------------------------------------------
//here we have a factor this factor will 
//effect in the size of the Rectangle we
//do this by using the center point that 
//we make a func to return it after we 
//change the size of the Rectangle we
//check if the the new points are valueds
//if yes we return true if no we return
//false and set the points on defulte
bool Rectangle::scale(double factor) {
	Vertex currBottomLeft(m_bottomLeft);
	Vertex currTopRight(m_topRight);
	Vertex center = getCenter();
	double height = getHeight() * factor;
	double width = getWidth() * factor;
	//we find the new points of the new Rectangle
	m_bottomLeft.m_col = center.m_col - width / 2;
	m_bottomLeft.m_row = center.m_row - height / 2;
	m_topRight.m_col = center.m_col + width / 2;
	m_topRight.m_row = center.m_row + height / 2;
	//we check if the new points are valued
	if (setVartexes(Vertex(m_bottomLeft.m_col, m_bottomLeft.m_row), Vertex(m_topRight.m_col, m_topRight.m_row))) {
		return true;
	}
	else {
		setVartexes(currBottomLeft, currTopRight);
		return false;
	}
}

//---------------------------------------------------------------------------
//this bool func take the points of the Rectangle (bottomLeft and topRight)
//and check if the points are valued if yes we save the values in the private 
//points and return trueif no we return false to put the default values
bool Rectangle::setVartexes(const Vertex& bottomLeft, const Vertex& topRight) {
	if (bottomLeft.isValid() && topRight.isValid() &&
		topRight.isToTheRightOf(bottomLeft) && topRight.isHigherThan(bottomLeft)) {
		m_bottomLeft = bottomLeft;
		m_topRight = topRight;
		return true;
	}
	//if the points not valued
	else {
		m_bottomLeft = Vertex(DEF_REC_BOTTOM_COL, DEF_REC_BOTTOM_ROW);
		m_topRight = Vertex(DEF_REC_TOP_COL, DEF_REC_TOP_ROW);
		return false;
	}
}
