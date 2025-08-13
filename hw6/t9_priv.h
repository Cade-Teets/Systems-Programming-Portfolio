#ifndef T9_PRIV_H_
#define T9_PRIV_H_

typedef struct T9 {
    // Pointer to node for each number on the T9 Keypad
    // i = 0 -> 2, ..., i
    T9* node[8];
    char** val;
    int list_count;
} T9;

#endif  // T9_PRIV_H_
