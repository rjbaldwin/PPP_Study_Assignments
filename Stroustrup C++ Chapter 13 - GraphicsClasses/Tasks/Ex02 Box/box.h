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
    sides.add(Point{ p.x + r,p.y }, Point{ p.x + w - r, p.y }); //top side
    sides.add(Point{ p.x + r,p.y + h }, Point{ p.x + w - r,p.y + h }); //bottom side
    sides.add(Point{ p.x,p.y + r }, Point{ p.x,p.y + h - r }); //left side
    sides.add(Point{ p.x + w,p.y + r }, Point{ p.x + w,p.y + h - r }); //right side

    corners.push_back(new RobArc{ Point {p.x + r,p.y + r}, r, 90,180 }); //top left
    corners.push_back(new RobArc{ Point {p.x + w - r,p.y + r}, r, 0,90 }); //top right
    corners.push_back(new RobArc{ Point {p.x + r,p.y + h - r}, r, 180,270 }); //bottom left
    corners.push_back(new RobArc{ Point {p.x + w - r,p.y + h - r}, r, 270,360 }); //bottom right

};



// definition for draw_lines

void Box::draw_lines() const
{
    for (int i = 0; i < corners.size(); ++i)
        corners[i].draw_lines();

    sides.draw_lines();
}