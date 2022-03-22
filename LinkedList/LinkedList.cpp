#include "LinkedList.hpp"

using namespace std;

void
LinkedList::addFront(const std::string &newData)
{
  ListNode *newNode;
  newNode = new ListNode(newData);

  newNode->next() = _head;

  _head=newNode;
}


ostream& operator<<(ostream &os, const LinkedList &myList)
{
  ListNode *curr = myList._head;

  while (curr!=NULL)
    {
      os << *curr << " ";

      curr = curr->next();
    }
  
  return os;
}
