/*--------------------------------------------------------------------------
This is the implementation for the class TwoD. The interface is in the file
twod.h.

Author: Chibuikem Amaechi
Email:  cramaechi@me.com
--------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "twod.h"

using namespace std;

TwoD::TwoD() :rows(10), cols(10)
{
    TwoDArray = new DoublePtr[rows];

    for (int row = 0; row < rows; row++)
    {
        TwoDArray[row] = new double[cols];
    }
}

TwoD::TwoD(unsigned int theRows, unsigned int theColumns) :rows(theRows), cols(theColumns)
{
    TwoDArray = new DoublePtr[rows];

    for (int row = 0; row < rows; row++)
    {
        TwoDArray[row] = new double[cols];
    }
}

TwoD::TwoD(const TwoD& otherTwoD) :rows(otherTwoD.rows), cols(otherTwoD.cols)
{
    TwoDArray = new DoublePtr[rows];

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < cols; column++)
        {
            TwoDArray[row][column] = otherTwoD.TwoDArray[row][column];
        }
    }
}	 

void TwoD::setElement(unsigned int theRow, unsigned int theColumn, double number)
{
    if (theRow >= rows)
    {
        cout<<"Error: Attempt to exceed max number of rows\n";
        exit(1);
    }
    else if (theColumn >= cols)
    {
        cout<<"Error: Attempt to exceed max number of columns\n";
        exit(1);
    }

    // The double bracket notation should work for pointer variable...
    TwoDArray[theRow][theColumn] = number;
}

double TwoD::getElement(unsigned int theRow, unsigned int theColumn) const
{
    if (theRow >= rows)
    {
        cout<<"Error: Attempt to exceed max number of rows\n";
        exit(1);
    }
    else if (theColumn >= cols)
    {
        cout<<"Error: Attempt to exceed max number of columns\n";
        exit(1);
    }

    return TwoDArray[theRow][theColumn];
}

TwoD& TwoD::operator =(const TwoD& rightSide)
{
    if (rows != rightSide.rows || cols != rightSide.cols)
    {   
        for (int row = 0; row < rows; row++)
        {
            delete [] TwoDArray[row];
        }

        delete [] TwoDArray;

        TwoDArray = new DoublePtr[rightSide.rows];

        for (int row; row < rightSide.rows; row++)
        {
            TwoDArray[row] = new double[rightSide.cols];
        }
    } 

    rows = rightSide.rows;
    cols = rightSide.cols;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < cols; column++)
        {
            TwoDArray[row][column] = rightSide.TwoDArray[row][column];
        }
    }

    return *this;
} 

const TwoD operator +(const TwoD& leftSide, const TwoD& rightSide)
{
    if (leftSide.rows != rightSide.rows || leftSide.cols != rightSide.cols) 
    {
        cout<<"Error: Attempt to add two two-dimensional arrays of different sizes\n";
        exit(1);
    }

    TwoD sumTwoD(leftSide.rows, leftSide.cols);

    for (int row = 0; row < sumTwoD.rows; row++)
    {
        for (int column = 0; column < sumTwoD.cols; column++)
        {
            sumTwoD.TwoDArray[row][column] = leftSide.TwoDArray[row][column] + rightSide.TwoDArray[row][column];
        }
    }

    return sumTwoD;
}

TwoD::~TwoD()
{
    for (int row = 0; row < rows; row++)
    {   
        delete [] TwoDArray[row];   
    }

    delete [] TwoDArray;
} 
