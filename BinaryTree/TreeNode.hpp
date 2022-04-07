#ifndef _TREE_NODE_HPP_
#define _TREE_NODE_HPP_

#include <iostream>
#include <string>

class TreeNode
{
private:
  std::string *_data;

  TreeNode *_parent;
  TreeNode *_left;
  TreeNode *_right;
  
public:
  TreeNode(const std::string &value):
    _data( new std::string(value) ), _parent(), _left(), _right()  {} 

  const std::string* data() const {return _data;}
  std::string* & data()  {return _data;} // use with EXTREME caution!

  const TreeNode* parent() const {return _parent;}
  TreeNode* & parent()  {return _parent;}

  const TreeNode* left() const {return _left;}
  TreeNode* & left() {return _left;}
  
  const TreeNode* right() const {return _right;}
  TreeNode* & right() {return _right;}

  bool isLeaf() const;
  int depth() const;

  friend std::ostream& operator<<(std::ostream &os, const TreeNode &tn);
};

#endif
