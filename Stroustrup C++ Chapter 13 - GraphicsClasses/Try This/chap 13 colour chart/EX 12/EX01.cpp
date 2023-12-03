

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;






int main()
{
	 Point begin{ 10,10 };

	 Simple_window win1{ begin,800	,600,"polyline" };
	//===================================================================

	 Graph_lib::Vector_ref<Graph_lib::Rectangle> rect;

	 Graph_lib::Rectangle x{ Point{100,200},Point{200,300} };
	 rect.push_back(x);

	 rect.push_back(new Graph_lib::Rectangle{ Point{50,60},Point{80,90} });

	 for (int i = 0; i < rect.size(); ++i)
		 rect[i].move(10, 10); 
	

	 Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;
	 for (int i = 0; i < 16; ++i)
		 for (int j = 0; j < 16; ++j) {
			 vr.push_back(new Graph_lib::Rectangle{ Point{i * 20,j * 20},20,20 });
			 vr[vr.size()-1].set_fill_color(Color{ i * 16 + j });
			 win1.attach(vr[vr.size()-1]);
		 }



	 win1.wait_for_button();

}
