#include <iostream>

#include "Complex.hpp"

using namespace std;

int main (int argc, char *argv[])
{
  Complex *ptr = new Complex(2, 2.13) ; // 2 + 2.13i

  cout << "*ptr = " << *ptr << endl;
  cout << "ptr = " << ptr << endl;

  // remember, there's an   imaginary()   method in the Complex class
  //cout << " The imaginary part of ptr is:" << (*ptr).imaginary() << endl;
  cout << " The imaginary part of ptr is:" << ptr->imaginary() << endl;
  
  return 0;
}
