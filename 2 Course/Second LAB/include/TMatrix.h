#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include "TVector.h"

template <class T>
class TMatrix:public TVector<TVector<T>>
{
  protected:
    TVector<T>* pMemory;
    unsigned int length;
  public:
    TMatrix();
    TMatrix(unsigned int length);
    ~TMatrix();

    const unsigned int GetLength();

    using TVector<TVector<T>>::operator[];
    bool operator==(const TMatrix& matrix);
    TMatrix operator+(const TMatrix& matrix);
    TMatrix operator-(const TMatrix& matrix);
    TMatrix operator*(const TMatrix& matrix);
    TMatrix operator*(const T input);



};





#endif
