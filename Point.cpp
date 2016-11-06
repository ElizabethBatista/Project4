/**
 * Point.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
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
    checkRange(xVal);
    //Checks the range of yVal and changes its value if needed
    checkRange(yVal);
    //Sets the value of x to xVal
    x = xVal;
    //Sets the value of y to yVal
	y = yVal;
}

void Point::setX(int xVal) {
	//Sets the value of xVal to x
    x = xVal;
}


int Point::getX() {
	//Returns the value of x
    return x;
}


void Point::setY(int yVal) {
	//Sets the value of yVal to y
    y = yVal;
}


int Point::getY() {
	//Returns the value of y
    return y;
}

//Needs to be fixed!
void Point::read(istream& ins) {
	cin >> x >> y;
}

//Needs to be fixed!
void Point::write(ostream& outs) {
	cout << "(" << x << "," << y << ")";

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

