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
  /*
  cout <<" Adding:" << elementToAdd << ", with "
       << _elementCount << " of " << _totalSize
       << " slots already full" << endl;
  */
  
  if (_elementCount==_totalSize)
    {
      /*
      cerr << "UH-OH: array is already full! Not inserted!" << endl;
      return;
      */
      //1 . build a new bigger array.
      _totalSize+=10;
      int *biggerArray = new int[_totalSize];

      // 1.5 copy the old array contents into the new bigger one ...
      for (int index=0; index<_elementCount; index++)
	biggerArray[index]= _array[index];
      
      // 2. set the _array instance variable to be this new bigger array
      _array = biggerArray;
      
    }
  
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
