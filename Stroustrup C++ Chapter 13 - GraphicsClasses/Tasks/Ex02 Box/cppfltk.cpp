/*
2. Draw a box with rounded corners. Define a class Box, consisting of four lines and four arcs.
*/

// created by Robert J Baldwin 13/04/2023

#include "Graph.h"
#include "Simple_window.h"
#include "box.h"

using namespace Graph_lib;



//===== Definitions are in Graph.cpp, Declarations are in Graph.h ======================

//======================================================================================

int main()
{
	Simple_window win{ Point{1,1},1920,1080,"My Window" };


    Box b1{ Point{10, 10}, 350, 350, 40 };
    b1.set_color(Color::yellow);
    win.attach(b1);

   
	

	gui_main();
	// win.wait_for_button();


}