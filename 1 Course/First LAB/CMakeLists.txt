cmake_minimum_required(VERSION 3.21)
project(First_LAB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(First_LAB
        Animals.h
        main.cpp MilckAnimals.h ColdAnimals.h frog.h Snake.h Dog.h Cat.h Animals.cpp Cat.cpp ColdAnimals.cpp Dog.cpp Frog.cpp MilckAnimals.cpp Snake.cpp SetOfAnimals.cpp SetOfAnimals.h)
