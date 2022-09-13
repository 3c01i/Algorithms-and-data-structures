#include "Animals.h"
#include "MilckAnimals.h"
#include "Cat.h"
#include "ColdAnimals.h"
#include "Dog.h"
#include "frog.h"
#include "Snake.h"
#include "SetOfAnimals.h"
#include <iostream>
using namespace std;

int main(){
  MilckAnimals pig;
  Cat myrka;
  SetOfAnimals animalszoo;
  pig.SetDivide(Divide::vseyad);
  myrka.SetName("lol");
  myrka.SetWeight(54);
  animalszoo.AddAnimals(&pig);
  animalszoo.AddAnimals(&myrka);
  animalszoo.Print();
  return 0;
}