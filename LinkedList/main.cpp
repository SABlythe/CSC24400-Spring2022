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

  /*
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
  */

  LinkedList animals;

  
  animals.append("cat");
  
  animals.append("dog");
  animals.append("shark");
  animals.append("dolphin");

  
  if ( !animals.isEmpty() )
    cout << animals << endl;
  else
    cout << "List is empty!" << endl;

  ListNode *search = animals.find("shark");
  if (search) 
    cout << search->data() << endl;

  search = animals.find("shorts");
  if (search) 
    cout << search->data() << endl;

  search = animals.findPrev("shark");
  if (search) 
    cout << search->data() << endl;

  search = animals.findPrev("cat");
  if (search) 
    cout << search->data() << endl;
  else
    cout << "Not found!!" << endl;

  search = animals.findPrev("shorts");
  if (search) 
    cout << search->data() << endl;
  else
    cout << "Not found!!" << endl;

  ListNode *loc = animals.find("phoenix");
  //animals.insertBefore(loc, "human");
  //animals.insertAfter(loc, "human");
  animals.remove(loc);
  cout << animals << endl; // should have "human" between "dog" and "shark"

  animals.append("lobster");
  cout << animals << endl;
  
  return 0;
}
