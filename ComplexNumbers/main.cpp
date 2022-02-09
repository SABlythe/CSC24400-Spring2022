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
	
	return 0;
}
