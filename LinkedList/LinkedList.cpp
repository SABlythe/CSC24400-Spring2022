#include "LinkedList.hpp"

using namespace std;

/*
ListNode*
LinkedList::findTail() const
{
  ListNode *curr = _head;

  // if no items in the list, there is no tail !!!
  if (curr==NULL)
    return NULL;
  
  while(curr->next() != NULL)
    {
      curr = curr -> next();
    }

  return curr;
}
*/

void
LinkedList::addFront(const std::string &newData)
{
  ListNode *newNode;
  newNode = new ListNode(newData);

  bool startedEmpty = (_head==NULL) ;
  
  newNode->next() = _head;

  _head=newNode;

  if (startedEmpty)
    _tail = newNode;
}

void
LinkedList::append(const std::string &newData) //add at end of list
{
  ListNode *nodeToAdd = new ListNode(newData);
  ListNode *tail = findTail();

  // if the tail actually existed ... go ahead and add node ...
  if (tail)
    {
      tail->next() = nodeToAdd;
      _tail = nodeToAdd;
    }
  else // add to an empty list, so adding at front is same as adding at tail
    addFront(newData);
  
}

ListNode*
LinkedList::removeFront()
{
  ListNode *valueToReturn = _head;

  // if list is empty , mpthing to do !
  if (!_head)
    {
      return NULL;
    }
  // if there's only one item in list, then ...
  if (_head==_tail)
    {
      _tail = NULL;
      _head = NULL;
    }
  else
    _head = _head->next();


  valueToReturn->next() = NULL;
  return valueToReturn;
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
