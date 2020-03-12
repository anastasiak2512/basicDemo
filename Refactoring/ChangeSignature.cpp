//Use Change Signature (Ctrl+F6 on Windows/Linux, Cmd+F6 on macOS) to:
//- Add another Person Data parameter to the callPerson function.
//- Swap two input parameters in the callPerson function.
//- Use Change Signature to add rate_cf with the default value, use completion for DEFAULT_RATE
//- Extract parameter (extra_cf), check the value from the initializer is used in the usages

#define DEFAULT_RATE 100

typedef struct PersonData {
    int int_idx;
    int rate_idx;
    const char *name;
} PersonData;

void callPerson(PersonData *p, int rate_cf) {
    int extra_cf = 200;
    p->rate_idx = p->int_idx * 100 * extra_cf;

    //TODO: implement actual call
}

void usage() {
    PersonData p = {1, 100, "Bjarne Stroustrup"};
    callPerson(&p, DEFAULT_RATE);
}