#include "BinaryTree.hpp"

using namespace std;

TreeNode*
BinaryTree::find(const std::string &newVal) const
{
  TreeNode *curr = _root;

  while (  curr  &&  *(curr->data())  !=  newVal )
    {
      if ( *(curr->data())  >  newVal )
	{
	  curr=curr->left();
	}
      else if ( *(curr->data())  <  newVal )
	{
	  curr=curr->right();
	}
    }
  
  return curr; // fix me LATER !!!!
}

// returns new tree with new node inserted
TreeNode* recursiveInsert( TreeNode *intoSubTree, TreeNode *newNode  )
{
  if (!intoSubTree) // if subtree is empty ...
    {
      return newNode;
    }

  // should I insert in left subtree? 
  if ( *(newNode->data()) < *(intoSubTree->data()) )
    {
      // insert newNode into left subtree and update this node's left pointer
      intoSubTree->left() = recursiveInsert( intoSubTree->left() , newNode );

      // update modified left child's parent properly. 
      intoSubTree->left()->parent() = intoSubTree;
    }
  else if ( *(newNode->data()) > *(intoSubTree->data()) )
    {
      // insert newNode into right subtree and update this node's right pointer
      intoSubTree->right() = recursiveInsert( intoSubTree->right() , newNode );

      // update modified right child's parent properly. 
      intoSubTree->right()->parent() = intoSubTree;
    }
  else // equal, so node is already there!!!
    {
      
    }

  // return updated subtree
  return intoSubTree;
}

void
BinaryTree::insert(const std::string &newVal)
{
  TreeNode *nodeToInsert = new TreeNode(newVal); 
  _root = recursiveInsert( _root, nodeToInsert );
}

TreeNode*
BinaryTree::remove(const std::string &newVal) // preview
{
  return NULL; // fix me LATER !!!!
}

void infixPrint(TreeNode *subTree, ostream &toStream)
{
  if (!subTree)
    return;
  
  infixPrint(subTree->right() , toStream);

  for (int nspaces=0; nspaces < subTree->depth(); nspaces++)
    toStream << "    ";
  
  toStream << *(subTree->data()) << endl;

  infixPrint(subTree->left() , toStream);
}

std::ostream& operator<<(std::ostream &os, const BinaryTree &bt)
{
  infixPrint(bt._root, os);
  return os;
}
