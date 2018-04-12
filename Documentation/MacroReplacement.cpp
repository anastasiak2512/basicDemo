//- Call Quick Doc (Ctrl+Q on Windows/Linux, F1 on macOS) for CLASS_DEF usage. See the macro replacement.
//- Inline (Ctrl+Alt+N on Windows/Linux, ⌥⌘N) CLASS_DEF, one or all usages

#define MAGIC 100
#define CALL_DEF(val, class_name) int call_##class_name() { return val; }

#define CLASS_DEF(class_name) class class_##class_name { \
                              public: \
                                  int count_##class_name; \
                                  CALL_DEF(MAGIC, class_name) \
                              };

CLASS_DEF(A)
CLASS_DEF(B)
CLASS_DEF(C)