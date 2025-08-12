#ifndef T9_PRIV_H_
#define T9_PRIV_H_

typedef struct T9 {
    // Pointer to node for each number on the T9 Keypad
    // plus a pointer to a word
    T9* node2;
    T9* node3;
    T9* node4;
    T9* node5;
    T9* node6;
    T9* node7;
    T9* node8;
    T9* node9;
    char val;
    char** node_pound;
} T9;

#endif  // T9_PRIV_H_
