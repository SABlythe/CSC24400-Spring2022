#include <iostream>

#include "TreeNode.hpp"
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  BinaryTree myTree;
  for (int i=1; i<argc; i++)
    {
      myTree.insert(argv[i]);
    }

  cout << myTree << endl;

  cout << "What value should I delete ?";
  string valToFind;
  cin >> valToFind;
  TreeNode *foundAt = myTree.find(valToFind);

  if (foundAt != NULL)
    {    
      myTree.remove(valToFind);
       cout << "and here is the updated tree!" << endl
	   << myTree << endl;
    }
  else
    cout << "Not found in tree!" << endl;
  
  return 0;
}
