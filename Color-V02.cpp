/**
 * Color.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * Kelly, Elizabeth Batista
 * kbrakke, ellazar
 *
 * Project 4 color implementation file
 */

#include "Color.h"


// int maxVal = 255;

// TODO: implement first checkRange, then two constructors, setRed, getRed,
//       setGreen, getGreen, setBlue, getBlue, read, write.

// sets color to (0, 0, 0)
Color::Color()
{
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(int redVal, int greenVal, int blueVal)
{
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

void Color::setRed(int redVal)
{
    red = checkRange(redVal);
}

int Color::getRed()
{
    return red;
}

void Color::setGreen(int greenVal)
{
    green = checkRange(greenVal);
}

int Color::getGreen()
{
    return green;
}

void Color::setBlue(int blueVal)
{
    blue = checkRange(blueVal);
}

int Color::getBlue()
{
    return blue;
}


// Reads in the integer values RGB designating the color
void Color::read(istream& ins)
{
    ins >> red >> green >> blue;
    this->setRed(red);
    this->setGreen(green);
    this->setBlue(blue);
}

// TODO check if this must be reversed
// Writes R-space-G-space-B
void Color::write(ostream& outs)
{
    cout << red << " " << green << " " << blue;
}


// check if range between 0 and 255, if not return closest of the two ints
int Color::checkRange(int val)
{
    // minVal is 0, maxVal is 255
    int maxVal = 255;
    if( 0 <= val && val <= maxVal)
    {
        return val;
    }
    else
    {
        int absOfVal = abs(val);
        int absOfDiff = abs(maxVal - val);
        
        // since 256 is an even number of possible values, use <
        if(absOfVal < absOfDiff)
        {
            return 0;
        }
        else
        {
            return maxVal;
        }
    }
    return 0;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
    color.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Color color)
{
    color.write(outs);
    return outs;
}

