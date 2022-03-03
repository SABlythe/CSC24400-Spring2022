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

  const PFA&  operator+=(int newElement) {addElement(newElement); return *this; }   
  const PFA&  operator+=(const PFA &otherArray);
  
  std::ostream& print(std::ostream &toStream) const;

  friend std::ostream& operator<<(std::ostream &os, const PFA &pfa);
};

#endif
