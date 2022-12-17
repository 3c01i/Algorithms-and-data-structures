#include <iostream>
#include "TMatrix.h"

template <class T>
TMatrix<T>::TMatrix()
{
  length = NULL;
  pMemory = nullptr;
}
template<class T>
TMatrix<T>::TMatrix(int _length)
{
  if (_length > 0)
  {
    length = _length;
    pMemory = new TVector<T>[length];
    for (int i = 0; i < length; i++)
    {
      pMemory[i] = TVector<T>(i+1);
    }
  }
  else
  {
    throw "TMatrix init error";
  }
}
template <class T>
TMatrix<T>::~TMatrix()
{
  if (pMemory != nullptr)
  {
    delete[] pMemory;
  }
  length = NULL;
  pMemory = nullptr;
}
template <class T>
const int TMatrix<T>::GetLength()
{
  return length;
}
template<class T>
bool TMatrix<T>::operator==(const TMatrix& matrix)
{
  if (length != matrix.length)
  {
    return false;
  }
  if (pMemory == nullptr || matrix.pMemory == nullptr)
  {
    throw "TMatrix operation == error";
  }
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (pMemory[i] != matrix.pMemory[i])
      {
        return false;
      }
    }
    return true;
  }
}
template<class T>
bool TMatrix<T>::operator!=(const TMatrix& matrix)
{
  if (length != matrix.length)
  {
    return true;
  }
  if (pMemory == nullptr || matrix.pMemory == nullptr)
  {
    throw "TMatrix operation == error";
  }
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (pMemory[i] != matrix.pMemory[i])
      {
        return true;
      }
    }
    return false;
  }
}
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& matrix)
{
  if (length != matrix.length || length == 0 || pMemory == nullptr)
  {
    throw "TMatrix operator + error";
  }
  TMatrix<T> Result = TMatrix<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] + matrix.pMemory[i];
  }
  return Result;
}
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& matrix)
{
  if (length != matrix.length || length == 0 || pMemory == nullptr)
  {
    throw "TMatrix operator + error";
  }
  TMatrix<T> Result = TMatrix<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] - matrix.pMemory[i];
  }
  return Result;
}

template<class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix& matrix)
{
  if (length != matrix.length || length == 0 || pMemory == nullptr)
  {
    throw "TMatrix operator + error";
  }
  TMatrix<T> Result = TMatrix<T>(length);
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      Result[i][j] = 0;
      for (int k = j; k <= i; k++)
      {
        Result[i][j] += matrix.pMemory[i][k] * pMemory[k][j];
      }
    }
  }
  return Result;
}
template<class T>
TVector<T> TMatrix<T>::operator*(TVector<T>& vector)
{
  if (length != vector.GetLength() || length == 0 || pMemory == nullptr)
  {
    throw "TMatrix operator+ error";
  }
  TVector<T> Result = TVector<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result[i] = 0;
    for (int j = 0; j <= i; j++)
    {
      Result[j] += pMemory[i][j] * vector[i];
    }
  }
  return Result;
}
template<class T>
TMatrix<T> TMatrix<T>::operator*(const T input)
{
  if (length == 0 || pMemory == nullptr)
  {
    throw "TMatrix operator * error";
  }
  TMatrix<T> Result = TMatrix<T>(length);
  for (int i = 0; i < length; i++)
  {
    Result.pMemory[i] = pMemory[i] * input;
  }
  return Result;
}
template<class T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& matrix)
{
  for (int i = 0; i < matrix.length; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      istr >> matrix.pMemory[i][j];
    }
  }
  return istr;
}
template<class T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& matrix)
{
  for (int i = 0; i < matrix.length; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      ostr << matrix.pMemory[i][j] << ' ';
    }
    ostr << '\n';
  }
  return ostr;
}