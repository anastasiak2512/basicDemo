// - Generate constructor
// - Generate getters/setters
// - Generate operators
// - Inherit from Mammal
// - Override/Implement
// - makeSound - write code, surround with 'if'
// - call callSound function, implement
// - Rename with hierarchy

#ifndef DEMOMORE_HUMAN_H
#define DEMOMORE_HUMAN_H

#include <ostream>
#include <iostream>

class Mammal {
public:
    virtual void makeSound() = 0;

    virtual int useSelfEnergy() { return 0; }
};

class Bird : public Mammal {
public:
    void makeSound() override {

    }

    int useSelfEnergy() override {
        return Mammal::useSelfEnergy();
    }
};

class Livestock : public Mammal {
public:
    void makeSound() override {

    }

    int useSelfEnergy() override {
        return Mammal::useSelfEnergy();
    }
};

class Human {
private:
    float h_weight;
    float h_height;
public:

};


#endif //DEMOMORE_HUMAN_H
