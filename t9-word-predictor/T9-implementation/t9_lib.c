/*
    Author: Cade Teets
    UWNetID: 2302720
    CSE 374 25su Homework 6: T9 Implementation
    Date: 8/10/25

    Citations: [List external resources or people you consulted]
    https://www.geeksforgeeks.org/c/strncpy-function-in-c/
    https://www.geeksforgeeks.org/c/strlen-function-in-c/
    Description: [Brief description of the purpose of this program]
        Program can create a dictionary to hold words in a Trie.
    The words are converted into T9 codes and to get a word
    one uses the T9 code and a word is returned. Multiple
    words can share the same code and are iterated by using
    the pound key after the code.
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t9_lib.h"
#include "t9_priv.h"


#define MAX_WORD_LENGTH 50
// add comments here
void CharToT9Code(const char* word, char* code);
void Put(T9* node, const char* word, char* nums, int n);
void InitializeDefaultFields(T9* dict);
T9* GetNode(T9* dict, const char* nums, int n);

T9* InitializeEmptyT9() {
// Maybe make sure the size of the T9 struct
// pointer is different than this
    T9* dict = (T9*) malloc(sizeof(T9));
    if (dict == NULL) {
        return NULL;
    }
    // Set all the field pointers to NULL
    InitializeDefaultFields(dict);
    return dict;
}

T9* InitializeFromFileT9(const char* filename) {
    T9* dict = InitializeEmptyT9();
    if (filename == NULL) {
        return NULL;
    }
    // create buffer to store line
    char buffer[MAX_WORD_LENGTH];
    FILE* fileT9 = fopen(filename, "r");
    // Check that fileT9 pointer was properly opened
    if (fileT9 == NULL) {
        return NULL;
    }

    // While not at EOF
    while (fgets(buffer, MAX_WORD_LENGTH, fileT9) != NULL) {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
        // Remove/Replace newline with null terminator
        buffer[len - 1] = '\0';
        len--;
        }
        AddWordToT9(dict, buffer);
    }
    fclose(fileT9);
    return dict;
}

void AddWordToT9(T9* dict, const char* word) {
    if (word != NULL && strlen(word) >= 1) {
        // Add one for '\0'
        int len = strlen(word) + 1;
        char* code = (char*) malloc(sizeof(char) * len);
        if (code == NULL) {
                return;
        }
        // Check if all letters in word are valid,
        // then call the CharToT9Code
        int isWord = 1;
        for (int i = 0; i < strlen(word); i++) {
            char letter = word[i];
            if (letter < 'a' || letter > 'z') {
                isWord = 0;
                break;
            }
        }
        if (isWord) {
            CharToT9Code(word, code);
            Put(dict, word, code, 0);
        }
        free(code);
    }
}

char* PredictT9(T9* dict, const char* nums) {
    // Check for invalid preconditions
    if (dict == NULL || nums == NULL || strlen(nums) == 0
    || nums[0] == '#') {
        return NULL;
    }
    char code[MAX_WORD_LENGTH];
    int num_pounds = 0;
    int index = 0;
    int pound_found = 0;

    // Loop through nums to separate digits and count pounds
    for (int i = 0; i < strlen(nums); i++) {
        char c = nums[i];
        if (c >= '2' && c <= '9') {
            if (pound_found) {
                return NULL;
            }
            code[index] = c;
            index++;
        } else if (c == '#') {
            pound_found = 1;
            num_pounds++;
        } else {
            return NULL;
        }
    }
    code[index] = '\0';
    // Use the GetNode to find the correct node in the trie
    T9* last_node = GetNode(dict, code, 0);

    // Check the result and return the correct word
    if (last_node != NULL && last_node->list_count > num_pounds) {
        return last_node->val[num_pounds];
    }
    return NULL;
}

void DestroyT9(T9* dict) {
    // free word_list and its words
    // if the array of pointers has been made
    // then free words
    if (dict->val != NULL) {
        for (int i = 0; i < dict->list_count; i++) {
            free(dict->val[i]);
        }
        free(dict->val);
    }
    // free branches
    for (int i = 0; i < 8; i++) {
        if (dict->node[i] != NULL) {
            DestroyT9(dict->node[i]);
        }
    }
    free(dict);
}

void InitializeDefaultFields(T9* dict) {
// Initialize fields to NULL
    for (int i = 0; i < 8; i++) {
        dict->node[i] = NULL;
    }
    dict->val = NULL;
    dict->list_count = 0;
}
void CharToT9Code(const char* word, char* code) {
    char letter;
    for (int i = 0; i < strlen(word); i++) {
        letter = word[i];
        if (letter >= 'a' && letter <= 'c') {
            code[i] = '2';
        } else if (letter >= 'd' && letter <= 'f') {
            code[i] = '3';
        } else if (letter >= 'g' && letter <= 'i') {
            code[i] = '4';
        } else if (letter >= 'j' && letter <= 'l') {
            code[i] = '5';
        } else if (letter >= 'm' && letter <= 'o') {
            code[i] = '6';
        } else if (letter >= 'p' && letter <= 's') {
            code[i] = '7';
        } else if (letter >= 't' && letter <= 'v') {
            code[i] = '8';
        } else if (letter >= 'w' && letter <= 'z') {
            code[i] = '9';
        }
    }
    code[strlen(word)] = '\0';
}
// recusively search trie for insertion spot
// n is the index of the code string
void Put(T9* dict, const char* word, char* nums, int n) {
    // Base Case: We've reached the end of the
    // number string, so insert the word.
    if (n == strlen(nums)) {
        int isDup = 0;
        if (dict->val != NULL) {
            for (int i = 0; i < dict->list_count; i++) {
                if (strcmp(dict->val[i], word) == 0) {
                    isDup = 1;
                    break;
                }
            }
        }
        if (!isDup) {
            if (dict->val == NULL) {
                char** word_list = (char**) malloc(sizeof(char*));
                if (word_list == NULL) { return; }
                dict->val = word_list;
                char* new_word = (char*)
                  malloc(sizeof(char) * (strlen(word) + 1));
                if (new_word == NULL) { return; }
                strncpy(new_word, word, strlen(word) + 1);
                word_list[0] = new_word;
                dict->list_count = 1;
            } else {
                int size = dict->list_count;
                char** temp = realloc(dict->val,
                  sizeof(char*)*(dict->list_count + 1));
                if (temp == NULL) { return; }
                dict->val = temp;
                char* new_word = (char*)
                  malloc(sizeof(char) * (strlen(word) + 1));
                if (new_word == NULL) { return; }
                strncpy(new_word, word, strlen(word) + 1);
                dict->val[size] = new_word;
                dict->list_count++;
            }
        }
        return;
    }
    // Recursive Step: Continue searching for the insertion point.
    // Check for invalid digits at the current index before processing.
    if (nums[n] < '2' || nums[n] > '9') {
        return;
    }

    int x = nums[n] - '0';
    int index = x - 2;

    // Check if node for the keypad input is null
    if (dict->node[index] == NULL) {
        T9* new_node = InitializeEmptyT9();
        dict->node[index] = new_node;
    }
    // Recurse and return the result
    return Put(dict->node[index], word, nums, n+1);
}
T9* GetNode(T9* dict, const char* nums, int n) {
// Base Case: At end of code return dict
    if (n == strlen(nums)) {
        return dict;
    }
    if (nums[n] < '2' || nums[n] > '9') {
        return NULL;
    }

    int x = nums[n] - '0';
    int index = x - 2;
    if (dict->node[index] == NULL) {
        return NULL;
    }

    return GetNode(dict->node[index], nums, n + 1);
}
