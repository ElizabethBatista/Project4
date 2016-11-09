/**
 * Graphics.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

#include "Graphics.h"
#include "bmp.h"

using namespace std;

Graphics::Graphics() {
	//Calls initArray in order to set every pixel to black
    initArray();
}

void Graphics::clear() {
	//Calls initArray in order to set every pixel to black
    initArray();
}

void Graphics::setPixel(int x, int y, Color color) {
    //Sets a given pixel a given color
    pixelData[x][y] = color;
}

void Graphics::initArray() {
	//Goes through every row in the pixel data array
    for (int x = 0; x < DIMENSION; x++) {
		//Goes through every column in the pixel data array
        for (int y = 0; y < DIMENSION; y++) {		
			//Sets every pixel in the array to black (red, green, and blue are 0)
            		pixelData[x][y].setRed(0);
			pixelData[x][y].setGreen(0);
			pixelData[x][y].setBlue(0);
		}
	}
}

void Graphics::writeFile(string fileName) const
{
    ofstream outFile;
    outFile.open(fileName);
    
    // determine padding
    int padding = (4 - (DIMENSION * 3) % 4) % 4;
    
    // BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    bf.bfType = 0x4d42; // type of file = bitmap
    bf.bfSize = DIMENSION * (DIMENSION + padding) * 3 + 54; // TODO
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = 54; // location of pixels
    
    // BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    bi.biSize = 40; // header size
    bi.biWidth = DIMENSION;
    bi.biHeight = -DIMENSION;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = 0;
    bi.biSizeImage = bi.biWidth * bi.biHeight * 3;
    bi.biXPelsPerMeter = 2834;
    bi.biYPelsPerMeter = 2834;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;
    
    // write output BITMAPFILEHEADER
    outFile.write((char*)&bf, sizeof(BITMAPFILEHEADER));
    
    // write output BITMAPINFOHEADER
    outFile.write((char*)&bi, sizeof(BITMAPINFOHEADER));
    
    // iterate over lines
    for (int i = 0; i < DIMENSION; i++)
    {
        // iterate over pixels in line
        for (int j = 0; j < DIMENSION; j++)
        {
            // temporary storage
            Color pixel = pixelData[i][j];
            
            // write RGB triple to outfile
            outFile << (BYTE) pixel.getBlue() << (BYTE) pixel.getGreen()
            << (BYTE) pixel.getRed();
        }
        
        // write padding to outfile
        for (int k = 0; k < padding; k++)
        {
            outFile << 0;
        }
    }
    
    // close file
    outFile.close();
}

