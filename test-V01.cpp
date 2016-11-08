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
#include "Circle.h"

using namespace std;


int main()
{
    // Point tests
    cout << endl;
    // cout << "Point tests" << endl;
    // test default constructor
    Point p1;
    // test constructor with input values
    Point p2(3,0);
    // test member functions setX and setY
    p2.setX(4);
    p2.setY(5);
    // test getX, getY, read, and <<
    cout << "(" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "Point2: " << p2 << endl;
    
    // Color tests
    cout << endl;
    // cout << "Color tests" << endl;
    Color color1;
    Color color2(-5,200,-42);
    color2.setRed(255);
    cout << color2.getRed() << " " << color2.getGreen() << " " << color2.getBlue() << endl;
    cout << "enter input for a color object:" << endl;
    color2.read(cin);
    cout << color2.getRed() << " " << color2.getGreen() << " " << color2.getBlue() << endl;
    color2.write(cout);
    
    // Line tests
    cout << endl;
    // cout << "Line tests" << endl;
    Line line1(p1,p2,color2);
    cout << "Line1: " << line1 << endl;
    Line line2;
    cout << "enter input for a line object:" << endl;
    line2.read(cin);
    cout << "Line2: " << line2 << endl;
    
    /*
     // Triangle tests
     cout << endl;
     // cout << "Triangle tests" << endl;
     Point p3(8,5);
     Triangle triangle1(p1,p2,p3,color2);
     cout << "Triangle1: " << triangle1 << endl;
     Triangle triangle2;
     cout << "enter input for a triangle object:" << endl;
     triangle2.read(cin);
     cout << "Triangle2: " << triangle2 << endl;
    
     */
    
    // Circle tests
    cout << endl;
    // cout << "Circle tests" << endl;
    Point p4(9,3);
    Circle circle1(p4,5,color2);
    cout << "Circle1: " << circle1 << endl;
    //Circle circle2(p3,15,color1);
    Circle circle2(p1,1,color1);
    cout << "enter input for a circle object:" << endl;
    circle2.read(cin);
    cout << "Circle2: " << circle2 << endl;
    
    
    
    return 0;
}
