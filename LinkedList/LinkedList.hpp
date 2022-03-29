#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <iostream>
#include <string>

#include "ListNode.hpp" 

class LinkedList
{
private:
  ListNode *_head;
  ListNode *_tail;
public:
  LinkedList() : _head(NULL), _tail(NULL) {}

  void addFront(const std::string &newData);
  void append(const std::string &newData); //add at end of list
  void insertBefore(ListNode *here, const std::string &newData);

  
  bool isEmpty() const {return _head==NULL;}
  
  // returns poiter to the item removed ...
  ListNode* removeFront();

  ListNode* find(const std::string &value) const;
  ListNode* findPrev(const std::string &value) const;
  
  ListNode* findTail() const {return _tail;}

  friend std::ostream& operator<<(std::ostream &os, const LinkedList &l);
};

#endif
