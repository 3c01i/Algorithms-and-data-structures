#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>

template <class T>
class TVector
{
  protected:
    int length;
    T* pMemory;
  public:
    TVector();
    TVector(int _length);
    TVector(T* array, int _length);
    TVector(const TVector& vector);
    TVector(TVector&& vector);
    ~TVector();
    int GetLength();
    void SetLength(int newlength);

    T& operator[](int index);
    const T& operator[](int index) const;
    bool operator==(const TVector& vector);
    bool operator!=(const TVector& vector);
    TVector operator+(T value);
    TVector operator-(T value);
    TVector operator*(T value);
    TVector operator+(const TVector& vector);
    TVector operator-(const TVector& vector);
    T operator*(const TVector& vector);
    TVector& operator=(const TVector& vector);
    TVector& operator=(TVector&& vector);

    friend std::istream& operator>>(std::istream& istr, TVector& vector);
    friend std::ostream& operator<<(std::ostream& ostr, const TVector& vector);
};
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
    throw std::range_error("Vector size should be greater than zero");
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
    throw std::range_error("Array size should be greater than zero");
  }
  if (array == nullptr)
  {
    throw std::range_error("You array = nullptr");
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
    throw std::range_error("You vector don`t unique");
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
    throw std::range_error("Error TVector please check you code");
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
    throw std::range_error("kill me");
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
    throw std::range_error("SIGSEGV");
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
    throw std::range_error("SIGSEGV");
  }
}
template <class T>
bool TVector<T>::operator==(const TVector& vector)
{
  if (vector.pMemory == nullptr)
  {
    throw std::range_error("kill me pls");
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
    throw std::range_error("kill me pls");
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
    throw std::range_error("You length = 0 or pMemory = nullptr");
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
    throw std::range_error("You length = 0 or pMemory = nullptr");
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
    throw std::range_error("You length = 0 or pMemory = nullptr");
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
    throw std::range_error("You length = 0 or pMemory = nullptr");
  }
  if (length != vector.length)
  {
    throw std::range_error("Length first vector != length second vector");
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
    throw std::range_error("You length = 0 or pMemory = nullptr");
  }
  if (length != vector.length)
  {
    throw std::range_error("Length first vector != length second vector");
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
    throw std::range_error("You length = 0 or pMemory = nullptr");
  }
  if (length != vector.length)
  {
    throw std::range_error("Length first vector != length second vector");
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
    throw std::range_error("this == this");
  }
  if (length == 0 || pMemory == nullptr || vector.length == 0 || vector.pMemory == nullptr)
  {
    throw std::range_error("You length = 0 or pMemory = nullptr");
  }
  if (length != vector.length)
  {
    throw std::range_error("Length first vector != length second vector");
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

#endif
