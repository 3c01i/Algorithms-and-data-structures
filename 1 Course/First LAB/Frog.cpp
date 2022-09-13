#include "frog.h"
float frog ::GetJump() {
    return(jump);
}
void frog ::SetJump(float jump) {
    this->jump=jump;
}
float frog ::GetJumpheight() {
    return(jumpheight);
}
void frog ::SetJumpheight(float jumpheight) {
    this->jumpheight=jumpheight;
    
}
void frog::PrintAnimals() {
    std::cout <<"frog"<<endl;
}


