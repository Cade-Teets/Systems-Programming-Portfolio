/*
    Author: Cade Teets
    UWNetID: 2302720
    CSE 374 25su Homework 6: T9 Implementation
    Date: 8/10/25

    Citations: [List external resources or people you consulted]

    Description: [Brief description of the purpose of this program]
*/

// TODO: Includes for functions & types defined elsewhere.
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t9_lib.h"
#include "t9_priv.h"

// TODO: Defines for symbolic constants (if any).
#define MAX_WORD_LENGTH 50
// TODO: Function declarations/prototypes (with appropriate comments).
// T9* Put(T9* dict, char* nums, int n);
void Put(T9* node, const char* word, const char* nums, int n);
char* CharToInt(char* word);
void InitializeDefaultFields(T9* dict);


T9* InitializeEmptyT9() {
    // Maybe make sure the size of the T9 struct 
    // pointer is different than this
    T9* dict = (T9*) malloc(sizeof(T9));
    
    
    // Set all the field pointers to NULL
    InitializeDefaultFields(dict);
    return dict;
}

T9* InitializeFromFileT9(const char* filename) {
    
    T9* dict = InitializeEmptyT9();
    /*
    open file
    get word from line
    for each word , call addWordToT9(dict, word) 
    return file pointer
    */
    if (filename == NULL) {
        // std err out 
        return NULL;
    }
    // create buffer to store line
    char buffer[MAX_WORD_LENGTH];
    FILE* fileT9 = fopen(filename, "r");

    // Check that fileT9 pointer was properly opened
    if (fileT9 == NULL) {
        // std err out 
        return NULL;
    }

    // While not at EOF 
    while (fgets(buffer, MAX_WORD_LENGTH, fileT9) != NULL) {
        AddWordToT9(dict, buffer);
    }
    
    return dict;
}

void AddWordToT9(T9* dict, const char* word) {
//     Post: in ASCII numbers, nums needs to check 
//   if (num > 47 && num < 58 || nums == 35)
    
    char* nums;    

    // Check if all letters in word are valid,
    // then call the charToInt
    int isWord = 1;
    for (int i = 0; i < strlen(word) - 1; i++) {
        char letter = word[i]; 
        if (letter < 'a' || letter > 'z') {
            isWord = 0;
            break;
        }
    }
    if (isWord) {
        nums = CharToInt(word);
    }
    // Word checked to be valid, so now add to t9
    // call put to insert the word to
    // the dict, starting at root (n = 0)
    Put(dict, word, nums, 0);
}

char* PredictT9(T9* dict, const char* nums) {
    // TODO: your code goes here
    return NULL;  // you will want to change this
}

void DestroyT9(T9* dict) {
    if (dict != NULL) {
        free(dict);
    }
    // freeing the whole block is required 
    // so in this case then I want to use recursion to 
    // go through each of the nodes from the root and check
    // if its NULL, i.e. has no children. It could then recurse
    // through each node and check if its null. Then once it hit 
    // then end, then it will recurse through and free all the T9's
    // until it made it back to the top. 

    //Also need to dereference the other strings in the string array and set them to NULL
}

void InitializeDefaultFields(T9* dict) {
    dict->node2 = NULL;
    dict->node3 = NULL;
    dict->node4 = NULL;
    dict->node5 = NULL;
    dict->node6 = NULL;
    dict->node7 = NULL;
    dict->node8 = NULL;
    dict->node9 = NULL;
    dict->node_pound = NULL;
    dict->val = '1'; // Root = 1
}
char* CharToInt(char* word) {
    int len;
    len = strlen(word);
    char code[len];
    char letter;
    for (int i = 0; i < strlen(word) - 1; i++) {
        letter = word[i];
        if (letter >= 'a' && letter <= 'c') {
            code[i] = '2';
        }
        else if (letter >= 'd' && letter <= 'f') {
            code[i] = '3';
        }
        else if (letter >= 'g' && letter <= 'i') {
            code[i] = '4';
        }
        else if (letter >= 'j' && letter <= 'l') {
            code[i] = '5';
        }
        else if (letter >= 'm' && letter <= 'o') {
            code[i] = '6';
        }
        else if (letter >= 'p' && letter <= 's') {
            code[i] = '7';
        }
        else if (letter >= 't' && letter <= 'v') {
            code[i] = '8';
        }
        //else if (letter >= 'w' && letter <= 'z') {
        else {
            code[i] = '9';
        }
        word[i] = code[i];
    }
    return code;
}
// recusively search trie for insertion spot
void Put(T9* node, const char* word, const char* nums, int n) {
    // allocate T9 for new entry
    
    // if a root node, then make a new level and 
    if (node->val == '1') {
        // T9* level = InitializeEmptyT9();
        // Put(node, word, nums, n);
        char val = nums[n];
        //node->

    }
    
    
    
    // Check if at the end of the code and insert
    if (n == strlen(nums) - 1) {
        
        // if there are no words in the pointer array
        if (node->node_pound == NULL) {
            char* new_word = (char*) malloc(sizeof(size_t));
            new_word = word;
            node->node_pound[0] = new_word;
        }
        else {
            int i = 0;
            while (node->node_pound[i] != NULL) {
                i++;
            }
            char* new_word = (char*) malloc(sizeof(size_t));
            new_word = word;
            node->node_pound[i] = new_word;
        }
    }

  
}
