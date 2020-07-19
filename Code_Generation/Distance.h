//Generate constructor, destructor, getter/setter, operators (Alt+Ins on Linux/Windows, Cmd+N on macOS)
//Try iter live template.

#ifndef DEMOMORE_DISTANCE_H
#define DEMOMORE_DISTANCE_H

#include <vector>
#include <ostream>

class Base_Distance {
public:
    virtual void self_calculation() = 0;
};

class Distance : public Base_Distance {
private:
    int feet = 0;
    int inches = 0;
//    int dimension;
public:
    Distance(int feet, int inches) : feet(feet), inches(inches) {}

    void some_cycle() {
        std::vector<int> var{1,2,3,4,5};

        //Generate with Iter live template here
        
        //Create a function from usage, update ref-qualifier
        //some_function(var);
    }

};


#endif //DEMOMORE_DISTANCE_H
