#include <cstdlib>
#include <iostream>

#include "PFA.hpp"

using namespace std;

int main(int argc, char **argv)
{ 
  PFA myNumbers(argc);

  for (int i=1; i< argc; i++)
    {
      // do something with argv[i] ....
      myNumbers.addElement( atoi(argv[i]) );
    }
  /*
  myNumbers.addElement(11);
  myNumbers.addElement(3);
  myNumbers.addElement(222222);
  myNumbers.addElement(42);
  */
  
  cout << myNumbers; //myNumbers.print(cout);
  
  return 0;
}
