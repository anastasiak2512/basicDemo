//
// Created by AK on 15/11/16.
//

#ifndef DEMOMORE_DISTANCE_H
#define DEMOMORE_DISTANCE_H


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

    bool operator<(const Distance &d)
    {
        if (feet < d.feet) {
            return true;
        }
        return feet == d.feet && inches < d.inches;
    }

    //Generate missing operators here (Alt+Ins on Linux/Windows, Cmd+N on macOS)
};


#endif //DEMOMORE_DISTANCE_H
