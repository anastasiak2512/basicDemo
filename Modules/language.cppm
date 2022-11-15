export module Talk; // declares the primary module interface unit for named module 'A'

// hello() will be visible by translations units importing 'A'
export char const* hello() { return "hello"; }

// world() will NOT be visible.
char const* world() { return "world"; }

export
{
    char const* English()  { return "Hi"; }
}

export namespace hi
{
    char const* hi_French()  { return "Salut!"; }
    char const* hi_German()  { return "Hallo!"; }
    char const* hi_Dutch()  { return "Hoi!"; }
}