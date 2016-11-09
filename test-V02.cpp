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
    // test default constructor
    Point p1;
    // test constructor with input values
    Point p2(3,0);
    Point p3(-5,100);
    Point p4(-100,-2);
    Point p5(2000,200);
    // test member functions setX and setY
    p2.setX(4);
    p2.setY(5);
    p3.setX(-10);
    p3.setY(800);
    p4.setX(-9);
    p4.setY(-14);
    p5.setX(100);
    p5.setY(100);
    // test getX, getY, read, and <<
    cout << "(" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "(" << p3.getX() << ", " << p3.getY() << ")" << endl;
    cout << "(" << p4.getX() << ", " << p4.getY() << ")" << endl;
    cout << "(" << p5.getX() << ", " << p5.getY() << ")" << endl;
    cout << "Point1: " << p1 << endl << endl;
    cout << "Point2: " << p2 << endl << endl;
    cout << "Point3: " << p3 << endl << endl;
    cout << "Point4: " << p4 << endl << endl;
    cout << "Point5: " << p5 << endl << endl;
}

void testing_graphic() {
    cout << "Graphic tests" << endl;
    Color pixelData[5][5];
    initArray();
    cout << "Pixel Data: ";
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            cout << pixelData[x][y];
        }
    }
    clear();
    cout << "Pixel Data: ";
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            cout << pixelData[x][y];
        }
    }
    int i = 2;
    int j = 3;
    Color color = (3,2,5);
    setPixel(i, j, color);
    cout << pixelData[i][j];
}

void testing_color() {
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
}

void testing_line() {
    Point p1;
    Point p2(3,0);
    Color color2(-5,200,-42);
    cout << "Line tests" << endl;
    Line line1(p1,p2,color2);
    cout << "Line1: " << line1 << endl;
    Point p0(6,9);
    Line line2(p0,p2,color2);
    //Line line2;
    cout << "Line2a: " << line2 << endl;
    cout << "enter input for a line object:" << endl;
}

void testing_circle() {
    cout << "Circle tests" << endl;
    Point p4(9,3);
    Point p1;
    Color color1;
    Color color2(-5,200,-42);
    Circle circle1(p4,5,color2);
    cout << "Circle1: " << circle1 << endl;
    Circle circle2(p1,1,color1);
    cout << "enter input for a circle object:" << endl;
}

void testing_triangle() {
    cout << "Triangle tests" << endl;
    Point p1;
    Point p2(3,0);
    Point p3(8,5);
    Color color2(-5,200,-42);
    Point p1(-19,200)
    Point p2(3,0);
    Point p3(8,5);
    Color color2(5,20,42);
    Point p1(19,20);
    Point p2(-3,600);
    Point p3(-8,500);
    Color color2(-5,200,-42);
    Triangle triangle1(p1, p2, p3, color2);
    cout << "Triangle1: " << triangle1 << endl;
    Triangle triangle1(p4, p5, p6, color1);
    cout << "Triangle2: " << triangle1 << endl;
    Triangle triangle1(p7, p8, p9, color3);
    cout << "Triangle1: " << triangle1 << endl;
}

void testing_rectangle() {
    cout << "Rectangle tests" << endl;
    Point p1;
    Point p4(9,3);
    Color color2(-5,200,-42);
    Point p2(-6,700);
    Point p5(9,3);
    Color color1(5,200,42);
    Point p3(-4,-4);
    Point p6(9,3);
    Color color3(5,2000,-42);
    Rectangle rectangle1(p1, p4, color2);
    cout << "Rectangle1: " << circle1 << endl;
    Rectangle rectangle1(p2, p5, color1);
    cout << "Rectangle1: " << circle1 << endl;
    Rectangle rectangle1(p3, p6, color3);
    cout << "Rectangle1: " << circle1 << endl;
}
