

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;





int main()
{
	 Point begin{ 10,10 };

	 Simple_window win1{ begin,800	,600,"polyline" };
	//===================================================================

	 Graph_lib::Rectangle rect00{ Point{150,100},200,100 };
	 rect00.set_fill_color(Color::yellow);
	 win1.attach(rect00);

	 Graph_lib::Rectangle rect11{ Point{50,50},Point{250,150} };
	 rect11.set_fill_color(Color::blue);
	 rect11.move(400, 0);
	 rect11.set_fill_color(Color::white);

	 win1.attach(rect11);

	 Graph_lib::Rectangle rect12{ Point{50,150},Point{250,250} };
	 rect12.set_fill_color(Color::red);
	 win1.attach(rect12);

	 Graph_lib::Rectangle rect21{ Point{250,50},200,100 };
	 rect21.set_fill_color(Color::green);
	 win1.attach(rect21);

	 Graph_lib::Rectangle rect22{ Point{250,150},200,100 };
	
	 win1.attach(rect22);
	 win1.set_label("Rectangles 2");
	
	 win1.put_on_top(rect00);

	 rect00.set_color(Color::invisible);
	 rect11.set_color(Color::invisible);
	 rect12.set_color(Color::invisible);
	 rect21.set_color(Color::invisible);
	 rect22.set_color(Color::invisible);

	 win1.wait_for_button();

}
