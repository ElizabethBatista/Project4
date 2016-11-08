/**
 * Triangle.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Triangle.h"
#include "Graphics.h"
#include "Shape.h"
#include <cmath>
using namespace std;

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Default contructor.
*/
Triangle::Triangle() {
}

/**
* Requires: Nothing.
* Modifies: vertexOne, vertexTwo, vertexThree,
*           vertexOneColor, vertexTwoColor, vertexThreeColor.
* Effects:  Overloaded constructor. Sets three vertices and sets all three
*           colors to one single color.
*/
Triangle::Triangle(Point pt1, Point pt2, Point pt3, Color color) {
	//Sets vertex #1 as the given point (pt1)
    vertexOne = pt1;
    //Sets vertex #2 as the given point (pt2)
	vertexTwo = pt2;
    //Sets vertex #3 as the given point (pt3)
	vertexThree = pt3;
    //Sets color #1, #2, and #3 as the same color
	vertexOneColor = color;
	vertexTwoColor = color;
	vertexThreeColor = color;
}

/**
* Requires: nothing
* Modifies: vertexOne, vertexTwo, vertexThree,
*           vertexOneColor, vertexTwoColor, vertexThreeColor.
* Effects:  Overloaded constructor. Sets three vertices and three colors.
*/
Triangle::Triangle(Point pt1, Color color1,
	Point pt2, Color color2,
	Point pt3, Color color3) {
	//Sets vertex #1 as the given point (pt1)
    vertexOne = pt1;
    //Sets vertex #2 as the given point (pt2)
	vertexTwo = pt2;
    //Sets vertex #3 as the given point (pt3)
	vertexThree = pt3;
    //Sets color #1 as the given color (color1)
	vertexOneColor = color1;
    //Sets color #2 as the given color (color2)
	vertexTwoColor = color2;
    //Sets color #3 as the given color (color3)
	vertexThreeColor = color3;
}

/**
* Requires: Nothing.
* Modifies: vertexOneColor, vertexTwoColor, vertexThreeColor.
* Effects:  Sets all three colors of triangle.
*/
void Triangle::setColor(Color color) {
	//Sets color #1, #2, and #3 as the same color
    vertexOneColor = color;
	vertexTwoColor = color;
	vertexThreeColor = color;
}

void Triangle::setVertexOne(Point pt) {
	//Sets vertex #1 as the given point
    vertexOne = pt;
}

Point Triangle::getVertexOne() {
	//Returns vertex #1
    return vertexOne;
}

void Triangle::setVertexOneColor(Color color) {
	//Sets color #1 as the given color
    vertexOneColor = color;
}

Color Triangle::getVertexOneColor() {
	//Returns color #1
    return vertexOneColor;
}

void Triangle::setVertexTwo(Point pt) {
	//Sets vertex #2 as the given point
    vertexTwo = pt;
}

Point Triangle::getVertexTwo() {
	//Returns vertex #2
    return vertexTwo;
}

void Triangle::setVertexTwoColor(Color color) {
	//Sets color #2 as the given color
    vertexTwoColor = color;
}

Color Triangle::getVertexTwoColor() {
	//Returns color #2
    return vertexTwoColor;
}

void Triangle::setVertexThree(Point pt) {
	//Sets vertex #3 as the given point
    vertexThree = pt;
}

Point Triangle::getVertexThree() {
	//Returns vertex #3
    return vertexThree;
}

void Triangle::setVertexThreeColor(Color color) {
	//Sets color #3 as the given color
    vertexThreeColor = color;
}

Color Triangle::getVertexThreeColor(){
	//Returns color #3
    return vertexThreeColor;
}

//Probably Needs Fixed!!!
void Triangle::read(istream& ins) {
	//Reads in vertex #1
    ins >> vertexOne;
    //Reads in color #1
	ins >> vertexOneColor;
	//If the object after vertex #1 was supposed to be a vertex and not a color
    if (ins.fail()) {
        //Reads in vertex #2
		ins >> vertexTwo;
       //Reads in vertex #3
		ins >> vertexThree;
        //Reads in color
		ins >> vertexOneColor;
	}
    //Reads in vertex #2
	ins >> vertexTwo;
    //Reads in color #2
	ins >> vertexTwoColor; 
    //Reads in vertex #3
	ins >> vertexThree;
    //Reads in color #3
	ins >> vertexThreeColor;
}

void Triangle::write(ostream& outs) {
	//Writes out the vertex #1, color #1, vertex #2, color #2, vertex #3, and color # 3
    outs << " " << vertexOne << " " << vertexOneColor << " " << vertexTwo <<
		" " << vertexTwoColor << " " << vertexThree << " " << vertexThreeColor;
}


istream& operator >> (istream& ins, Triangle& tri)
{
    tri.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Triangle tri)
{
    tri.write(outs);
    return outs;
}

void Triangle::draw (Graphics& drawer) {
    
    int xa = checkRange(getVertexOne().getX());
    int ya = checkRange(getVertexOne().getY());
    int xb = checkRange(getVertexTwo().getX());
    int yb = checkRange(getVertexTwo().getY());
    int xc = checkRange(getVertexThree().getX());
    int yc = checkRange(getVertexThree().getY());
    float red1 = (float)(getVertexOneColor().getRed()/255.0);
    float green1 = (float)(getVertexOneColor().getGreen()/255.0);
    float blue1 = (float)(getVertexOneColor().getBlue()/255.0);
    float red2 = (float)(getVertexTwoColor().getRed()/255.0);
    float green2 = (float)(getVertexTwoColor().getGreen()/255.0);
    float blue2 = (float)(getVertexTwoColor().getBlue()/255.0);
    float red3 = (float)(getVertexThreeColor().getRed()/255.0);
    float green3 = (float)(getVertexThreeColor().getGreen()/255.0);
    float blue3 = (float)(getVertexThreeColor().getBlue()/255.0);
    
    float a01, a02, a03, b01, b02, b03, c01, c02, c03, beta1, beta2, beta3;
    float lowX = 0, lowY = 0, highX = 0, highY = 0, i, j, R, G, B, t1, t2, t3;
    float triangleArea = 0;
    
    a01 = (float)(ya - yb);
    a02 = (float)(ya - yc);
    a03 = (float)(yb - yc);
    b01 = (float)(xb - xa);
    b02 = (float)(xc - xa);
    b03 = (float)(xc - xb);
    c01 = -(a01 * (xa+xb)+ b01 * (ya + yb)) / 2;
    c02 = -(a02 *(xa+xc) + b02 * (ya + yc)) / 2;
    c03 = -(a03 *(xb+xc) + b03 * (yb + yc)) / 2;
    
    if (evalFunc(xc,yc, (int)a01, (int)b01, (int)c01) < 0) {
        a01 = a01 * (-1);
        b01 = b01 * (-1);
        c01 = c01 * (-1);
    }
    if (evalFunc(xb,yb, (int)a02, (int)b02, (int)c02) < 0) {
        a02 = a02 * (-1);
        b02 = b02 * (-1);
        c02 = c02 * (-1);
    }
    if (evalFunc(xa,ya, (int)a03, (int)b03, (int)c03) < 0) {
        a03 = a03 * (-1);
        b03 = b03 * (-1);
        c03 = c03 * (-1);
    }
    if (xa > xb) { highX = (float)xa;  } else { highX = (float)xb; }
    if (xc > highX) { highX = (float)xc; }
    if (ya > yb) { highY = (float)ya; } else { highY = (float)yb; }
    if (yc > highY) { highY = (float)yc; }
    if (xa < xb) { lowX = (float)xa; } else { lowX = (float)xb; }
    if (xc < lowX) { lowX = (float)xc; }
    if (ya < yb) { lowY = (float)ya; } else { lowY = (float)yb; }
    if (yc < lowY) { lowY = (float)yc; }
    
    triangleArea = triArea(xa, ya, xb, yb, xc, yc);
    
    for (i = lowX; i < (highX+1); i++) {
        for (j = lowY; j < (highY+1); j++) {
            t1 = (float)evalFunc((int)i,(int)j, (int)a01, (int)b01, (int)c01);
            t2 = (float)evalFunc((int)i,(int)j, (int)a02, (int)b02, (int)c02);
            t3 = (float)evalFunc((int)i,(int)j, (int)a03, (int)b03, (int)c03);
            if ((t1 >= 0)&&(t2 >= 0)&&(t3 >= 0)){
                t1 = triArea(xb, yb, xc, yc, (int)i, (int)j);
                t2 = triArea(xc, yc, xa, ya, (int)i, (int)j);
                t3 = triArea(xa, ya, xb, yb, (int)i, (int)j);
                beta1 = triArea(xb, yb, xc, yc, (int)i, (int)j)/triangleArea;
                beta2 = triArea(xc, yc, xa, ya, (int)i, (int)j)/triangleArea;
                beta3 = triArea(xa, ya, xb, yb, (int)i, (int)j)/triangleArea;
                R = (beta1*red1 + beta2*red2 + beta3*red3) * 255;
                G = (beta1*green1 + beta2*green2 + beta3*green3) * 255;
                B = (beta1*blue1 + beta2*blue2 + beta3*blue3) * 255;
                drawer.setPixel((int)i,(int)j,Color((int)R,(int)G,int(B)));
            }
        }
    }
}

int Triangle::checkRange(int val)
{
    if (val < 0)
        return 0;
    else if (val > DIMENSION)
        return DIMENSION;
    else
        return val;
}

int Triangle::evalFunc(int x, int y, int a, int b, int c) {
    int e = a*x+b*y+c;
    return(e);
}

float Triangle::triArea(int xa, int ya, int xb, int yb, int xref, int yref) {
    xa -= xref;
    xb -= xref;
    ya -= yref;
    yb -= yref;
    return((float)(sqrt(pow((double)(yb*xa)-(xb*ya), (double)2))*0.5));
}

