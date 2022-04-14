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
BinaryTree::remove(const std::string &val) // preview
{
  TreeNode *toDel = find(val);

  // val is not in tree
  if (!toDel)
    {
      return NULL;
    }

  // case 1: toDel is a leaf
  if (toDel->isLeaf())
    {
      // Think ***HARD*** ... there's a small bug here!
      if (toDel==_root)
        _root=NULL;
      
      TreeNode *parent = toDel->parent();
      if (parent->left() == toDel)
        parent->left()=NULL;
      else
        parent->right()=NULL;

      toDel->parent()=toDel->left()=toDel->right() = NULL;
      return toDel;
    }

  // case 2: toDel has 1 child
  else if (  (toDel->left()   &&  !toDel->right())  ||
             (toDel->left()==NULL   &&  toDel->right()!=NULL)
          )
    {
      if (toDel==_root)
        {
          if (toDel->left())
            _root=toDel->left();
          else
            _root=toDel->right();
          _root->parent() = NULL;
        }
      else
        {
          // find the subtree to "move up"
          TreeNode *subTreeToMove;
          if (toDel->left())
            subTreeToMove = toDel->left();
          else
            subTreeToMove = toDel->right();

          // find toDel's parent and attach the subtree we just found to it
          TreeNode *parent = toDel->parent();
          if (parent->left() == toDel)
            parent->left() = subTreeToMove;
          else
            parent->right() = subTreeToMove;

          // make subtree's parent toDel's parent .
          subTreeToMove->parent() = parent; 
        }

      toDel->parent()=toDel->left()=toDel->right() = NULL;
      return toDel;
    }
  // case 3: toDel has 2 children
  else // must have two children
    {
      // find the largest node in the left subtree.
      //   note: alternative: find the smallest node in the right subtree:
      TreeNode *largestInLeft=toDel->left();

      // as long as we can keep moving right (in the left subtree) ...
      while( largestInLeft->right() )
        {
          // ... keep moving right
          largestInLeft=largestInLeft->right();
        }

      // "recursively" remove the largest value in left subtree.
      //   reality: this node is a leaf or has only one child!
      //             so, only one more "recursive" call is made!
      remove( *(largestInLeft->data()) );

      // update the node we are trying to delete's data
      toDel->data() = largestInLeft->data();

      // cleanup the node we removed so it does not refere back to tree. 
      largestInLeft->parent()=largestInLeft->left()=largestInLeft->right() = NULL;
      return largestInLeft;
    }

  // should never be reached, but the compiler can't tell that.
  //   So, we have to return something. 
  return NULL;
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
