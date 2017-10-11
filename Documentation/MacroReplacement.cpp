//
// Created by AK on 11/10/2017.
//

#define MAGIC 100
#define CALL_DEF(val) int call() { return val; }

#define CLASS_DEF(class_name) class class_##class_name { \
                              public: \
                                  int count_##class_name; \
                                  CALL_DEF(MAGIC) \
                              };

CLASS_DEF(my)