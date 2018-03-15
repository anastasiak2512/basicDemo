//- Call Quick Doc (Ctrl+Q on Windows/Linux, F1 on macOS) for CLASS_DEF usage. See the macro replacement.
//- Inline (Ctrl+Alt+N on Windows/Linux, ⌥⌘N) CLASS_DEF, one or all usages

#define MAGIC 100
#define CALL_DEF(val) int call() { return val; }

#define CLASS_DEF(class_name) class class_##class_name { \
                              public: \
                                  int count_##class_name; \
                                  CALL_DEF(MAGIC) \
                              };

CLASS_DEF(my)
CLASS_DEF(his)
CLASS_DEF(her)