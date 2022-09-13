#include "Animals.h"
int Animals ::GetWeight() {
    return (weight);
}
void Animals ::SetWeight(int weight) {
    this->weight = weight;
}
std::string Animals :: GetName() {
    return(name);
}
void Animals ::SetName(std::string name) {
    this->name = name;
}
Divide Animals :: GetDivide() {
    return(divide);
}
void Animals :: SetDivide(Divide sdivide){
    this->divide = sdivide;
    
}
void Animals::PrintAnimals() {
    std::cout <<"animals"<<endl;
}
