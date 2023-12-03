// Chapter 12 Drill
//
// Created by R J Baldwin 29/03/2023

/*
* The drill is the graphical equivalent to the �Hello, World!� program. Its purpose is to get you acquainted with the simplest
graphical output tools.
1. Get an empty Simple_window with the size 600 by 400 and a label My window compiled, linked, and run. Note that
you have to link the FLTK library as described in Appendix D; #include Graph.h and Simple_window.h in your
code; and include Graph.cpp and Window.cpp in your project.
2. Now add the examples from �12.7 one by one, testing between each added subsection example.
3. Go through and make one minor change (e.g., in color, in location, or in number of points) to each of the subsection
examples.
*/

#include <iostream>
#include "Graph.h"
#include "Simple_window.h"
#include <stdexcept>

int main()
try
{
	using namespace Graph_lib;

	Point tl{ 50,50 };
	Simple_window win{ tl,1920,1080,"My window compiled!" };

	Axis xa{ Axis::x,Point{30,500},280,10,"x axis" };	//make an axis
	Axis ya{ Axis::y,Point{30,500},280,10,"y axis" };	//make an axis
	xa.set_color(Color::black);
	ya.set_color(Color::cyan);
	xa.label.set_color(Color::dark_blue);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.attach(xa);		// attach xa to the window, win
	
	Graph_lib::Polygon poly;
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });

	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash,4));
	win.attach(poly);
	

	Function sine{ sin,0,100,Point{20,150},1000,50,50 };	// sine curve
	sine.set_color(Color::black);
	win.attach(sine);

	Graph_lib::Rectangle r{ Point{200,200},100,50 };
	r.set_fill_color(Color::yellow);
	win.attach(r);



	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 50,75 });
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);


	Text t{ Point{150,50},"Wanjo Pop!" };
	t.set_color(Color::black);
	t.set_font(Font::times_bold);
	t.set_font_size(50);
	win.attach(t);

	Image ii{ Point{100,100},"image.jpg" };
	ii.move(500, 200);
	win.attach(ii);

	Circle c{ Point{100,200},50 };
	Graph_lib::Ellipse e{ Point{100,200},75,25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{100,200},'x' };

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes{ Point{100,20},oss.str() };

	Image cal{ Point{1225,225},"ls01.jpg" };
	cal.set_mask(Point{ 400,400 }, 1500, 1500);
	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();		// display


}
catch (exception& e) {
	cerr << "Bastard!";
	return 1;
}
catch (...) {
	cerr << "Kurwa!";
	return 2;
}