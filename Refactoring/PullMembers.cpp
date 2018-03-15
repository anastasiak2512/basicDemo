// Pull up produceMilk member
// Check related members will be suggested
//

#include <string>
#include <iostream>

enum class Sex {
    Male,
    Female
};

class Mammal {
public:
    virtual void makeLoudSound() = 0;
};

class Human : public Mammal {
private:
    float weight{};
    Sex mf;
    std::string name;
public:
    void sayHello() {
        std::cout << "Hello, " + name + "\n";
    }

    float some_magic_num(float weight) {
        return 0;
    }

    float produceMilk() {
        if (mf == Sex::Male) {
            return 0;
        } else {
            return some_magic_num(weight);
        }
    }
};