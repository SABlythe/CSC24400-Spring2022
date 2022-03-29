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


void
LinkedList::insertBefore(ListNode *here, const std::string &newData)
{
  ListNode *prev = findPrev(here->data());

  ListNode *newNode = new ListNode(newData);

  newNode->next() = here;
  prev->next() = newNode;
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

ListNode*
LinkedList::find(const std::string &value) const
{
  ListNode *curr;

  curr = _head;
  while(curr)
    {
      if (curr->data() == value)
	return curr;
      else
	curr=curr->next();
    }
  return NULL;  
}

ListNode*
LinkedList::findPrev(const std::string &value) const
{
  if (!find(value))
    {
      cerr << "Warning: " << value << " not found in list !!!" << endl;
      return NULL;
    }

  
  ListNode *curr;

  curr = _head;
  while(curr->next())
    {
      if (curr->next()->data() == value)
	return curr;
      else
	curr=curr->next();
    }
  return NULL;  
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
