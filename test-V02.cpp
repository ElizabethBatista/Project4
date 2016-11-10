//
//  test.cpp
//  Project4
//
//  Created by Elizabeth Batista on 11/5/16.
//  Copyright © 2016 Elizabeth Batista. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Point.h"
#include "Color.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "utility.h"

using namespace std;


int main()
{
  testing_point();
  testing_graphic();
  testing_color();
  testing_line();
  testing_circle();
  testing_triangle();
  testing_rectangle();
    
    return 0;
}

void testing_point() {
	cout << endl;
	cout << "Point tests" << endl;
	Point p1;
	Point p2(3, 0);
	p2.setX(4);
	p2.setY(5);
	cout << "(" << p2.getX() << ", " << p2.getY() << ")" << endl;
	cout << "Point2: " << p2 << endl << endl;
}

void testing_color() {
	cout << "Color tests" << endl;
	Color color1;
	cout << "Color1: " << color1 << endl;
	Color color2(-5, 200, -42);
	cout << "Color2 starts as -5 200 -42" << endl;
	cout << "Color2 is automatically changed to: " << color2 << endl;
	color2.setRed(255);
	cout << "Color2 red changed: " << color2 << endl;
	cout << "enter input for a color object:" << endl;
	color2.read(cin);
	cout << color2.getRed() << " " << color2.getGreen() << " " << color2.getBlue() << endl;
	color2.write(cout);
	cout << endl;
}

void testing_line() {
	Point p0(6, 9);
	Point p1;
	Point p2(3, 0);
	Color color2(-5, 200, -42);
	cout << "Line tests" << endl;
	Line line1(p1, p2, color2);
	cout << "Line1: " << line1 << endl;
	Line line2(p0, p2, color2);
	//Line line2;
	cout << "Line2a: " << line2 << endl;
	cout << "enter input for a line object:" << endl;
	line2.read(cin);
	cout << "Line2b: " << line2 << endl << endl;
}

void testing_circle() {
	Point p1;
	Point p4(9, 3);
	Color color1;
	Color color2(-5, 200, -42);
	cout << "Circle tests" << endl;
	Circle circle1(p4, 5, color2);
	cout << "Circle1: " << circle1 << endl;
	Circle circle2(p1, 1, color1);
	cout << "enter input for a circle object:" << endl;
}

void testing_triangle() {
	cout << "Triangle tests" << endl;
	Point p1;
	Point p2(3, 0);
	Point p3(8, 5);
	Color color2(-5, 200, -42);
	Point p4(-19, 200);
	Point p5(3, 0);
	Point p6(8, 5);
	Color color1(5, 20, 42);
	Point p7(19, 20);
	Point p8(-3, 600);
	Point p9(-8, 500);
	Color color3(-5, 200, -42);
	Point pt1, pt2, pt3;
	Color col1, col2, col3;
	pt1.setVertexOne(4, 9);
	pt2.setVertexTwo(4, 9);
	pt3.setVertexThree(4, 9);
	col1.setVertexOneColor(60, 60, 70);
	col2.setVertexTwoColor(90, 90, 90);
	col3.setVertexThreeColor(120, 120, 120);
	Triangle triangle1(p1, p2, p3, color2);
	cout << "Triangle1: " << triangle1 << endl;
	Triangle triangle2(p4, p5, p6, color1);
	cout << "Triangle2: " << triangle2 << endl;
	Triangle triangle3(p7, p8, p9, color3);
	cout << "Triangle3: " << triangle3 << endl;
	Triangle triangle4();
	cout << "Triangle4: " << triangle4 << endl;
	cout << "Triangle5: " << pt1.getVertexOne() << col1.getVertexColorOne <<
		pt2.getVertexTwo() << col2.getVertexColorTwo() << pt3.getVertexThree()
		<< col3.getVertexColorThree() << endl;
	Triangle triangle6;
	cout << "enter input for a triangle object:" << endl;
	triangle6.read(cin);
	cout << "Triangle6: " << triangle6 << endl << endl;


}

void testing_rectangle() {
	cout << "Rectangle tests" << endl;
	Point p1;
	Point p4(9, 3);
	Color color2(-5, 200, -42);
	Point p2(-6, 700);
	Point p5(3, 9);
	Color color1(5, 200, 42);
	Point p3(-4, -4);
	Point p6(5, 12);
	Color color3(5, 2000, -42);
	Point p7, p8;
	Color color4;
	p7.setStart(-6, 0);
	p8.setEnd(25, 500);
	color4.setColor(250, -4, 800);
	Rectangle rectangle1(p1, p4, color2);
	cout << "Rectangle1: " << rectangle1 << endl;
	Rectangle rectangle2(p2, p5, color1);
	cout << "Rectangle2: " << rectangle2 << endl;
	Rectangle rectangle3(p3, p6, color3);
	cout << "Rectangle3: " << rectangle3 << endl;
	Rectangle rectangle4();
	cout << "Rectangle4: " << rectangle4 << endl;
	Rectangle rectangle5(p4, p6, color2, color1, color3);
	cout << "Rectangle5: " << rectangle5: << endl;
	cout << "Rectangle6: " << p7.getStart() << p8.getEnd() <<
		 color.getColorTopLeft() << color.getColorTopRight() <<
		 color.getColorBottomRight() << color.getColorBottomLeft() << endl;
	Rectangle rectangle7;
	cout << "enter input for a rectangle object:" << endl;
	rectangle7.read(cin);
	cout << "Rectangle7: " << rectangle7 << endl << endl;
}
