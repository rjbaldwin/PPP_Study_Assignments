// Created by robert J Baldwin 30/03/2023

/*


7. Draw a two-dimensional house seen from the front, the way a child would: with a door, two windows, and a roof with a
chimney. Feel free to add details; maybe have �smoke� come out of the chimney.
8. Draw the Olympic five rings. If you can�t remember the colors, look them up.
9. Display an image on the screen, e.g., a photo of a friend. Label the image both with a title on the window and with a
caption in the window.
10. Draw the file diagram from �12.8.
11. Draw a series of regular polygons, one inside the other. The innermost should be an equilateral triangle, enclosed by a
square, enclosed by a pentagon, etc. For the mathematically adept only: let all the points of each N-polygon touch sides
of the (N+1)-polygon. Hint: The trigonometric functions are found in <cmath> (�24.8, �B.9.2).
12. A superellipse is a two-dimensional shape defined by the equation
Look up superellipse on the web to get a better idea of what such shapes look like. Write a program that draws �starlike�
patterns by connecting points on a superellipse. Take a, b, m, n, and N as arguments. Select N points on the superellipse
defined by a, b, m, and n. Make the points equally spaced for some definition of �equal.� Connect each of those N
points to one or more other points (if you like you can make the number of points to which to connect a point another
argument or just use N�1, i.e., all the other points).
13. Find a way to add color to the lines from the previous exercise. Make some lines one color and other lines another color
or other colors.*/





#include "Graph.h"
#include "Simple_window.h"

int main()
try
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 1920, 1080, "My window");



	
	//================================TASK 05=============================================
	// 5. Draw a red � - inch frame around a rectangle that is three - quarters the height of your screen and two - thirds the width.
	// screen size = 1920 x 1080 therefore 1280 x 810
	// assuming 1 inch = 96px, therefore 24 px frame width of size 1280+24 x 810 +24 therefore 1304 x 834


	Graph_lib::Rectangle task4{ Point{100,100},1280,810 };
	task4.set_fill_color(Color::white);
	task4.set_color(Color::white);
	
	win.attach(task4);


	Graph_lib::Rectangle frame{ Point{88,88},1304,834 };
	
	frame.set_color(Color::red);
	frame.set_style(Line_style(Line_style::solid, 24));
	win.attach(frame);


	//================================TASK 06=============================================
	//6. What happens when you draw a Shape that doesn�t fit inside its window? What happens when you draw a Window
	// that doesn�t fit on your screen ? Write two programs that illustrate these two phenomena.

	// the shape will be drawn off screen.  Resizing the screen will expose the rest of the shape

	/*Graph_lib::Rectangle big{ Point{100,100},2560,1440 };
	big.set_fill_color(Color::green);
	big.set_color(Color::white);

	win.attach(big);*/

	// the window size adjusts to the screen size

	/*Point t2(20, 20);
	Simple_window win2(t2, 5000, 10000, "My window2");*/

	//================================TASK 07=============================================
	// 7. Draw a two-dimensional house seen from the front, the way a child would: with a door, two windows, and a roof with a
	// chimney.Feel free to add details; maybe have �smoke� come out of the chimney.

	






	win.set_label("Chapter 12 Tasks");
	win.wait_for_button();
}
catch (exception& e) {
	cerr << "Odchody";
	return 1;
}
catch (...) {
	cerr << "Stolec!";
	return 2;
}