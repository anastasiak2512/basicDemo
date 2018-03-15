// Rename: feet -> dfeet
// Update both: code and non-code usages, which includes:
// - member name
// - all its usages
// - comment text
// - stream output operator text

#include <ostream>

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

    friend std::ostream &operator<<(std::ostream &os, const Distance &distance) {
        os << "feet: " << distance.feet << " inches: " << distance.inches;
        return os;
    }
};
