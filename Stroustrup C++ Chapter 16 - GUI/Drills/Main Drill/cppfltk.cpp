
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

struct Lines_window :Window
{
	Lines_window(Point xy, int w, int h, const string& title);
	

private:
	// data:
	Open_polyline lines;

	// widgets
	Button next_button;		// add (next_x, next_y) to lines
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	Menu lineStyleMenu;
	Button lineStyleButton;

	void change(Color c) { lines.set_color(c); }
	void hide_menu() { color_menu.hide(); menu_button.show(); }

	void hideLineMenu() { lineStyleMenu.hide(); lineStyleButton.show(); }

	// the actions invoked by callbacks:
	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue);hide_menu();}
	void black_pressed() { change(Color::black); hide_menu();}

	void solid_pressed() { lines.set_style(Line_style::solid); hideLineMenu(); }
	void dotted_pressed() { lines.set_style(Line_style::dot); hideLineMenu(); }
	void dashed_pressed() { lines.set_style(Line_style::dash); hideLineMenu(); }


	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void lineMenuPressed() { lineStyleButton.hide(); lineStyleMenu.show(); }
	void next();
	void quit();

	// callback functions
	static void cb_red(Address, Address); // callback for red button
	static void cb_blue(Address, Address); // callback for blue button
	static void cb_black(Address, Address); // callback for black button
	static void cb_menu(Address, Address);
	static void cb_LineMenu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);

	static void cb_solid(Address, Address);		// callback for solid lines
	static void cb_dotted(Address, Address);	// callback for dotted lines
	static void cb_dashed(Address, Address);	// callback for dashed lines
};






//--------------------------------------------------------------------//
//-----------Class Constructor----------------------------------------//
//--------------------------------------------------------------------//

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	next_button{ Point{x_max() - 150,0}, 70, 20, "Next point",cb_next },

	quit_button{ Point{x_max() - 70,0}, 70, 20, "Quit",cb_quit },

	next_x{ Point{x_max() - 310,0}, 50, 20, "Next x:" },

	next_y{ Point{x_max() - 210,0}, 50, 20, "Next y:" },

	xy_out{ Point{100,0}, 100, 20, "Current (x,y):" },

	color_menu{ Point{x_max()-70,30},70,20,Menu::vertical,"colour" },

	menu_button{Point{x_max()-80,30},80,20,"Color Menu",cb_menu},

	lineStyleMenu{Point{x_max()- 180,30},80,20,Menu::vertical, "Line Style"},

	lineStyleButton{ Point {x_max() - 180,30},90,20,"Line Style", cb_LineMenu }
		
	{

	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	color_menu.attach(new Button{ Point{0,0},0,0,"red",cb_red });
	color_menu.attach(new Button{ Point{0,0},0,0,"blue",cb_blue });
	color_menu.attach(new Button{ Point{0,0},0,0,"black",cb_black });
	attach(color_menu);
	color_menu.hide();
	attach(menu_button);
	attach(lines);

	lineStyleMenu.attach(new Button{ Point{0,0},0,0,"Solid", cb_solid });
	lineStyleMenu.attach(new Button{ Point{0,0},0,0,"Dotted",cb_dotted });
	lineStyleMenu.attach(new Button{ Point{0,0},0,0,"Dashed",cb_dashed });
	attach(lineStyleMenu);
	lineStyleMenu.hide();
	attach(lineStyleButton);
	}


//--------------------------------------------------------------------//
//-----------Member function implementation---------------------------//
//--------------------------------------------------------------------//


void Lines_window::quit()
{
	hide();	// curious FLTK idiom to delete window
}

void Lines_window::cb_red(Address, Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}



void Lines_window::cb_menu(Address, Address pw)
{
	reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_LineMenu(Address, Address pw)
{
	reference_to<Lines_window>(pw).lineMenuPressed();
}

void Lines_window::cb_next(Address, Address pw)
{
	reference_to<Lines_window>(pw).next();
}

void Lines_window::cb_quit(Address, Address pw)
{
	reference_to<Lines_window>(pw).quit();
}



void Lines_window::cb_solid(Address, Address pw)
{
	reference_to<Lines_window>(pw).solid_pressed();
}


void Lines_window::cb_dotted(Address, Address pw)
{
	reference_to<Lines_window>(pw).dotted_pressed();
}


void Lines_window::cb_dashed(Address, Address pw)
{
	reference_to<Lines_window>(pw).dashed_pressed();
}




void Lines_window::next()
{
	int x{ next_x.get_int() };
	int y{ next_y.get_int() };
	lines.add(Point{ x,y });

	// update current position readout:
	ostringstream ss;
	ss << '('<< x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();

}

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

int main()
try {
	Lines_window win{ Point{100,100},600,400,"lines" };
	
	return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Some exception\n";
	return 2;
}