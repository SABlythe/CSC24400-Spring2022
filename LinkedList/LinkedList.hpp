#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <iostream>
#include <string>

#include "ListNode.hpp" 

class LinkedList
{
private:
  ListNode *_head;
public:
  LinkedList() : _head(NULL) {}

  void addFront(const std::string &newData);

  friend std::ostream& operator<<(std::ostream &os, const LinkedList &l);
};

#endif
