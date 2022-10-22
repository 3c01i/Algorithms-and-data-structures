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

#endif
