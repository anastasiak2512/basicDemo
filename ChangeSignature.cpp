//
// Created by AK on 30/10/16.
//

#include "ChangeSignature.h"

typedef struct PersonData {
    int age;
    int id;
    const char *name;
} PersonData;

//Add another parameter
void callPerson(PersonData& p1) {
    //TODO:
}

void usage() {
    PersonData p = {64, 0, "Bjarne Stroustrup"};

    callPerson(p);
}