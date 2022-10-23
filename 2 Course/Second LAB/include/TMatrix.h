#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include "TVector.h"

template <class T>
class TMatrix:public TVector<TVector<T>>
{
  protected:
    TVector<T>* pMemory;
    int length;
  public:
    TMatrix();
    TMatrix(int _length);
    ~TMatrix();

    const int GetLength();

    using TVector<TVector<T>>::operator[];
    bool operator==(const TMatrix& matrix);
    bool operator!=(const TMatrix& matrix);
    TMatrix operator+(const TMatrix& matrix);
    TMatrix operator-(const TMatrix& matrix);
    TMatrix operator*(const TMatrix& matrix);
    TVector<T> operator*(TVector<T>& vector);
    TMatrix operator*(const T input);

    friend std::istream& operator>>(std::istream& istr, TMatrix& matrix);
    friend std::ostream& operator<<(std::ostream& ostr, const TMatrix& matrix);

};





#endif
