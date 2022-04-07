#include "TreeNode.hpp"

bool
TreeNode::isLeaf() const
{
  return !_left && !_right;
}

int
TreeNode::depth() const
{
  int numHops=0;  // maybe 1? 
  TreeNode* ancestor = _parent;

  // while we are not the root node ...
  while( ancestor!=NULL )
    {
      numHops++;

      ancestor = ancestor->parent();
    }

  return numHops;
}

std::ostream& operator<<(std::ostream &os, const TreeNode &tn)
{
  os << *tn._data;

  return os;
}
