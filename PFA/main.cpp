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
      //myNumbers.addElement( atoi(argv[i]) );
      myNumbers+=atoi(argv[i]);
    }

  
  //myNumbers.addElement(11);
  myNumbers+=11;
  //cout << "added one value" <<endl;
  //myNumbers.addElement(3);
  myNumbers+=3;
  
  //cout << "added some values" <<endl;
  
  //myNumbers.addElement(222222);
  myNumbers+=222222;
  //myNumbers.addElement(42);
  myNumbers+=42;

  //cout << "added all values" <<endl;
  
  
  cout << myNumbers; //myNumbers.print(cout);
  
  return 0;
}
