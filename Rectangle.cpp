/**
 * Rectangle.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

//Default Rectangle prints nothing
Rectangle::Rectangle() {
}

Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
	//Start is set to the given point (pt1)
    start = pt1;
    //End is set to the given point (pt2)
	end = pt2;
    //The colors from all of the vertexes are set to the same color
	colorTopLeft = color;
	colorTopRight = color;
	colorBottomLeft = color;
	colorBottomRight = color;
}

Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
	Color cBottomRight, Color cBottomLeft) {
	//Start is set to the given point (pt1)
    start = pt1;
    //End is set to the given point (pt2)
	end = pt2;
    //The color in the top left vertex is set to the given color
	colorTopLeft = cTopLeft;
    //The color in the top right vertex is set to the given color
	colorTopRight = cTopRight;
    //The color in the bottom left vertex is set to the given color
	colorBottomLeft = cBottomLeft;
    //The color in the bottom right vertex is set to the given color
	colorBottomRight = cBottomRight;
}

void Rectangle::setStart(Point pt) {
	//Start is set to the given point
    start = pt;
}

Point Rectangle::getStart() {
	//The start point is returned 
    return start;
}

void Rectangle::setEnd(Point pt) {
	//End is set to the given point
    end = pt;
}

Point Rectangle::getEnd() {
	//The end point is returned
    return end;
}

void Rectangle::setColor(Color color) {
	//The colors from all of the vertexes are set to the same color
    colorTopLeft = color;
	colorTopRight = color;
	colorBottomRight = color;
	colorBottomLeft = color;
}

void Rectangle::setColorTopLeft(Color color) {
	//The color in the top left vertex is set to the given color
    colorTopLeft = color;
}

Color Rectangle::getColorTopLeft() {
	//The color in the top left vertex is returned
    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color) {
	//The color in the top right vertex is set to the given color
    colorTopRight = color;
}

Color Rectangle::getColorTopRight() {
	//The color in the top right vertex is returned
    return colorTopRight;
}

void Rectangle::setColorBottomRight(Color color) {
	//The color in the bottom right vertex is set to the given color
    colorBottomRight = color;
}

Color Rectangle::getColorBottomRight() {
	//The color in the bottom right vertex is returned
    return colorBottomRight;
}

void Rectangle::setColorBottomLeft(Color color) {
	//The color in the bottom left vertex is set to the given color
    colorBottomLeft = color;
}

Color Rectangle::getColorBottomLeft() {
	//The color in the bottom left vertex is returned
    return colorBottomLeft;
}

//Probably Needs to be Fixed!!!
void Rectangle::read(istream& ins) {
	//Reads in the start point
	ins >> start;
	//Reads in the end point
	ins >> end;
	//Reads in the color of the top left vertex
	ins >> colorTopLeft;
	//Reads in the color of the top right vertex
	ins >> colorTopRight;
	//Reads in the color of the bottom right vertex
	ins >> colorBottomRight;
	//Reads in the color of the bottom left vertex
	ins >> colorBottomLeft;
	if (ins.fail()) {
		ins.clear();
	}
}

void Rectangle::write(ostream& outs) {
	/*Writes out the start point, the end point, the color in the top left vertex, the top right
	vertex, the bottom right vertex, and the bottom left vertex into the file*/
	outs << " " << start << " " << end << " " << colorTopLeft << " " <<
		colorTopRight << " " << colorBottomRight << " " << colorBottomLeft;
}


istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());
    
    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);
    
    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}

