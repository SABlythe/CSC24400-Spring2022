#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  int value = 42;
  int* ptr;
  ptr = &value;

  cout << "value = " << value << endl;
  cout << "*ptr = " << *ptr << endl;
  cout << "ptr = " << ptr << endl;

  *ptr = 666;

  cout << "After *ptr=666:" << endl;
  cout << "value = " << value << endl;
  cout << "*ptr = " << *ptr << endl;
  cout << "ptr = " << ptr << endl;
  
  return 0;
}
