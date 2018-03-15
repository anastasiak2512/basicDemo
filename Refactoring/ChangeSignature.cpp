//Use Change Signature (Ctrl+F6 on Windows/Linux, Cmd+F6 on macOS) to:
//- Add another Person Data parameter to the callPerson function.
//- Swap two input parameters in the callPerson function.

typedef struct PersonData {
    int age;
    int id;
    const char *name;
} PersonData;

void callPerson(PersonData *p) {
    //TODO:
}

void usage() {
    PersonData p = {64, 0, "Bjarne Stroustrup"};
    callPerson(&p);
}