//Use Change Signature (Ctrl+F6 on Windows/Linux, Cmd+F6 on macOS) to:
//- Add another Person Data parameter to the callPerson function.
//- Swap two input parameters in the callPerson function.

#define DEFAULT_RATE 100

typedef struct PersonData {
    int int_idx;
    int rate_idx;
    const char *name;
} PersonData;

void callPerson(PersonData *p) {
    p->rate_idx = p->int_idx * 100;

    //TODO: implement actual call
}

void usage() {
    PersonData p = {1, 100, "Bjarne Stroustrup"};
    callPerson(&p);
}