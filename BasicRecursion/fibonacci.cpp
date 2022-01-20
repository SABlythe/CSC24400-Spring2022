#include <iostream>

using namespace std;

long answers[150];

long fibo (int n)
{
  // did we already calculate this value? 
  if (answers[n] != 0)
    return answers[n];
    
  if (n<=2)
    answers[n] = 1;
  else
    answers[n] = fibo(n-1) + fibo(n-2);
    
  return answers[n];
}

int main(int argc, char *argv[])
{
  for (int index=0; index<150; index++)
  	answers[index] = 0; // 0 means "empty"

  cout << "What number do you want the Fibonacci of? ";
  int myNum;
  cin >> myNum;
  
  cout << myNum << "'th fibonacci number is " 
       << fibo(myNum) << endl;
  return 0;
}
