/**
 * Point.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * Kelly Brakke, Elizabeth Batista
 * kbrakke, ellazar
 *
 * Implementation of Point.cpp functions
 */

#include "Point.h"
#include "utility.h"

Point::Point() {
    //Initializes x to 0
    x = 0;
    //Initializes y to 0
    y = 0;
}

//Pobably needs fixed!
Point::Point(int xVal, int yVal) {
    //Checks the range of xVal and changes its value if needed
    xVal = checkRange(xVal);
    //Sets the value of x to xVal
    x = xVal;
    //Checks the range of yVal and changes its value if needed
    yVal = checkRange(yVal);
    //Sets the value of y to yVal
    y = yVal;
}

void Point::setX(int xVal) {
    //Checks the range of xVal and changes its value if needed
    xVal = checkRange(xVal);
    //Sets the value of xVal to x
    x = xVal;
}

int Point::getX() {
    //Checks the range of xVal and changes its value if needed
    //xVal = checkRange(xVal);
    //Returns the value of x
    return x;
}


void Point::setY(int yVal) {
    //Checks the range of yVal and changes its value if needed
    yVal = checkRange(yVal);
    //Sets the value of yVal to y
    y = yVal;
}


int Point::getY() {
    //Checks the range of yVal and changes its value if needed
    //yVal = checkRange(yVal);
    //Returns the value of y
    return y;
}

//Needs to be fixed!
void Point::read(istream& ins) {
    //Used to pick up the parenthesis and comma in the file data
    char dontMatter = '-';
    //Reads the values of the data, the parenthesis and comma is disregarded
    ins >> dontMatter;
    ins >> x;
    ins >> dontMatter;
    ins >> y;
    ins >> dontMatter;
}

void Point::write(ostream& outs) {
    //Writes out the point into the file in the form (x,y)
    outs << "(" << x << "," << y << ")";
}

int Point::checkRange(int val) {
    //Returns the value if it is 0 or greater and less than the demension
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    //Sets the value to 0 and returns it if the value is less than 0
    else if (val < 0) {
        val = 0;
        return val;
    }
    /*Sets the value to 1 less than the demension and returns it
     if the value is greater than or equal to the demension*/
    else if (val >= DIMENSION) {
        val = (DIMENSION - 1);
        return val;
    }
    
    return 0;
}


istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
