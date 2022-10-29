#include <iostream>
#include "TSqMatrix.h"

template <class T>
TSqMatrix<T>::TSqMatrix()
{
    length = NULL;
    pMemory = nullptr;
}
template<class T>
TSqMatrix<T>::TSqMatrix(int _length)
{
    if (_length > 0)
    {
        length = _length;
        pMemory = new TVector<T>[length];
        for (int i = 0; i < length; i++)
        {
            pMemory[i] = TVector<T>(length);
        }
    }
    else
    {
        throw "TSqMatrix init error";
    }
}
template <class T>
TSqMatrix<T>::~TSqMatrix()
{
    if (pMemory != nullptr)
    {
        delete[] pMemory;
    }
    length = NULL;
    pMemory = nullptr;
}
template <class T>
const int TSqMatrix<T>::GetLength()
{
    return length;
}
template<class T>
bool TSqMatrix<T>::operator==(const TSqMatrix& matrix)
{
    if (length != matrix.length)
    {
        return false;
    }
    if (pMemory == nullptr || matrix.pMemory == nullptr)
    {
        throw "TSqMatrix operation == error";
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
bool TSqMatrix<T>::operator!=(const TSqMatrix& matrix)
{
    if (length != matrix.length)
    {
        return true;
    }
    if (pMemory == nullptr || matrix.pMemory == nullptr)
    {
        throw "TSqMatrix operation == error";
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
TSqMatrix<T> TSqMatrix<T>::operator+(const TSqMatrix<T>& matrix)
{
    if (length != matrix.length || length == 0 || pMemory == nullptr)
    {
        throw "TSqMatrix operator + error";
    }
    TSqMatrix<T> Result = TSqMatrix<T>(length);
    for (int i = 0; i < length; i++)
    {
        Result.pMemory[i] = pMemory[i] + matrix.pMemory[i];
    }
    return Result;
}
template <class T>
TSqMatrix<T> TSqMatrix<T>::operator-(const TSqMatrix<T>& matrix)
{
    if (length != matrix.length || length == 0 || pMemory == nullptr)
    {
        throw "TSqMatrix operator + error";
    }
    TSqMatrix<T> Result = TSqMatrix<T>(length);
    for (int i = 0; i < length; i++)
    {
        Result.pMemory[i] = pMemory[i] - matrix.pMemory[i];
    }
    return Result;
}

template<class T>
TSqMatrix<T> TSqMatrix<T>::operator*(const TSqMatrix& matrix)
{
    if (length != matrix.length || length == 0 || pMemory == nullptr)
    {
        throw "TSqMatrix operator + error";
    }
    TSqMatrix<T> Result = TSqMatrix<T>(length);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            Result[i][j] = 0;
            for (int k = 0; k < length; k++)
            {
                Result[i][j] += matrix.pMemory[i][k] * pMemory[k][j];
            }
        }
    }
    return Result;
}
template<class T>
TVector<T> TSqMatrix<T>::operator*(TVector<T>& vector)
{
    if (length != vector.GetLength() || length == 0 || pMemory == nullptr)
    {
        throw "TSqMatrix operator+ error";
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
TSqMatrix<T> TSqMatrix<T>::operator*(const T input)
{
    if (length == 0 || pMemory == nullptr)
    {
        throw "TSqMatrix operator * error";
    }
    TSqMatrix<T> Result = TSqMatrix<T>(length);
    for (int i = 0; i < length; i++)
    {
        Result.pMemory[i] = pMemory[i] * input;
    }
    return Result;
}
template<class T>
std::istream& operator>>(std::istream& istr, TSqMatrix<T>& matrix)
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
std::ostream& operator<<(std::ostream& ostr, const TSqMatrix<T>& matrix)
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
