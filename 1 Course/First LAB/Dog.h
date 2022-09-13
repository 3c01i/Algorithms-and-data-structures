#pragma once
#include "MilckAnimals.h"

class Dog : public MilckAnimals {
protected:
    Eating eda;
public:
    virtual void PrintAnimals();
    Eating GetEda();
    void SetEda(Eating eda);
};