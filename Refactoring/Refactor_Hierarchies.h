//Check Rename or Change Signature on sibling functions

#ifndef DEMOMORE_REFACTOR_HIERARCHIES_H
#define DEMOMORE_REFACTOR_HIERARCHIES_H

class A {
public:
    virtual void check(int v, int v2) = 0;
};

class B : public A {
    void check(int v, int v2) override {
        //...
    }
};

class C : public A {
    void check(int v, int v2) override {
        //...
    }
};

#endif //DEMOMORE_REFACTOR_HIERARCHIES_H
