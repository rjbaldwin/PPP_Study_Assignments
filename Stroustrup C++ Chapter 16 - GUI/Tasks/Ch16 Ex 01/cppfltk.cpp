
// simple window chapter 16.3
// created by Robert J Baldwin 24/04/2023

#include "Graph.h"
#include "Simple_window.h"
#include "GUI.h"

using namespace Graph_lib;

//--------------------------------------------------------------------//
//-------------Class Definition---------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

struct QuitWindow :Window
{
	QuitWindow(Point xy, int w, int h, const string& title);


private:
	// widgets
	Button quit_button;
	Button next_button;
	// the actions invoked by callbacks:
	void quit();
	void next();

	// callback functions
	static void cb_quit(Address, Address);	
	static void cb_next(Address, Address);
};


//--------------------------------------------------------------------//
//-----------Class Constructor----------------------------------------//
//--------------------------------------------------------------------//

QuitWindow::QuitWindow(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	
	quit_button{ Point{x_max() - 70,0}, 70, 20, "Quit",cb_quit },
	next_button{Point{x_max() -142,0},70,20, "Next",cb_next}

{	
	attach(quit_button);	
	attach(next_button);
}


//--------------------------------------------------------------------//
//-----------Member function implementation---------------------------//
//--------------------------------------------------------------------//


void QuitWindow::quit()
{
	hide();	// curious FLTK idiom to delete window
}


void QuitWindow::cb_quit(Address, Address pw)
{
	reference_to<QuitWindow>(pw).quit();
}


void QuitWindow::next()
{
	hide();
}

void QuitWindow::cb_next(Address, Address pw)
{
	reference_to<QuitWindow>(pw).quit();
}





//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

int main()
try {
	QuitWindow win{ Point{100,100},600,400,"lines" };

	return gui_main();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}