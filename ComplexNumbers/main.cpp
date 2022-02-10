#include <iostream>

#include "Complex.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Complex num1(1,2); // 1 + 2i
	Complex num2(1,-2); // 1 - 2i
	
	Complex num3  = num1.operator+(num2);
	num3 = num1 + num2;
	
	//num3.print();
	cout << "addition gave:" << num3 << endl;
	
	num3 = num1 * num2;
	cout << "multiply gave:" << num3 << endl;

	double val = 3.3;
	num3 = num1 + val;

	cout << "adding " << num1 << " + " << val << " = " << num3 << endl;

	num3 = val + num1;

	cout << "adding " << val << " + " << num1 << " = " << num3 << endl;

	num3 = num1/num2;

	cout << num1 << "/" << num2 << "=" << num3 << endl;

	cout << num3 * num2 << endl;

	cout << "The imaginary part of " << num3
	     << " is " << num3.imaginary() << endl; 

	num3.imaginary() = 99;
	cout << "The imaginary part of " << num3
	     << " is NOW " << num3.imaginary() << endl; 
	
	return 0;
}
