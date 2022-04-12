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

  cout << "What value should I look for ?";
  string valToFind;
  cin >> valToFind;
  TreeNode *foundAt = myTree.find(valToFind);

  if (foundAt != NULL)
    cout << "Here it is:" << *foundAt << endl;
  else
    cout << "Not found in tree!" << endl;
  
  return 0;
}
