// Created by robert J Baldwin 30/03/2023

/*
We recommend that you use Simple_window for these exercises.
1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle
blue.
2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
3. Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
5. Draw a red ¼-inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.
6. What happens when you draw a Shape that doesn’t fit inside its window? What happens when you draw a Window
that doesn’t fit on your screen? Write two programs that illustrate these two phenomena.
7. Draw a two-dimensional house seen from the front, the way a child would: with a door, two windows, and a roof with a
chimney. Feel free to add details; maybe have “smoke” come out of the chimney.8. Draw the Olympic five rings. If you can’t remember the colors, look them up.
9. Display an image on the screen, e.g., a photo of a friend. Label the image both with a title on the window and with a
caption in the window.
10. Draw the file diagram from §12.8.
11. Draw a series of regular polygons, one inside the other. The innermost should be an equilateral triangle, enclosed by a
square, enclosed by a pentagon, etc. For the mathematically adept only: let all the points of each N-polygon touch sides
of the (N+1)-polygon. Hint: The trigonometric functions are found in <cmath> (§24.8, §B.9.2).
12. A superellipse is a two-dimensional shape defined by the equation
Look up superellipse on the web to get a better idea of what such shapes look like. Write a program that draws “starlike”
patterns by connecting points on a superellipse. Take a, b, m, n, and N as arguments. Select N points on the superellipse
defined by a, b, m, and n. Make the points equally spaced for some definition of “equal.” Connect each of those N
points to one or more other points (if you like you can make the number of points to which to connect a point another
argument or just use N–1, i.e., all the other points).
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

	//================================TASK 01=============================================
	// 1. Draw a rectangle as a Rectangle and as a Polygon. 
	// Make the lines of the Polygon red and the lines of the Rectangle blue.
	// 
	// rectangle properties
	Graph_lib::Rectangle r{ Point{200,200},100,30 };
	r.set_color(Color::blue);		// sets the line colour to blue

	win.attach(r);

	// Polygon rectangle
	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,30 });
	poly_rect.add(Point{ 200,30 });
	poly_rect.add(Point{ 200,60 });
	poly_rect.add(Point{ 100,60 });
	poly_rect.set_color(Color::red);

	win.attach(poly_rect);

	//================================TASK 02=============================================
	// 2. Draw a 100 - by - 30 Rectangle and place the text “Howdy!” inside it.
	
	// rectangle properties
	Graph_lib::Rectangle r2{ Point{120,120},100,30 };
	r2.set_color(Color::black);		// sets the line colour to black
	Text t{ Point{125,140},"Howdy doody!" };
	t.set_color(Color::black);
	win.attach(t);
	win.attach(r2);


	//================================TASK 03=============================================
	// 3. Draw your initials 150 pixels high. Use a thick line. 
	// Draw each initial in a different color.

	// CANT BE ARSED WITH THIS AS I WOULD USE FONTS INSTEAD OF LINES FOR INITIALS.  I MAY REVIST

	//================================TASK 04=============================================
	// 4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.

	//====row 1====
	Graph_lib::Rectangle s1{ Point{200,300},100,100 };
	s1.set_fill_color(Color::white);
	s1.set_color(Color::white);
	win.attach(s1);

	Graph_lib::Rectangle s2{ Point{300,300},100,100 };
	s2.set_fill_color(Color::red);
	s2.set_color(Color::red);
	win.attach(s2);

	Graph_lib::Rectangle s3{ Point{400,300},100,100 };
	s3.set_fill_color(Color::white);
	s3.set_color(Color::white);
	win.attach(s3);
	//====row 2====
	Graph_lib::Rectangle s4{ Point{200,400},100,100 };
	s4.set_fill_color(Color::red);
	s4.set_color(Color::red);
	win.attach(s4);

	Graph_lib::Rectangle s5{ Point{300,400},100,100 };
	s5.set_fill_color(Color::white);
	s5.set_color(Color::white);
	win.attach(s5);

	Graph_lib::Rectangle s6{ Point{400,400},100,100 };
	s6.set_fill_color(Color::red);
	s6.set_color(Color::red);
	win.attach(s6);
	//====row 3====
	Graph_lib::Rectangle s7{ Point{200,500},100,100 };
	s7.set_fill_color(Color::white);
	s7.set_color(Color::white);
	win.attach(s7);

	Graph_lib::Rectangle s8{ Point{300,500},100,100 };
	s8.set_fill_color(Color::red);
	s8.set_color(Color::red);
	win.attach(s8);

	Graph_lib::Rectangle s9{ Point{400,500},100,100 };
	s9.set_fill_color(Color::white);
	s9.set_color(Color::white);
	win.attach(s9);

	//************************Continued in a new project**********************************
	//================================TASK 05=============================================
	// 5. Draw a red ¼ - inch frame around a rectangle that is three - quarters the height of your screen and two - thirds the width.


	Graph_lib::Rectangle task4{ Point{1000,500},500,500 };
	task4.set_fill_color(Color::white);
	task4.set_color(Color::white);
	win.attach(task4);





	win.set_label("Chapter 12 Tasks");
	win.wait_for_button();
}
catch (exception& e) {
	cerr << "Twat";
	return 1;
}
catch (...) {
	cerr << "Fuck you!";
	return 2;
}