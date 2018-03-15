//
// Created by AK on 15/03/2018.
//

#ifndef DEMOMORE_PERSON_H
#define DEMOMORE_PERSON_H


#include <tuple>
#include <ostream>

namespace Live {

    class Mammal {
    public:
        virtual void makeSound() = 0;

        virtual float bm_index() { return 0.0; }

        friend std::ostream &operator<<(std::ostream &os, const Mammal &mammal) {
            return os;
        }
    };

    class Bird : public Mammal {
    public:
        void makeSound() override {

        }

        float bm_index() override {
            return Mammal::bm_index();
        }
    };

    class Human : public Mammal {
    private:
        float weight;
        float height;
        int   age{};
    public:
        Human(float weight, float height) : weight(weight), height(height) {}

        void makeSound() override {

        }

        float squared_height() {
            return height * height;
        }

        float bm_index() override {
            if (height != 0) {
                return (weight) / (squared_height());
            } else {
                return -1;
            }
        }

        float getWeight() const {
            return weight;
        }

        void setWeight(float weight) {
            Human::weight = weight;
        }

        float getHeight() const {
            return height;
        }

        void setHeight(float height) {
            Human::height = height;
        }

        bool operator==(const Human &rhs) const {
            return std::tie(weight, height) == std::tie(rhs.weight, rhs.height);
        }

        bool operator!=(const Human &rhs) const {
            return !(rhs == *this);
        }

        bool operator<(const Human &rhs) const {
            if (weight < rhs.weight)
                return true;
            if (rhs.weight < weight)
                return false;
            return height < rhs.height;
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
            os << static_cast<const Mammal &>(human) << " weight: " << human.weight << " height: " << human.height;
            return os;
        }
    };
}


#endif //DEMOMORE_PERSON_H
