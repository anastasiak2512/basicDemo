// Turn on Refactoring modal dialog: Settings/Preferences | Editor | Code Editing -> Refactorings | Specify refactoring options | In the modal dialogs
// Rename: feet -> dfeet
// Update both: code and non-code usages, which includes:
// - member name
// - all its usages
// - comment text
// - stream output operator text

#include <ostream>

class CustomDistance {
private:
    int feet = 0;
    int inches = 0;
public:
    CustomDistance(int feet, int inches) : feet(feet) , inches(inches)
    {}

    CustomDistance operator-()
    {
        feet = -feet;
        inches = -inches;
        return {feet, inches};
    }

    bool operator<(const CustomDistance &d) const
    {
        if (feet < d.feet) {
            return true;
        }
        return feet == d.feet && inches < d.inches;
    }

    //Print: feet and inches
    friend std::ostream &operator<<(std::ostream &os, const CustomDistance &distance) {
        os << "feet: " << distance.feet << " inches: " << distance.inches;
        return os;
    }
};
