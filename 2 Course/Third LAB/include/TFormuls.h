#ifndef TFORMULS_H
#define TFORMULS_H

#include <iostream>
#include "TStack.h"
#include "vector"

int priority(char a) {
  int temp;
  if (a == '^')
    temp = 1;
  else  if (a == '*' || a == '/')
    temp = 2;
  else  if (a == '+' || a == '-')
    temp = 3;
  return temp;
}

class TFormuls
{
private:
  std::string infix;
  std::string postfix;
  TStack<char> element;
  TStack<char> operand;
public:
  
};

#endif
