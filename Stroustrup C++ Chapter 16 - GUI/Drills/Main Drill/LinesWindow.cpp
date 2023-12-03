#include "Window.h"
#include "Graph.h"
#include "LinesWindow.h"
#include "GUI.h"

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

	color_menu{ Point{x_max() - 70,30},70,20,Menu::vertical,"colour" },

	menu_button{ Point{x_max() - 80,30},80,20,"Color Menu",cb_menu },

	lineStyleMenu{ Point{x_max() - 180,30},80,20,Menu::vertical, "Line Style" },

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
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();

}

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//