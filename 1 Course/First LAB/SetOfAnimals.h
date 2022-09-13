#pragma once
#include "Animals.h"
class SetOfAnimals
{
public:
    SetOfAnimals();
    ~SetOfAnimals();

    void Print();
    void AddAnimals(Animals* animal);

private:
    Animals** animals;
    int animalcount;
};