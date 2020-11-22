#include "EquilateralTriangle.h";
#include "Utilities.h"
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "cmath"

//-----------------------------------------------------------------
//this func take the points of the EquilateralTriangle and check
//if the points are vaild 
EquilateralTriangle::EquilateralTriangle(const Vertex vertices[3])
{
	setVertex(vertices[0], vertices[1], vertices[2]);
}

//---------------------------------------------------------------------------------------
//this bool func check if the points of the c are valued or not if no
//we set the defult points and return false else we return true and save the points
bool EquilateralTriangle::setVertex(const Vertex& p1, const Vertex& p2, const Vertex& p3)
{
	//we check if they valued
	if (p1.isValid() && p2.isValid() && p3.isValid() && sameRow(p1, p2))
	{   //we check if its a Equilateral Triangle
		if ((doubleEqual((distance(p1, p2) - distance(p2, p3)), 0)) &&
			 (doubleEqual(distance(p1, p2) - distance(p1, p3), 0)))
		{
			//save the new values in the private points
			setVertexesvalues(p1, p2, p3);
			return true;
		}
	}
	//the default values
	setDefulte();
	return false;
}

//---------------------------------------------------
// we return the vertex point of the point we chose
Vertex EquilateralTriangle::getVertex(int index) const
{
	return m_vertices[index];
}

//--------------------------------------------------
//we return the length of the Equilateral Triangle
double EquilateralTriangle::getLength() const
{
	return distance(m_vertices[0], m_vertices[1]);
}

//--------------------------------------------------
//this func draw the Equilateral Triangle by using
//the drawLine func in bourd class
void EquilateralTriangle::draw(Board& board) const
{   //we print all the lines of the Triangle
	board.drawLine(m_vertices[1], m_vertices[0]);
	board.drawLine(m_vertices[2], m_vertices[1]);
	board.drawLine(m_vertices[2], m_vertices[0]);
}

//-------------------------------------------------------------
//this func print a Rectangle surround the EquilateralTriangle
Rectangle EquilateralTriangle::getBoundingRectangle() const
{
	struct Vertex v1, v2;
	//we give the values to new Vertexs
	v1.m_col = m_vertices[0].m_col;
	v1.m_row = m_vertices[0].m_row;
	v2.m_col = m_vertices[1].m_col;
	v2.m_row = m_vertices[2].m_row;
	//we return the two points of Rectangle
	return Rectangle(v1,v2);
}

//--------------------------------------------------
//this func return the area of the EquilateralTriangle
//by using a Equation to  Considered the area 
double EquilateralTriangle::getArea() const
{
	double height = m_vertices[2].m_row - m_vertices[0].m_row;
	double area = (height * distance(m_vertices[0], m_vertices[1])) / 2;
	return area;
}

//----------------------------------------------
//this func return the center point of the 
//EquilateralTriangle by simple Equation
Vertex EquilateralTriangle::getCenter() const
{
	struct Vertex Center_Point;
	Center_Point.m_row = ((m_vertices[2].m_row + m_vertices[0].m_row) / 2);
	Center_Point.m_col = ((m_vertices[1].m_col + m_vertices[0].m_col) / 2);
	return Center_Point;
}

//--------------------------------------------------
//this func Considere the Perimeter of the
//EquilateralTriangle by simple Equation
double EquilateralTriangle::getPerimeter() const
{
	return(distance(m_vertices[0], m_vertices[1]) + distance(m_vertices[0], m_vertices[2])
		+ distance(m_vertices[1], m_vertices[2]));
}

//-------------------------------------------------------
//this func take a factor this facter is the change
//that we want to make it in the size of the Equilateral
//Triangle we do this by get help in center point that
//we did it the func return true if the points still valued
//after the change if no we returne false
double EquilateralTriangle::scale(double factor)
{
	double newhight = (m_vertices[2].m_row - m_vertices[0].m_row) * factor;
	double newside = distance(m_vertices[0], m_vertices[1]) * factor;
	struct Vertex center = getCenter();
	//we check if the points are valued
	if (setVertex(
		Vertex(center.m_col - (newside / 2), center.m_row - (newhight / 2)),
		Vertex(center.m_col + (newside / 2), center.m_row - (newhight / 2)),
		Vertex(center.m_col, center.m_row + (newhight / 2))))
	{
		return true;
	}
	//default points
	setDefulte();
	return false;
}

//-----------------------------------------------------------------------
//this func set the new valued on the vertexs that we have in privet
//after we checked its valued and fix we code this func to get rid of
//double code
void EquilateralTriangle::setVertexesvalues(Vertex v0, Vertex v1, Vertex v2) {
	m_vertices[0].m_col = v0.m_col;
	m_vertices[0].m_row = v0.m_row;
	m_vertices[1].m_col = v1.m_col;;
	m_vertices[1].m_row = v1.m_row;;
	m_vertices[2].m_col = v2.m_col;
	m_vertices[2].m_row = v2.m_row;
}

//------------------------------------------------------------------------
//here we set the defulte values
void EquilateralTriangle::setDefulte()
{
	m_vertices[0].m_col = DEF_BOTTOM_LEFT_COL;
	m_vertices[0].m_row = DEF_BOTTOM_LEFT_ROW;
	m_vertices[1].m_col = DEF_BOTTOM_RIGHT_COL;
	m_vertices[1].m_row = DEF_BOTTOM_RIGHT_ROW;
	m_vertices[2].m_col = DEF_TOP_COL;
	m_vertices[2].m_row = DEF_TOP_ROW;
}