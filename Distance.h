//
// Created by AK on 15/11/16.
//

#ifndef DEMOMORE_DISTANCE_H
#define DEMOMORE_DISTANCE_H


class Distance {
private:
    int feet;
    int inches;
public:
    Distance() : feet(0) , inches(0)
    {}

    Distance(int feet , int inches) : feet(feet) , inches(inches)
    {}

    Distance operator-()
    {
        feet = -feet;
        inches = -inches;
        return Distance(feet , inches);
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
