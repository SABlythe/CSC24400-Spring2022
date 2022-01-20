#include <iostream>

using namespace std;

int factorial (int n)
{
  if (n==0)
    return 1;
  else
    return n * factorial(n-1);
}

int main(int argc, char *argv[])
{
  cout << "What number do you want the factorial of? ";
  int myNum;
  cin >> myNum;
  
  cout << myNum << "! = " << factorial(myNum) << endl;
  return 0;
}
