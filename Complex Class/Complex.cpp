#include <iostream>
#include <cmath>
using namespace std;
#include "Complex.hpp"
// Constructor to initialise the data members
Complex::Complex()
{
    r = i = 0.0;
}

// Function to print the complex number
void Complex::print()
{
    if (i >= 0)
    {
        cout << r << " + " << i << "i" << endl
             << endl;
    }
    else
    {
        cout << r << " - " << (-1) * i << "i" << endl
             << endl;
    }
}

// Parameterized Const. to set values for the components of the complex number
Complex::Complex(double x, double y)
{
    r = x;
    i = y;
}
void Complex::sub(Complex c1, Complex c2)
{
    r = c1.r - c2.r;
    i = c1.i - c2.i;
}

void Complex::add(Complex c)
{
    r = c1.r + c2.r;
    i = c1.i + c2.i;
}
// Function to multiply 2 complex numbers
void Complex::mul(Complex c1, Complex c2)
{
    r = (c1.r * c2.r) - (c1.i * c2.i);
    i = (c1.i * c2.r) + (c1.r * c2.i);
}

// Function to divide 2 complex numbers
void Complex::div(Complex c1, Complex c2)
{
    r = (c1.r * c2.r + c1.i * c2.i) / (pow(c2.r, 2) + pow(c2.i, 2));
    i = (c1.i * c2.r - c1.r * c2.i) / (pow(c2.r, 2) + pow(c2.i, 2));
}

// conjugate of a complex number
void Complex::conjugate()
{
    this->i = this->i * (-1);
    this->print();
}

double Complex::norm()
{
    return sqrt(pow(r, 2) + pow(i, 2));
}