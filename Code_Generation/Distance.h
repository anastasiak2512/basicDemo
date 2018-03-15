//Generate constructor, destructor, getter/setter, operators (Alt+Ins on Linux/Windows, Cmd+N on macOS)
//Try iter live template.

#ifndef DEMOMORE_DISTANCE_H
#define DEMOMORE_DISTANCE_H

#include <vector>

class Distance {
private:
    int feet = 0;
    int inches = 0;
public:
    Distance(int feet , int inches) : feet(feet) , inches(inches)
    {}

    Distance operator-()
    {
        feet = -feet;
        inches = -inches;
        return {feet, inches};
    }

    bool operator<(const Distance &d) const
    {
        if (feet < d.feet) {
            return true;
        }
        return feet == d.feet && inches < d.inches;
    }

    void some_cycle() {
        std::vector<int> var{1,2,3,4,5};

        //Generate with Iter live template here
    }

};


#endif //DEMOMORE_DISTANCE_H
