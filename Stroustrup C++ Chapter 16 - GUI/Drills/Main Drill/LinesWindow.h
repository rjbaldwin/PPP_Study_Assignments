#pragma once


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
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }

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
