#ifndef _LIST_NODE_HPP_
#define _LIST_NODE_HPP_

#include <iostream>
#include <string>

class ListNode
{
private:
  std::string _data;
  ListNode *_next;
public:
  ListNode(): _data(), _next(NULL) {}
  ListNode(const std::string &sval): _data(sval), _next(NULL) {}

  // accessors
  const std::string& data() const {return _data;}
  ListNode* next() const {return _next;}

  // modifiers
  std::string& data() {return _data;}
  ListNode* & next() {return _next;}
  
  friend std::ostream& operator<<(std::ostream &os, const ListNode &ln);
  
};

#endif
