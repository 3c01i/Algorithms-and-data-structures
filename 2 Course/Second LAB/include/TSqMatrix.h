#pragma once
#ifndef __TSqMATRIX_H__
#define __TSqMATRIX_H__

#include <iostream>
#include "TVector.h"

template <class T>
class TSqMatrix:protected TVector<TVector<T>>
{
    using TVector<TVector<T>>::pMemory;
    using TVector<TVector<T>>::length;
public:
    TSqMatrix();
    TSqMatrix(int _length);
    ~TSqMatrix();

    const int GetLength();

    using TVector<TVector<T>>::operator[];
    bool operator==(const TSqMatrix& matrix);
    bool operator!=(const TSqMatrix& matrix);
    TSqMatrix operator+(const TSqMatrix& matrix);
    TSqMatrix operator-(const TSqMatrix& matrix);
    TSqMatrix operator*(const TSqMatrix& matrix);
    TVector<T> operator*(TVector<T>& vector);
    TSqMatrix operator*(const T input);

    friend std::istream& operator>>(std::istream& istr, TSqMatrix& matrix);
    friend std::ostream& operator<<(std::ostream& ostr, const TSqMatrix& matrix);

};





#endif