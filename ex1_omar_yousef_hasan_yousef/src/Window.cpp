#include "Window.h"

//------------------------------------------------------------------------
//here we have a outer and inner Rectangle we check if this two Rectangle
//are valued and make the condition if yes we save it in the private
//Rectangles if no we set the defulte values
Window::Window(const Rectangle& outer, const Rectangle& inner) {
	setRectangles(outer, inner);
}

//-----------------------------------------------------------------------------------------------
//here we have the outer Rectangle and the vertical Thick and horizontal Thick that we can find
//the innert Rectangle by this info we ceck if the verticalThickness  horizontalThickness and 
//the Rectangle are vaued if yes we save it in privat Rectangle if no we set defulte Rectangle
Window::Window(const Rectangle& outer, double verticalThickness, double horizontalThickness) {
	m_outer = outer;
	m_inner = Rectangle(
		Vertex(
			outer.getBottomLeft().m_col + horizontalThickness,
			outer.getBottomLeft().m_row + verticalThickness
		),
		Vertex(
			outer.getTopRight().m_col - horizontalThickness,
			outer.getTopRight().m_row - verticalThickness
		)
	);
}

//-------------------------------------------------------
//we return the BottomLeft point og the outer Rectangle
Vertex Window::getBottomLeft() const {
	return m_outer.getBottomLeft();
}

//----------------------------------------------------------
//we return the TopRight point og the outer Rectangle
Vertex Window::getTopRight() const {
	return m_outer.getTopRight();
}

//--------------------------------------------
//we return the VerticalThickness of window
double Window::getVerticalThickness() const {
	return m_outer.getTopRight().m_row - m_inner.getTopRight().m_row;
}

//-----------------------------------------------
//we return the HorizontalThickness of window
double Window::getHorizontalThickness() const {
	return m_outer.getTopRight().m_col - m_inner.getTopRight().m_col;
}

//-----------------------------------
//here we print the window by use the
//drawline that in the board class
void Window::draw(Board& board) const {
	m_outer.draw(board);
	m_inner.draw(board);
}

//---------------------------------------------------
//here we get the Rectangle that surround the window
Rectangle Window::getBoundingRectangle() const {
	return m_outer;
}

//-----------------------------------
//we return the area of the window
double Window::getArea() const {
	return m_outer.getArea();
}

//--------------------------------------
//we return the Perimeter of the window
double Window::getPerimeter() const {
	return m_outer.getPerimeter();
}

//-----------------------------------
//we returne the center point
Vertex Window::getCenter() const {
	return m_outer.getCenter();
}

//----------------------------------------------------
//here we have a factor, we will change the size
//of the window according to the factor, we check
//if the new point that we find it to the new window
//are valued so we draw it and return trueif no we 
//return false and print the defulte values
bool Window::scale(double factor) {
	Rectangle tempOuter = m_outer;
	Rectangle tempInner = m_inner;
	if (m_outer.scale(factor) && m_inner.scale(factor))
		return true;
	m_outer = tempOuter;
	m_inner = tempInner;
	return false;
}

//-----------------------------------------------------------------------------
//here we take the inner and outer Rectangle and we check if him are valued
//and make the conditions if yes we save it in the private info if no we
//set the defulte value of the private
void Window::setRectangles(const Rectangle& outer, const Rectangle& inner) {
	if(sameCol(outer.getCenter(), inner.getCenter()) &&
		sameRow(outer.getCenter(), inner.getCenter())) {
		m_outer = outer;
		m_inner = inner;
	}
	else {  //defulte value
		m_inner = m_outer = Rectangle(
			Vertex(DEF_BOTTOM_LEFT_COL, DEF_BOTTOM_LEFT_ROW), 
			Vertex(DEF_TOP_RIGHT_COL, DEF_TOP_RIGHT_ROW)
		);
	}
}
