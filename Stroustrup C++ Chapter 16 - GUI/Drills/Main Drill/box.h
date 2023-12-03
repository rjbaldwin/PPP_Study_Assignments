#pragma once
// Ex 2 - Box

struct Box : Shape {
    
    // constructor
    Box(Point p, int w, int h, int r);

    void draw_lines() const;

    
   

private:
    Vector_ref<RobArc> corners;
    Lines sides;
};

// constructor definition
Box::Box(Point p, int w, int h, int r)
{
    sides.add(Point{ p.x+w, p.x+h}, Point{ p.x+h , p.y+w }); //top side
    

  

};



// definition for draw_lines

void Box::draw_lines() const
{
    for (int i = 0; i < corners.size(); ++i)
        corners[i].draw_lines();

    sides.draw_lines();
}