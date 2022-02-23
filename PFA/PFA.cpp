#include "PFA.hpp"

using namespace std;

PFA::PFA(int maxSize)
{
  _totalSize = maxSize;
  _array = new int [_totalSize];
  _elementCount = 0; // no elements in array yet ...
  
  for (int index=0; index < _totalSize; index++)
    _array[index]=0;
}

void
PFA::addElement(int elementToAdd)
{
  _array[_elementCount] = elementToAdd;
  _elementCount++;
}

std::ostream&
PFA::print(std::ostream &toStream) const
{
  for(int index=0; index< _elementCount; index++)
    toStream << _array[index] << endl;
  
  return toStream;
}

std::ostream& operator<<(std::ostream &os, const PFA &pfa)
{
  return pfa.print(os);
}
