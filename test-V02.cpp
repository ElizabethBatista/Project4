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
#include "Graphics.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "utility.h"

using namespace std;


int main()
{
    cout << endl;
    cout << "Point tests" << endl;
    // test default constructor
    Point p1;
    // test constructor with input values
    Point p2(3,0);
    // test member functions setX and setY
    p2.setX(4);
    p2.setY(5);
    // test getX, getY, read, and <<
    cout << "(" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "Point2: " << p2 << endl << endl;
    
    
    cout << "Color tests" << endl;
    Color color1;
    cout << "Color1: " << color1 << endl;
    Color color2(-5,200,-42);
    cout << "Color2 starts as -5 200 -42" << endl;
    cout << "Color2 is automatically changed to: " << color2 << endl;
    color2.setRed(255);
    cout << "Color2 red changed: " << color2 << endl;
    cout << "enter input for a color object:" << endl;
    color2.read(cin);
    cout << color2.getRed() << " " << color2.getGreen() << " " << color2.getBlue() << endl;
    color2.write(cout);
    cout << endl;
    
    
    cout << "Line tests" << endl;
    Line line1(p1,p2,color2);
    cout << "Line1: " << line1 << endl;
    Point p0(6,9);
    Line line2(p0,p2,color2);
    //Line line2;
    cout << "Line2a: " << line2 << endl;
    cout << "enter input for a line object:" << endl;
    line2.read(cin);
    cout << "Line2b: " << line2 << endl << endl;
    
    
    cout << "Circle tests" << endl;
    Point p4(9,3);
    Circle circle1(p4,5,color2);
    cout << "Circle1: " << circle1 << endl;
    Circle circle2(p1,1,color1);
    cout << "enter input for a circle object:" << endl;
    circle2.read(cin);
    cout << "Circle2: " << circle2 << endl << endl;
    
    
    cout << "Rectangle tests" << endl;
    Rectangle rectangle1(p4,p1,color2);
    cout << "Rectangle1: " << circle1 << endl;
    Rectangle rectangle2;
    cout << "enter input for a rectangle object:" << endl;
    rectangle2.read(cin);
    cout << "Rectangle2: " << rectangle2 << endl << endl;
    
    
    cout << endl;
    cout << "Triangle tests" << endl;
    Point p3(8,5);
    Triangle triangle1(p1,p2,p3,color2);
    cout << "Triangle1: " << triangle1 << endl;
    
    Triangle triangle2;
    cout << "enter input for a triangle object:" << endl;
    triangle2.read(cin);
    cout << "Triangle2: " << triangle2 << endl << endl;
    
    
    return 0;

}
