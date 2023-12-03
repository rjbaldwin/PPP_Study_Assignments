/*
* For each �define a class� exercise, display a couple of objects of the class to demonstrate that they work.
1. Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().

*/

// created by Robert J Baldwin 11/04/2023

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;



//===== Definitions are in Graph.cpp, Declarations are in Graph.h ======================

//======================================================================================

int main()
{
	Simple_window win{ Point{1,1},1920,1080,"My Window" };

	RobArc arc{ Point{50,50},50, 20,180 };
	arc.set_color(Color::red);

	win.attach(arc);


	gui_main();
	// win.wait_for_button();


}