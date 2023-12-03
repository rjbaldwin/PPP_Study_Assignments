/*
1. Make an 800-by-1000 Simple_window.
2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).
3. Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).
4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it on the grid (each image covering four
squares). If you can’t find an image that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of a larger
image. Don’t obscure the red squares.
5. Add a 100-by-100 image. Have it move around from square to square when you click the “Next” button. Just put
wait_for_button() in a loop with some code that picks a new square for your image.*/

// created by Robert J Baldwin 04/04/2023

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;



int main()
{
	 Point begin{ 1,1 };

	 Simple_window win{ begin,800,1000,"Drill 01 cuntus maximus" };
	//===================================================================

	 int x_size = 800;
	 int y_size = 800;
	 int x_grid = 100;
	 int y_grid = 100;

	 //=========Plots the lines of the grid==============================
	 Lines grid;
	 for (int x = x_grid; x <= x_size; x += x_grid)
		 grid.add(Point{ x,0 }, Point{ x,y_size });

	 for (int y = y_grid; y <= y_size; y += y_grid)
		 grid.add(Point{ 0,y }, Point{ x_size,y });

	 grid.set_color(Color::black);
	 win.attach(grid);

	 //=========Plots the 8 red squares==================================

	 Vector_ref<Graph_lib::Rectangle> vr;

	 for (int i = 0; i < 8; ++i)
	 {
		 vr.push_back(new Graph_lib::Rectangle(Point(i * 100, i * 100), 101, 101));
		 vr[vr.size()-1 ].set_fill_color(Color::red);
		 win.attach(vr[vr.size() - 1]);
	 }
	 //=========Attach a 200x200 image and place 3 times=================

	 Image db{ Point{201,0},"db.jpg" };
	 Image db2{ Point{501,0},"db.jpg" };
	 Image db3{ Point{201,501},"db.jpg" };
	 win.attach(db);
	 win.attach(db2);
	 win.attach(db3);

	 //=========Attach a 100x100 image===================================

	 Image hist{ Point{101,301},"hist.jpg" };
	 win.attach(hist);

	 win.wait_for_button();

	 //=====not my code.  I didnt know how to do this====================
	 for (int i = 0; i < 8; ++i) {
		 for (int j = 0; j < 8; ++j) {
			 hist.move(100, 0);
			 win.wait_for_button();
		 }
		 hist.move(-700, 100);         
		 win.wait_for_button();
	 }

}            
