/**
    Author: Cade Teets
    UWNetID: cteets
    CSE 374 25su Homework 3: Wordcount
    Date: 07/18/25

    Citations: [List external resources or people you consulted]
    //cplusplus.com for the fopen fget rewind etc.
    // Anthony helped with debugging

    Description: [Brief description of the purpose of this program]
*/

// Includes for functions & types defined elsewhere.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines for symbolic constants (if any).
#define MAX_NUM_CHAR 500
// Function declarations/prototypes (with appropriate comments).
int numLines(char* arg, int* argCounter);
int numWords(char* arg, int* argCounter);
int numChars(char* arg, int* argCounter);
FILE* fileOpener(FILE *inFile, char* argPoint , int* argCounter);
/*  int numLines(FILE *inFile):
    Counts the number of lines in the passed input file
    Accepts an open FILE pointer as parameter
    Returns an int lineCount in the inFile
    Reads from the global inFile poiner and rewinds after EOF
*/
int numLines(char *arg, int* argCounter) {
    int lineCount = 0;
    char lineBuff[MAX_NUM_CHAR];
    FILE* inFile = NULL;    
    inFile = fileOpener(inFile, arg, argCounter);
    while (fgets(lineBuff , MAX_NUM_CHAR , inFile) != NULL) {
        lineCount++;
    }
    rewind(inFile);
    return lineCount;
}
/*  int numWords(FILE *inFile):
    Counts the number of words in the passed input file
    Accepts a FILE pointer as parameter
    Returns int  wordCount in the inFile
    Reads from the global inFile poiner and rewinds after EOF
*/
int numWords(char* arg, int* argCounter) {
    int wordCount = 0;
    char lineBuff[MAX_NUM_CHAR];
    FILE* inFile = NULL; 
    inFile = fileOpener(inFile,arg, argCounter);

    while (fgets(lineBuff, MAX_NUM_CHAR, inFile) != NULL) {
        // Parse through the string and pull word count
        // Debug statement to print the words found by the function
        int i = 0;
        int wordLetters = 0;

        // Count words that are one character or longer, seperated by spaces,
        // newlines or end of line characters
        while (i < strlen(lineBuff)) {
            if (lineBuff[i] == ' ' ||
            lineBuff[i] == '\n' ||
            lineBuff[i] == '\0') {
                wordLetters++;
            } else if (wordLetters != 0) {
                wordCount++;
                wordLetters = 0;
            }
            i++;
        }
    }
    rewind(inFile);
    return wordCount;
}
/*  int numChars(FILE *inFile):
    Counts the number of chars in the passed input file
    Accepts a FILE pointer as parameter
    Returns int  charCount in the inFile
    Reads from the  inFile pointer and rewinds file pointer after EOF
*/
int numChars(char* arg, int* argCounter) {
    int charCount = 0;
    char lineBuff[MAX_NUM_CHAR];
    FILE* inFile = NULL;

    inFile = fileOpener(inFile, arg, argCounter);
    
    while (fgets(lineBuff , MAX_NUM_CHAR , inFile) != NULL) {
        // For each string passed into lineBuff, keep running sum of char
        charCount += strlen(lineBuff);
    }
    rewind(inFile);
    return charCount;
}
/*  FILE* fileOpener(FILE *inFile, char* argPoint, int* totalArgs):
    Opens the passed input file pointer and returns the open file pointer
    Accepts a FILE pointer as parameter
    Returns FILE pointer (now as an open file)
    Updates the global totalArgs integer by reference when skipping files
*/
FILE* fileOpener(FILE *inFile, char* argPoint, int* totalArgs) {
// Opening the inFile with the ith argument to read from stream
    
// Checks if inFile pointer is NULL and if true prompt the user and EXIT_FAILURE
    
    if (argPoint == NULL) {
            fprintf(stderr, "Usage: ./wordcount requires an input file.\n");
            exit(EXIT_FAILURE);
    }   
    
// Checks if there are multiple files passed as parameters and switches file
// if the file opening fails, updating the totalArgs to keep track of file arguments
    if (*totalArgs > 2 && (fopen(argPoint, "r") == NULL)) {
            fprintf(stderr, "%s will not open. Skipping.\n", argPoint);
            //printf("Total Lines: %d\n", totalNumOfLines);
            *totalArgs-= 1;
            argPoint = argPoint + __SIZEOF_POINTER__;
            inFile = fileOpener(inFile, argPoint, totalArgs);
            return NULL;
    } 
    
    // if its the last file and its not opening, then throw error and exit
    inFile = fopen(argPoint, "r");
    if (inFile == NULL) {
        fprintf(stderr, "wordcount: %s: No such file or directory\n", argPoint);
        exit(EXIT_FAILURE);
    }
    return inFile;
}

int main(int argc, char* argv[]) {
    // Create option flags for comparing input options
    const char* lineOption = "-l";
    const char* wordOption = "-w";
    const char* charOption = "-c";
    
    int argCounter = 1;
    int totalArgs = argc - 1;
    
    FILE *inFile = NULL;

    // Check if there are no args passed and print usage message.

    if (argc < 2 || (argc == 2 && 
    (strncmp(argv[1], lineOption, strlen(lineOption)) == 0 || 
    strncmp(argv[1], wordOption, strlen(wordOption)) == 0 || 
    strncmp(argv[1], charOption, strlen(charOption)) == 0))) {
        fprintf(stderr, "Usage: ./wordcount requires an input file.\n");
        exit(EXIT_FAILURE);
    } else {
        // There is an option flag present
        totalArgs--;
    }
    // Logic to check option flag, changing the output
    if (strncmp(argv[1], lineOption, strlen(lineOption)) == 0) {
        while (argCounter < argc) {
            int lineCount = 0;
            lineCount = numLines(argv[argCounter], &argCounter);
            printf("lines: %d %s\n", lineCount, argv[argCounter]);
        }
        return EXIT_SUCCESS;
    } else if (strncmp(argv[1], wordOption, strlen(wordOption)) == 0) {
        int wordCount = 0;    
        while (argCounter < argc) {
            wordCount = numWords(argv[argCounter], &argCounter);
            printf("lines: %d %s\n", wordCount, argv[argCounter]);
        }
        
        return EXIT_SUCCESS;

    } else if (strncmp(argv[1], charOption, strlen(charOption)) == 0) {
        int charCount = 0;
        while (argCounter < argc) {
            charCount = numChars(argv[argCounter], &argCounter);
            printf("lines: %d %s\n", charCount, argv[argCounter]);
        }
        
        return EXIT_SUCCESS;
    }
    // If no options called, count words, chars, lines
    int totalNumOfLines = 0;
    //for (int i = 1; i < argc; i++) {
    while (argCounter < argc) {
    // Open file passed as an argument and assign that file stream to inFile
        if (argv[argCounter] == NULL) {
            fprintf(stderr, "Usage: ./wordcount requires an input file.\n");
            exit(EXIT_FAILURE);
        }
        // Add this to file opener
        
        // Opening the inFile with the ith argument to read from stream
        inFile = fileOpener(inFile, argv[argCounter], &argCounter);
        if (inFile == NULL) {
            fprintf(stderr, "wordcount: %s: No such file or directory\n", argv[argCounter]);
            argCounter++;
            continue;
        //exit(EXIT_FAILURE);
        }
        // Create varibles to return line, word, char
        int ls = 0;
        int ws = 0;
        int cs = 0;
        cs = numChars(argv[argCounter], &argCounter);
        ls = numLines(argv[argCounter], &argCounter);
        ws = numWords(argv[argCounter], &argCounter);
        totalNumOfLines += ls;
        // Print counted nums, lines, words
        printf("lines: %d words: %d characters: %d %s\n", ls, ws, cs, argv[argCounter]);
        // Once done with the inFile, close it to prevent any unwanted problems
        fclose(inFile);
        argCounter++;
    }
    printf("Total Lines: %d\n", totalNumOfLines);
    exit(EXIT_SUCCESS);
}
