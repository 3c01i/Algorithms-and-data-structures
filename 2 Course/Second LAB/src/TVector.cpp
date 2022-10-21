#include <iostream>
#include "../include/TVector.h"

template <class T>
TVector<T>::TVector(unsigned int _length = 1);
{
  length = _length;
  if (length == 0)
  {
    throw out_of_range("Vector size should be greater than zero");
  }  
  pMemory = new T[length];
}
TVector<T>::TVector(T* array, unsigned int _length);
{
  length = _length;
  if (length == 0)
  {
    throw out_of_range("Array size should be greater than zero");
  }
  if (array == nullptr)
  {
    throw "You array = nullptr";
  }
  for (unsigned int i = 0; i < length; i++ )
  {
    pMemory[i] = array[i];
  }
}
TVector<T>::TVector(const TVector& vector);
{
  if (*this == *vector)
  {
    throw "You vector don`t unique";
  }
  length = vector.length;
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
}
TVector<T>::TVector(TVector&& vector);
{
  if (vector.length == 0 || vector.pMemory == nullptr || *this == vector )
  {
    throw "Error TVector please check you code"
  }
  length = vector.length;
  pMemory = new T[length];
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
  delete[] vector.pMemory;
  vector.length = 0;
}
TVector<T>::~TVector();
{
  if (pMemory == nullptr)
  {
    throw "Never use ~ for nullptr array";
  }
  length = 0;
  delete[] pMemory;
  pMemory =  nullptr;
}
unsigned int TVector<T>::GetLength();
{
  return length;
}
TVector<T>::SetLength(unsigned int newlength);
{
  if (newlength != length)
  {
    T* newpMemory = new T[newlength];
    for (unsigned int i = 0; i < min(length,newlength); i++)
    {
      newpMemory[i] = pMemory[i];      
    }
    delete[] pMemory;
    pMemory = new T[newlength];
    for (unsigned int i = 0; i < min(length,newlength); i++)
    {
       pMemory[i] = newpMemory[i];
    }
    if (newlength > length)
    {
      for (unsigned int i = length; i < newlength; i++)
      {
        pMemory[i] = 0;
      }
    }
    delete[] newpMemory;
    length = newlength;
  }
}

T& TVector<T>::operator[](unsigned int index);
{
  return &pMemory[index];
}
const T& TVector<T>::operator[](unsigned int index);
{
  return &pMemory[index];
}
bool TVector<T>::operator==(const TVector& vector);
{
  if(length != vector.length)
  {
    return false;
  }
  for (unsigned int i = 0; i < length; i++)
  {
    if (pMemory != vector.pMemory)
    {
      return false;
    }
  }
  return true;
}
bool TVector<T>::operator!=(const TVector& vector);
{
  if(length != vector.length)
   {
     return true;
   }
   for (unsigned int i = 0; i < length; i++)
   {
     if (pMemory != vector.pMemory)
     {
       return true;
     }
   }
   return false;
}
TVector TVector<T>::operator+(T value)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] += value;
  }
  return this;  
}
TVector TVector<T>::operator-(T value)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] -= value;
  }
  return this;
}
TVector TVector<T>::operator*(T value)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] *= value;
  }
  return this;
}
TVector TVector<T>::operator+(const TVector& vector);
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] += vector.pMemory[i];
  }
  return this;
}
TVector TVector<T>::operator-(const TVector& vector);
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == n    ullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] -= vector.pMemory[i];
  }
  return this;
}
T TVector<T>::operator*(const TVector& vector);
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == n        ullptr)
  { 
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  T result = 0;
  for (unsigned int i = 0; i < length; i++)
  {
    result *= pMemory[i]*vector.pMemory[i];
  } 
  return result;
}
TVector& TVector<T>::operator=(const TVector& vector);
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == n        ullptr)
  { 
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
  return &this;
}
TVector& TVector<T>::operator=(TVector&& vector);
{
  if (*this == vector)
  {
    throw "Error operation = &&";
  }
  length = vector.length;
  delete[] pMemory;
  pMemory = new T[length];
  for (unsigned int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
  vector.length = 0;
  delete[] vector.pMemory;
  return &this;
}
istream& operator>>(istream& istr, TVector<T>& vector);
{
  for (unsigned int i = 0; i < vector.length; i++)
  {
    istr >> vector.pMemory[i];
  }
  return istr;
}
ostream& operator<<(ostream& ostr, const TVector<T>& vector);
{
  for (unsigned int i = 0; i < vector.length; i++)
  {
    ostr << vector.pMemory[i]<<' ';
  }
  return ostr;
}























