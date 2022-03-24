#include <iostream>

#include "LinkedList.hpp"
#include "ListNode.hpp"


using namespace std;

int main(int argc, char *argv[])
{
  /*
  ListNode node; 

  cout << node << endl;

  node.data() = "hello";

  cout << node << endl;

  ListNode second ("Cardinals rule!");

  cout << node << endl;
  cout << second << endl;

  node.next() = &second;
  cout << node << endl;

  */

  LinkedList  names;

  cout << names << endl;

  names.append("Josh");
  cout << names << endl;

  names.addFront("Blythe");
  cout << names << endl;

  names.addFront("Jordina");
  cout << names << endl;

  names.append("Connor");
  cout << names << endl;

  names.append("Blythe");
  cout << names << endl;
  
  return 0;
}
