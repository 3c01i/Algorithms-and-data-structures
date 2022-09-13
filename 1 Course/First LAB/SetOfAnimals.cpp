#pragma once
#include "SetOfAnimals.h"

SetOfAnimals::SetOfAnimals() {
    animalcount = 0;
    animals = nullptr;
}

SetOfAnimals::~SetOfAnimals() {
    if (animals != nullptr)
        delete[] animals;

}

void SetOfAnimals::Print() {
    for (int q = 0; q < animalcount; q++)
    {
        animals[q]->PrintAnimals();
    }
}

void SetOfAnimals::AddAnimals(Animals *animal) {
    if (animalcount== 0)
    {
        animals = new Animals* [1];
        animalcount = 1;
        animals[0] = animal;

    }
    else
    {
        Animals** temporary = new Animals* [animalcount + 1];

        for ( int q = 0; q < animalcount; q++)
        {
            temporary[q] = animals[q];
        }

        delete animals;
        animals = temporary;
        animals[animalcount] = animal;
        animalcount++;


    }
}
