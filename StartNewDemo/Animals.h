//
// Created by AK on 08/06/2018.
//

#ifndef DEMOMORE_ANIMALS_H
#define DEMOMORE_ANIMALS_H

class Mammal {
public:
    virtual int eat() { return 0; }
    virtual void makeSound() = 0;
};

class Animals : public Mammal {
public:
};


#endif //DEMOMORE_ANIMALS_H
