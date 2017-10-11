// 1. Add another Person Data parameter to the callPerson function.
// 2. Swap two input parameters in the callPerson function.

typedef struct PersonData {
    int age;
    int id;
    const char *name;
} PersonData;

//Add another parameter
void callPerson(PersonData *p) {
    //TODO:
}

void usage() {
    PersonData p = {64, 0, "Bjarne Stroustrup"};
    callPerson(&p);
}