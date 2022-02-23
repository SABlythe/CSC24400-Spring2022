#ifndef _PFA_HPP_
#define _PFA_HPP_

#include <iostream>

class PFA
{
private:
  int *_array;       // actual array data
  int _elementCount; // number of real elements
  int _totalSize;    // number of elements, including umused portion. 
public:
  PFA(int maxSize=10);

  void addElement(int elementToAdd);

  std::ostream& print(std::ostream &toStream) const;

  friend std::ostream& operator<<(std::ostream &os, const PFA &pfa);
};

#endif
