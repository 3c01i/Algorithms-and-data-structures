#pragma once
#include <iostream>
using namespace std;

class Complex{
protected:

    double Im;
    double Re;

public:
    double GetIm();
    void SetIm(double Im);
    double GetRe();
    void SetRe(double Re);
    double ModComplex();
    Complex ExpComplex(double n);
    double injection();



    void Print();
    void PrintComplex();


    Complex();
    Complex(double ValueIm,double ValueRe);
    Complex(const Complex &other);
    //
    Complex operator+ (Complex STerm);
    Complex operator= (Complex Second);
    Complex operator* (Complex STerm);
    Complex operator/ (Complex STerm);



    friend istream& operator>>(istream &in, Complex& Output);
};
ostream& operator<< (ostream& os, Complex Input);
istream& operator>>(istream &in, Complex& Output);

bool operator== (Complex &First,Complex &Second);
bool operator!= (Complex &First,Complex &Second);