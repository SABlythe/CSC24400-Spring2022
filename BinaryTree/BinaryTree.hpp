#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

#include <iostream>
#include <string>

#include "TreeNode.hpp"

class BinaryTree
{
private:
  TreeNode *_root;
public:
  BinaryTree() : _root() {}

  TreeNode* find(const std::string &newVal) const;
  
  void insert(const std::string &newVal);
  TreeNode* remove(const std::string &newVal); // preview

  friend std::ostream& operator<<(std::ostream &os, const BinaryTree &bt);
};

#endif
