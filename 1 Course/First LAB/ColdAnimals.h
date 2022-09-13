#pragma once
#include "Animals.h"

class ColdAnimals : public Animals {
protected:
    int eat;
public:
    virtual void PrintAnimals();
    int GetEat();
    void SetEat(int eat);
};