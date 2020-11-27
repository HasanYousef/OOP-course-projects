Shapes former and drawer
#########################################################################################

authors:
	Omar Yousef
	Hasan Yousef

about the program:
	This program is about forming and drawing 4 paticular shapes - rectangle,
	isosceles triangle, equilateral triangle and window. for each shape, the
	program reads from the user the needed coordinates to form the shape.
	
	The user should give:
		for the rectangle: the coordinates of the bottom-left and the 
		top-right points.
		for the isosceles triangle and the equilateral triangle: the 
		coordinates of the bottom-left, the bottom-right and the top points.
		for the window: the same as the triangle but for 2 triangles and
		not just one.
	
	All the points' coordinates shold be fulfill these conditions:
		0 <= x <= 70
		0 <= y <= 50
		Left points should be in the left of the right points.
		Top points should be higher than the bottom points.
		Triangle's top and bottom edges should be parallels to the x axis.
		Triangle's left and right edges should be parallels to the y axis.
		Isosceles triangle's legs' lengths should be equal.
		Isosceles triangle's base edge should be parallel to the x axis.
		All equilateral triangle's edges' lengths should be equal.
		Equilateral triangle's base edge should be parallel to the x axis.
		Window's rectangles should fulfill the previous rectangles' conditons.
		Window's inner and outer rectangles should have the same center point.

	If the inputed coordinates don't fulfill the conditions the program will give
	the default coordinates.
	
	For each shape, the program will print (draw) the shape, then it will print
	the shape with the shape's bounding rectangle, after that it will print these
	informations about the shape:
		-The coordinates of each point.
		-The length of the shape's edges.
		-The perimeter of the shape.
		-The area of the shape.
		-The coordinates of the center point of the shape.
		-The thicknes of the window.

	Then it will print the same things as above but after scaling the shape by
	the factor, the default factor is 2.

About the files:
	Rectangle.h/.cpp:
		Defines the rectangle's class, which stores the coordinates of the
		bottom-left point and the top-right point, it also defines the related
		functions.
	IsoscelesTriangle.h/.cpp:
		Defines the IsoscelesTriangle's class, which stores the coordinates of 
		the bottom-left point, the bottom-right point and the top point, it also
		defines the related functions.
	EquilateralTriangle.h/.cpp:
		Defines the EquilateralTriangle's class, which stores the coordinates of 
		the bottom-left point, the bottom-right point and the top point, it also
		defines the related functions.
	Window.h/.cpp:
		Defines the Window's class, which stores 2 rectangle objects - one is
		the outer rectangle and one is the inner rectangle. it also defines the
		related functions.

Data Structures:
        We have only one of the Data Structures, its the array of the points, in every class
        we have an array that include the points of the shape for example int the EquilateralTriangle
        there are an array of 3 index every index about point (first index for first point ....).

Notable Algorithms:
        Only one algorithm we used in scale function
        algorithm work: we multiplication the height and the width for the shape on the factor
        and we get the center point of the shape after that we add half of the new width and height
        to the point center according to the shape for example the EquilateralTriangle:
        we get the new height and width according to what we explain after that we add the half
        of the new height to the center point and sub the half of the new width to the center point
        in this way we get the first point in the EquilateralTriangle:

Bug:
        there are a bug in the Triangles that sometimes the top vertex doesn't reach the age of the 
        Bounding Rectangle another bug that sometimes we have two top vertexs not just one

Another Notes:
      