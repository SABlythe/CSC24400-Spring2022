#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

class Complex
{
private:
  double _real;
  double _imaginary;
public:
  Complex(double realPart, double imaginaryPart);
  
  Complex operator+(Complex otherNumber); // do this + otherNumber
  Complex operator*(Complex otherNumber); // do this * otherNumber
  
  friend std::ostream& operator<<(std::ostream &os, Complex someNumber); 
  
  void print();
};

#endif
