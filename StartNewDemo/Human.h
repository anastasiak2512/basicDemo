//
// Created by anastasiak2512 on 9/14/18.
//

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

class Human : public Mammal {
private:
    float h_weight;
    float h_height;
    int age;
public:
    Human(float weight, float height, int age) : h_weight(weight), h_height(height), age(age) {}

    float calculateSound() {
        float x = h_weight / h_weight;
        return x * h_height * h_weight;
    }

    void makeSound() override {
        calculateSound();
    }

    int useSelfEnergy() override {
        return Mammal::useSelfEnergy();
    }

    float getWeight() const {
        return h_weight;
    }

    void setWeight(float weight) {
        Human::h_weight = weight;
    }

    float getHeight() const {
        return h_height;
    }

    void setHeight(float height) {
        Human::h_height = height;
    }

    bool operator==(const Human &rhs) const {
        return h_weight == rhs.h_weight &&
               h_height == rhs.h_height;
    }

    bool operator!=(const Human &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Human &rhs) const {
        if (h_weight < rhs.h_weight)
            return true;
        if (rhs.h_weight < h_weight)
            return false;
        return h_height < rhs.h_height;
    }

    bool operator>(const Human &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Human &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Human &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const Human &human) {
        os << "h_weight: " << human.h_weight << " h_height: " << human.h_height;
        return os;
    }
};


#endif //DEMOMORE_HUMAN_H
