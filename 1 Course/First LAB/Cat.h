#pragma once
#include "MilckAnimals.h"

class Cat : public MilckAnimals {
protected:
    Eating eda;
public:
    virtual void PrintAnimals();
    Eating GetEda();
    void SetEda(Eating eda);
};