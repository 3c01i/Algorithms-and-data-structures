#pragma once
#include <iostream>
using namespace std;
class MyString{
protected:
    char* string;
    int len;
public:
    //Конструкторы
    MyString(char *_string);
    MyString();
    MyString(int _len);
    MyString(MyString& obj);
    ~MyString();
    //Методы
    int GetLen();
    int StrLen(char *string);
    char GetChar(int index);
    void SetStr(int _len, char *_string);
    int Find(char c);
    int Find(const MyString word);
    void Split(MyString **p, int& counter, char c);
    void FindAll(const MyString word, int& counter, int *index);
    char MostFreq();
    void Characters(char *&ltrs, int& size);
    void CharQuantity(char *&ltrs, int *&quant, int& size);

    //Операторы
    bool operator<(const MyString& p);
    bool operator>(const MyString& p);
    MyString& operator=(const MyString& p);
    char& operator[](const int index);
    const char& operator[](const int index) const;
    MyString operator*(int k);

    friend bool operator==(const MyString& p, const MyString& q);
    friend MyString operator+(const MyString& p, const MyString& q);
    friend MyString operator+(const MyString& p, const char c);
    friend ostream& operator<<(ostream& t, const MyString& p);
    friend istream& operator>>(istream& t, MyString& p);
};
