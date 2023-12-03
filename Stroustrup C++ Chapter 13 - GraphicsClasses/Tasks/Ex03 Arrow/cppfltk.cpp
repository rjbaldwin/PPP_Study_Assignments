#include "Graph.h"
#include "Simple_window.h"
#include <math.h>



#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Arrow : public Shape {
public:
	Arrow(Point tail, Point head);
	void draw_lines() const;
private:
	Point m_tail;
	Point m_head;
};

Arrow::Arrow(Point tail, Point head)
	: m_tail{ tail }, m_head{ head }
{
	// The arrow object only consists of two points, so we can simply call add() twice. 
	add(tail);
	add(head);
}

void Arrow::draw_lines() const
{
	// Draw a line from the tail to the head.
	fl_line(m_tail.x, m_tail.y, m_head.x, m_head.y);
	
	// Determine the angle between the line and the x-axis.
	double arrowAngle = atan2(m_head.y - m_tail.y, m_head.x - m_tail.x);

	// Draw the arrowhead.
	double length{50};	// arrowhead length
	double headDegrees{ 30 };	// the angle of the arrowheads

	Point arrow1(m_head.x - int(length * cos(arrowAngle +  (headDegrees * M_PI/180))),
		m_head.y - int(length * sin(arrowAngle + (headDegrees * M_PI / 180))));
	Point arrow2(m_head.x - int(length * cos(arrowAngle - (headDegrees * M_PI / 180))),
		m_head.y - int(length * sin(arrowAngle - (headDegrees * M_PI / 180))));
	fl_line(m_head.x, m_head.y, arrow1.x, arrow1.y);
	fl_line(m_head.x, m_head.y, arrow2.x, arrow2.y);
}






//=== Class definition for RobArc

struct RobArc : Shape
{
	RobArc(Point aPoint, int rad, int angleA, int angleB);		//centre and radius

	void draw_lines() const;		// Draws line - implementation is outside of class - see below

	Point center() const;			// Established the centre of the arc/circle - implementation is outside of class - see below

	int get_radius() const			// GETTER: gets the radius value that is assigned to privateRad (Private) by user input to the constructor from rad (constructor)
	{
		return privateRad;
	}

	void set_radius(int rad)	// SETTER: sets/assigns the radius value that is assigned to rad (constructor) to privateRad (private)
	{
		set_point(0, Point{ center().x - rad,center().y - rad });
		privateRad = rad;
	}


private:
	int privateRad;
	int privateAngleA;
	int privateAngleB;
};


//=== Class Constructor definition ================================================================================================



RobArc::RobArc(Point aPoint, int rad, int angleA, int angleB)
	:privateRad{ rad },
	privateAngleA{ angleA },
	privateAngleB{ angleB }
{
	add(Point{ aPoint.x - privateRad, aPoint.y - privateRad });		// centre and radius - this centres the placememnt of the circle on the window with respect to the centre of the circle 
																	// the default FLTK point position is top left corner of bounding box. Subtracting radius from x and y lands us in the middle of the circle. 
																	// This new point is calculated by subtracting the radius from the x and y coordinates of the input point, which centers the shape on the screen.
}

//=== RobArc Function definitions =================================================================================================

void RobArc::draw_lines() const
{
	if (color().visibility())
		fl_arc(point(0).x, point(0).y, privateRad + privateRad, privateRad + privateRad, privateAngleA, privateAngleB);
}


Point RobArc::center() const
{
	return { point(0).x + privateRad, point(0).y + privateRad };	// Establishes the centre point of the arc/circle for scaling and positioning.  
																	// The initial coordinate point (0) is the top left of the binding box of the circle.  
																	// Add the radius size to the x and y from zero and this will provide the new centre coordinate point.
}



//=================================================================================
//=================================================================================
//=================================================================================




int main()
{
	using namespace Graph_lib;

	Point tl(0,0);
	Simple_window win(tl, 600, 400, "My window");

	

	Arrow arrow(Point{ 50, 50 }, Point{ 200,250 });
	arrow.set_color(Color::blue);
	win.attach(arrow);

	win.wait_for_button();



}