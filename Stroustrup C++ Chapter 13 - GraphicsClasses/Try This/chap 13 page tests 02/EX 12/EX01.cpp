

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;







int main()
{
	 Point begin{ 1,1 };

	 Simple_window win{ begin,600,400,"cuntus maximus" };
	//===================================================================

	 Image rita{ Point{0,0},"rita.jpg" };
	 Image path{ Point{0,0},"rita_path.gif" };
	 path.set_mask(Point{ 50,250 }, 600, 400);

	 win.attach(path);
	 win.attach(rita);




	 win.wait_for_button();

}            
