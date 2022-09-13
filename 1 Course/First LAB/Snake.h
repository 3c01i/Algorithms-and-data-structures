#pragma once
#include "ColdAnimals.h"

class Snake : public ColdAnimals {
protected:
    float lenght;
public:
    virtual void PrintAnimals();
    float GetLenght();
    void SetLenght(float lenght);
};