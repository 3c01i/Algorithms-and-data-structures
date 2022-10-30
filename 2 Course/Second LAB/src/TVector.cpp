#include <iostream>
#include "TVector.h"

template <class T>
TVector<T>::TVector()
{
  length = NULL;
  pMemory = nullptr;
}
template <class T>
TVector<T>::TVector(int _length)
{
  length = _length;
  if (length <= 0)
  {
    throw "Vector size should be greater than zero";
  }  
  pMemory = new T[length];
  for (int i = 0; i < length; i++ )
  {
    pMemory[i] = 0;
  }
}
template <class T>
TVector<T>::TVector(T* array, int _length)
{
  length = _length;
  if (length == 0)
  {
    throw "Array size should be greater than zero";
  }
  if (array == nullptr)
  {
    throw "You array = nullptr";
  }
  for (int i = 0; i < length; i++ )
  {
    pMemory[i] = array[i];
  }
}
template <class T>
TVector<T>::TVector(const TVector& vector)
{
  if ( *this == vector || vector.length <= 0 || vector.pMemory == nullptr )
  {
    throw "You vector don`t unique";
  }
  length = vector.length;
  pMemory = new T[length];
  for (int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
}
template <class T>
TVector<T>::TVector(TVector&& vector)
{
  if (vector.length == 0 || vector.pMemory == nullptr || *this == vector )
  {
    throw "Error TVector please check you code";
  }
  length = vector.length;
  pMemory = vector.pMemory;
  delete[] vector.pMemory;
  vector.length = 0;
  vector.pMemory = nullptr;
}
template <class T>
TVector<T>::~TVector()
{
  length = 0;
  if (pMemory != nullptr)
  {
    delete[] pMemory;
  }
  pMemory =  nullptr;
}
template <class T>
int TVector<T>::GetLength()
{
  return length;
}
template <class T>
void TVector<T>::SetLength(int newlength)
{
  if (newlength <= 0 )
  {
    throw "kill me";
  }
  if (newlength != length)
  {
    T* newpMemory = new T[newlength];
    for (int i = 0; i < std::min(length,newlength); i++)
    {
      newpMemory[i] = pMemory[i];      
    }
    delete[] pMemory;
    pMemory = new T[newlength];
    for (int i = 0; i < std::min(length,newlength); i++)
    {
       pMemory[i] = newpMemory[i];
    }
    if (newlength > length)
    {
      for (int i = length; i < newlength; i++)
      {
        pMemory[i] = 0;
      }
    }
    delete[] newpMemory;
    length = newlength;
  }
}

template <class T>
T& TVector<T>::operator[](int index)
{
  if (pMemory != nullptr)
  {
  return pMemory[index];
  }
  else
  {
    throw "SIGSEGV";
  }
}
template <class T>
const T& TVector<T>::operator[](int index) const
{
  if (pMemory != nullptr)
  {
    return pMemory[index];
  }
  else
  {
    throw "SIGSEGV";
  }
}
template <class T>
bool TVector<T>::operator==(const TVector& vector)
{
    if (vector.pMemory == nullptr)
    {
      throw "kill me pls";
    }
  if(length != vector.length)
  {
    return false;
  }
  for (int i = 0; i < length; i++)
  {
    if (pMemory[i] != vector.pMemory[i])
    {
      return false;
    }
  }
  return true;
}
template <class T>
bool TVector<T>::operator!=(const TVector& vector)
{
    if (vector.pMemory == nullptr)
    {
        throw "kill me pls";
    }
  if(length != vector.length)
   {
     return true;
   }
   for (int i = 0; i < length; i++)
   {
     if (pMemory[i] != vector.pMemory[i])
     {
       return true;
     }
   }
   return false;
}
template <class T>
TVector<T> TVector<T>::operator+(T value)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  TVector<T> Result = TVector<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] + value;
  }
  return Result;
}
template <class T>
TVector<T> TVector<T>::operator-(T value)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  TVector<T> Result = TVector<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] - value;
  }
  return Result;
}
template <class T>
TVector<T> TVector<T>::operator*(T value)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  TVector<T> Result = TVector<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] * value;
  }
  return Result;
}
template <class T>
TVector<T> TVector<T>::operator+(const TVector& vector)
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  TVector<T> Result = TVector<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] + vector.pMemory[i];
  }
  return Result;
}
template <class T>
TVector<T> TVector<T>::operator-(const TVector& vector)
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == nullptr)
  {
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  TVector<T> Result = TVector<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] - vector.pMemory[i];
  }
  return Result;
}
template <class T>
T TVector<T>::operator*(const TVector& vector)
{
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == nullptr)
  { 
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  T Result = 0;
  for (int i = 0; i < length; i++)
  {
    Result += pMemory[i]*vector.pMemory[i];
  } 
  return Result;
}
template <class T>
TVector<T>& TVector<T>::operator=(const TVector& vector)
{
  if (*this == vector)
  {
    throw "this == this";
  }
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == nullptr)
  { 
    throw "You length = 0 or pMemory = nullptr";
  }
  if (length != vector.length)
  {
    throw "Length first vector != length second vector";
  }
  delete[] pMemory;
  pMemory = new T[vector.length];
  for (int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
  length = vector.length;
  return *this;
}

template <class T>
TVector<T>& TVector<T>::operator=(TVector&& vector)
{
  if (*this == vector)
  {
    throw "Error operation = &&";
  }
  length = vector.length;
  delete[] pMemory;
  pMemory = new T[length];
  for (int i = 0; i < length; i++)
  {
    pMemory[i] = vector.pMemory[i];
  }
  vector.length = 0;
  delete[] vector.pMemory;
  vector.pMemory = nullptr;
  return *this;
}
template <class T>
std::istream& operator>>(std::istream& istr, TVector<T>& vector)
{
  for (int i = 0; i < vector.length; i++)
  {
    istr >> vector.pMemory[i];
  }
  return istr;
}
template <class T>
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& vector)
{
  for (int i = 0; i < vector.length; i++)
  {
    ostr << vector.pMemory[i]<<' ';
  }
  return ostr;
}























