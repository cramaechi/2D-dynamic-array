//A program that uses a class named TwoD to model a two-dimensional dynamic
//array of doubles.
#include <iostream>
#include <iomanip>
#include "twod.h"

using namespace std;

void input(TwoD& a1, TwoD& a2);
//Reads user input into a1 and a2.

void output(TwoD& a1, TwoD& a2);
//Precondition: a1 and a2 have both been filled with floating point values.
//Postcondition: Prints out the contents of a1, a2, and a TwoD object
//containing elements which are the sum of the ith row, jth column element in
//a1 and the the ith row, jth column element in a2.

int  main()
{
    TwoD a1, a2;
    input(a1, a2);
    output(a1, a2);

    return 0;
}

void input(TwoD& a1, TwoD& a2)
{
    int r1, c1, r2, c2;
    cout<<"What are the dimensions of the first 2D array? ";
    cin>>r1>>c1;
    cout<<"What are the dimensions of the second 2D array? ";
    cin>>r2>>c2;
    cout<<endl;

    a1.setRows(r1);
    a1.setCols(c1);
    a2.setRows(r2);
    a2.setCols(c2);

    double n;

    cout<<"Enter decimal numbers for the first 2D array."<<endl;
    for (int row = 0; row < r1; row++)   
    {
        for (int column = 0; column < c1; column++)
        {
            cin>>n;
            a1.setElement(row, column, n);
        }
    }
    cout<<endl;

    cout<<"Enter decimal numbers for the second 2D array."<<endl;
    for (int row = 0; row < r2; row++)   
    {
        for (int column = 0; column < c2; column++)
        {
            cin>>n;
            a2.setElement(row, column, n);
        }
    }
    cout<<endl;
}

void output(TwoD& a1, TwoD& a2)
{
    cout<<"First 2D array"<<endl<<endl;
    cout<<setw(8);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    for (int row = 0; row < a1.getRows(); row++)
    {
        for (int col = 0; col < a1.getCols(); col++)
            cout<<a1.getElement(row, col)<<setw(8);
        cout<<endl;
    }
    cout<<endl;

    cout<<"Second 2D array"<<endl<<endl;
    cout<<setw(8);

    for (int row = 0; row < a2.getRows(); row++)
    {
        for (int col = 0; col < a2.getCols(); col++)
            cout<<a2.getElement(row, col)<<setw(8);
        cout<<endl;
    }
    cout<<endl;

    cout<<"Third 2D array (resulting from adding first and second 2D arrays)";
    cout<<endl<<endl;
    cout<<setw(8);

    TwoD a3 = a1 + a2;

    for (int row = 0; row < a3.getRows(); row++)
    {
        for (int col = 0; col < a3.getCols(); col++)
            cout<<a3.getElement(row, col)<<setw(8);
        cout<<endl;
    }
}
