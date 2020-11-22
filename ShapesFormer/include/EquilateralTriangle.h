#pragma once

#include "Vertex.h"
#include "Utilities.h"
#include "Rectangle.h"
#include "Consts.h"
#include <cmath>

//the m_row Class
class EquilateralTriangle {
//the public section in class
public:
	//all the constructors that  we need
	EquilateralTriangle(const Vertex vertices[3]);
	Vertex getVertex(int index) const;
	double getLength() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const ;
	double getArea() const;
	Vertex getCenter() const;
	double getPerimeter() const;
	double scale(double factor);	
//the private section in class
private:
	//bool func that check if the point are valued
	bool setVertex(const Vertex& p1, const Vertex& p2, const Vertex& p3);
	//array of the points of the EquilateralTriangle
	struct Vertex m_vertices[3];
	void setDefulte();
	void setVertexesvalues(Vertex v0, Vertex v1, Vertex v2);
};