#include "macros.h"
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"

class IsoscelesTriangle {
public:
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(const Vertex& v0, const Vertex& v1, double height);
	Vertex getVertex(int index) const;
	double getBaseLength()  const;
	double getLegLength()const;
	double getHeight() const;


	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Vertex _point1;
	Vertex _point2;
	Vertex _point3;
	void Isoscelestriangledefault();
};