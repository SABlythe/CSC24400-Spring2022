#include "Complex.hpp"

#include <iostream>

using namespace std;
 
Complex::Complex(double realPart, double imaginaryPart)
{
  _real = realPart;
  _imaginary = imaginaryPart;
}

Complex 
Complex::operator+(Complex otherNumber) // do this + otherNumber
{
   Complex theSum( _real + otherNumber._real,
                   _imaginary + otherNumber._imaginary );
   
   return theSum;
}

Complex 
Complex::operator*(Complex otherNumber) // do this * otherNumber
{
   // use high school  FOIL  method from algebra to get ...
   double real = _real * otherNumber._real - 
                 _imaginary * otherNumber._imaginary;
   double imag = _imaginary * otherNumber._real +
                 _real * otherNumber._imaginary;
   
   Complex theProd( real, imag );
   
   return theProd;
}

ostream& operator<<(ostream &os, Complex someNumber)
{
	os << someNumber._real << " + " 
	   << someNumber._imaginary << "i";
	   
	return os;
}

void 
Complex::print()
{
  cout << _real << " + " << _imaginary << "i";
}
