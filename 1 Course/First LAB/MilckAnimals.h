#pragma once
#include "Animals.h"

class MilckAnimals : public Animals {
protected:
    int drink;
public:
    int GetDrink();
    void SetDrink(int drink);
    virtual void PrintAnimals();
};