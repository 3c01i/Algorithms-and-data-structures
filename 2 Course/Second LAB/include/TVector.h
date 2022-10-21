#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iosteam>

template <class T>
class TVector
{
  protected:
    unsigned int length;
    T* pMemory;
  public:
    TVector(unsigned int _length = 1);
    TVector(T* array, unsigned int _length);
    TVector(const TVector& vector);
    TVector(TVector&& vector);
    ~TVector();
    unsigned int GetLength();
    void SetLength(unsigned int newlength);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
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

    friend istream& operator>>(istream& istr, TVector& vector);
    friend ostream& operator<<(ostream& ostr, const TVector& vector);
};

#endif
