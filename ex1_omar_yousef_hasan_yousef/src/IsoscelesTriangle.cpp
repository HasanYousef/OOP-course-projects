	#pragma once

#include "IsoscelesTriangle.h"

//--------------------------------------------------------------------------
//here we have a arry that have the three points of the Isosceles Triangle
//we check if the points a valued if yes we save it in the private points
//if no we set the defult points 
IsoscelesTriangle::IsoscelesTriangle(const Vertex verticles[3]) {
	if (isValidVartexes(verticles[0], verticles[1], verticles[2]))
		setVertexes(verticles[0], verticles[1], verticles[2]);
	else { //set defult values
		setVertexes(
			Vertex(DEF_BOTTOM_LEFT_COL, DEF_BOTTOM_RIGHT_ROW), 
			Vertex(DEF_BOTTOM_RIGHT_COL, DEF_BOTTOM_RIGHT_ROW), 
			Vertex(DEF_TOP_COL, DEF_TOP_ROW)
		);
	}
}

//----------------------------------------------------------------------------------------
//here we have a points of the base and we have the height of the Isosceles Triangle by 
//simple equation we find the third point after that we check if the points a valued if 
//yes we save it in the private points if no we set the defult points 
IsoscelesTriangle::IsoscelesTriangle(const Vertex& v0, const Vertex& v1, double height) {
	Vertex top( //find thits point
		v1.m_col - distance(v0, v1) / 2,
		v1.m_row + height
	); //chek if valued
	if (isValidVartexes(v0, v1, top)) {
		setVertexes(v0, v1, top);
	}
	else { //set defulte
		setVertexes(
			Vertex(DEF_BOTTOM_LEFT_COL, DEF_BOTTOM_RIGHT_ROW),
			Vertex(DEF_BOTTOM_RIGHT_COL, DEF_BOTTOM_RIGHT_ROW),
			Vertex(DEF_TOP_COL, DEF_TOP_ROW)
		);
	}
}

//-----------------------------------------------------------------
//here we get the point from the array by give it the index number
Vertex IsoscelesTriangle::getVertex(int index) const {
	if (index == 0)
		return m_bottomLeft;
	if (index == 0)
		return m_bottomRight;
	return m_top;
}

//------------------------------------------------
//we returne the base length of the tringle
double IsoscelesTriangle::getBaseLength() const {
	return distance(m_bottomLeft, m_bottomRight);
}

//------------------------------------------------
//we return the leg length
double IsoscelesTriangle::getLegLength() const {
	return distance(m_bottomLeft, m_top);
}

//------------------------------------------------
//we return the hight of the tringle
double IsoscelesTriangle::getHeight() const {
	double height = m_top.m_row - m_bottomLeft.m_row;
	return height >= 0 ? height : -height;
}

//------------------------------------------------------
//here we draw the Isosceles Triangle by using drawline
// that in the board class
void IsoscelesTriangle::draw(Board& board) const {
	board.drawLine(m_bottomLeft, m_bottomRight);	// base edge
	board.drawLine(m_top, m_bottomLeft);			// left edge
	board.drawLine(m_top, m_bottomRight);			// right edge
}

//-----------------------------------------------------------
//here we found and draw the Rectangle that surround the 
//Isosceles Triangle with the condition we want
Rectangle IsoscelesTriangle::getBoundingRectangle() const {
	return Rectangle(m_bottomLeft, Vertex(m_bottomRight.m_col, m_top.m_row));
}

//-----------------------------------------------------
//here we calculate the area of the Isosceles Triangle
double IsoscelesTriangle::getArea() const {
	return distance(m_bottomLeft, m_bottomRight) * distance(this->getCenter(), m_top);
}

//-----------------------------------------------------
//we calculate the Perimeter of the Isosceles Triangle
double IsoscelesTriangle::getPerimeter() const {
	return (
		distance(m_bottomLeft, m_bottomRight) +
		distance(m_bottomRight, m_top) + 
		distance(m_top, m_bottomLeft)
	);
}

//------------------------------------------------
//we reeturn the center point
Vertex IsoscelesTriangle::getCenter() const {
	return Vertex(m_top.m_col, m_top.m_row - (m_top.m_row - m_bottomLeft.m_row)/2);
}

//-------------------------------------------------------------
//here we change the size of the Isosceles Triangle according
//to the factor that we have before we change the size we check
//if the new points are valued and return true if no we return 
//false and set the defulte values 
bool IsoscelesTriangle::scale(double factor) {
	double halfNewHeight = distance(m_top, getCenter()) * factor;
	Vertex v0(getCenter().m_col - distance(m_bottomLeft, m_bottomRight) * factor / 2,
			getCenter().m_row - halfNewHeight),
		v1(getCenter().m_col + distance(m_bottomLeft, m_bottomRight) * factor / 2,
			getCenter().m_row - halfNewHeight),
		v2(m_top.m_col, halfNewHeight + getCenter().m_row);
	if (isValidVartexes(v0, v1, v2)) {
		setVertexes(v0, v1, v2);
		return true;
	}
	setVertexes(
		Vertex(DEF_BOTTOM_LEFT_COL, DEF_BOTTOM_RIGHT_ROW),
		Vertex(DEF_BOTTOM_RIGHT_COL, DEF_BOTTOM_RIGHT_ROW),
		Vertex(DEF_TOP_COL, DEF_TOP_ROW)
	);
	return false;
}

// private functions
//-------------------------------------------------------------------------
//here we chek if the points of the Isosceles Triangle are valued or not
bool IsoscelesTriangle::isValidVartexes(Vertex v0, Vertex v1, Vertex v2) {
	return (
		v0.isValid() &&
		v1.isValid() &&
		v2.isValid() &&
		sameRow(v0, v1) &&
		doubleEqual(distance(v0, v2), distance(v1, v2))
	);
}

//---------------------------------------------------------------------
//here we take three points of the Isosceles Triangle and put the 
//values of the private points
void IsoscelesTriangle::setVertexes(Vertex v0, Vertex v1, Vertex v2) {
	m_bottomLeft.m_col = v0.m_col;
	m_bottomLeft.m_row = v0.m_row;
	m_bottomRight.m_col = v1.m_col;;
	m_bottomRight.m_row = v1.m_row;;
	m_top.m_col = v2.m_col;
	m_top.m_row = v2.m_row;
}