//
// Created by AK on 30/10/16.
//

//==========================================================
// Local DFA
//==========================================================

enum class Color { Red, Blue, Green, Yellow };

void do_shadow_color(int shadow) {
    Color cl1, cl2;

    if (shadow)
        cl1 = Color::Red, cl2 = Color::Blue;
    else
        cl1 = Color::Green, cl2 = Color::Yellow;

    if (cl1 == Color::Red || cl2 == Color::Yellow) {

    }
}

//==========================================================

void Sample2(int flag) {
    Color c;

    switch (flag) {
        case 0:
            c = Color::Red;
            break;
        case 1:
            c = Color::Blue;
            break;
        default:
            c = Color::Green;
    }

    switch (c) {
        case Color::Red:
            break;
        case Color::Blue:
            break;
        case Color::Green:
            break;
        case Color::Yellow:
            break;
    }

}

//==========================================================

enum class States {
    Started, Stopped, Waiting
};

void Sample3(States current) {
    current = States::Started;

    if (current == States::Stopped) {
        //...
    }

    //...
}

//==========================================================

enum CollisionType {
    None, Left, Right, Top, Bottom
};


class Ball {
public:
    int getSpeedX() { return 0; }
    int getSpeedY() { return 0; }
};

bool Sample4(Ball& ball, CollisionType type) {
    int mulX = 1, mulY = 1;

    switch (type)
    {
        case Left:
            if (ball.getSpeedX() < 0) mulX = -1;
            break;
        case Right:
            if (ball.getSpeedX() > 0) mulX = -1;
            break;
        case Top:
            if (ball.getSpeedY() < 0) mulY = -1;
            break;
        case Bottom:
            if (ball.getSpeedY() > 0) mulY = -1;
            break;
    }

    if (mulX == -1 && mulY == -1)
    {
        //do smth:...
        return true;
    } else
    {
        return false;
    }
}

int check() {
    while(true) {}
    return 0;
}

//==========================================================

//Loop conditions

void test_loop() {

    for (int i = 0; i < 10;) {
        if (i > 5)
            break;
    }

    {
        int x = 10;
        while (x > 0) {
            int &ref = {x};
            --ref;
        }
    }

    {
        int x = 10;
        int *p = &x;
        ([p, x]() {
            while (x > 0)
                *p = 0;
        })();
    }
}

//==========================================================
//Dangling pointer

struct node
{
    int data;
    struct node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void process();
    void add_node(int n);
};

void linked_list::add_node(int n)
{
    node *tmp = new node;
    tmp->data = n;
    tmp->next = nullptr;

    if(head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void linked_list::process() {
    for (node *pt = head; pt != nullptr; pt = pt->next) {
        delete pt;
    }
}

//==========================================================
// Global DFA
//==========================================================

// Unused value

void use(int n) {;}

class UseVal {
    int field;

    void operate() {
        field = 1001;
    }

    void doOperation() {
        use(field);
        operate();
    }

public:
    void callOperation() {
        doOperation();
    }
};
//==========================================================

//Null dereferencing

class Deref {
    int* foo() {
        return nullptr;
    }

public:
    void bar() {
        int* buffer = foo();
        buffer[0] = 0;
    }
};

//==========================================================

// Unreachable call sites

bool always_false() {
    return false;
}

static void myOperation() {}


void handleCondOperation() {
    if (always_false())
        myOperation();
}

//==========================================================

// Dangling pointer

static void delete_ptr(int* ptr) {
    delete ptr;
}

int handle_pointer() {
    int* int_ptr = new int;

    delete_ptr(int_ptr);
    *int_ptr = 1;

    return 0;
}
//==========================================================

// Unreachable code

enum State {
    Processing,
    Idle,
    Stop
};

void log_msg(const char *message) {}

State nextState;

static void setState(State state) {
    nextState = state;
}

static void Consume(State state) {
    switch (state) {
        case Processing: log_msg("Processing");
            break;
        case Idle: log_msg("Idle");
            break;
        case Stop: log_msg("Stop!");
            break;
    }
}

void Process() {
    Consume(Processing);
    Consume(Idle);
}

//==========================================================

// Array index out of bounds

#include <array>

void aioob() {
    int buffer[100];

    for (int i = 0; i <= 100; i++)
        buffer[i] = 0; // buffer overflow when i is equal to 100


    std::array<int, 3> a = {1, 2, 3};
    a[a.size()] = 4; // a overflow when index is equal to a.size()
}

//==========================================================
