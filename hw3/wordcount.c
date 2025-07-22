/**
    Author: Cade Teets
    UWNetID: cteets
    CSE 374 25su Homework 3: Wordcount
    Date: 07/18/25

    Citations: [List external resources or people you consulted]
    //cplusplus.com for the fopen fget rewind etc.

    Description: [Brief description of the purpose of this program]
*/

// Includes for functions & types defined elsewhere.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines for symbolic constants (if any).
#define MAX_NUM_CHAR 500
// Function declarations/prototypes (with appropriate comments).
int numLines(FILE *inFile);
int numWords(FILE *inFile);
int numChars(FILE *inFile);
FILE* fileOpener(FILE *inFile, char* argPoint);
/*  int numLines(FILE *inFile):
    Counts the number of lines in the passed input file
    Accepts a FILE pointer as parameter
    Returns an int lineCount in the inFile
    Reads from the global inFile poiner and rewinds after EOF
*/
int numLines(FILE *inFile) {
    int lineCount = 0;
    char lineBuff[MAX_NUM_CHAR];

    while (fgets(lineBuff , MAX_NUM_CHAR , inFile) != NULL) {
        // If the newline char is found in the string, increment line counter
        if (strchr(lineBuff, '\n') != NULL) {
            lineCount++;
        }
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
int numWords(FILE *inFile) {
    int wordCount = 0;
    char lineBuff[MAX_NUM_CHAR];
    while (fgets(lineBuff, MAX_NUM_CHAR, inFile) != NULL) {
        // Parse through the string and pull word count
        // Debug statement to print the words found by the function
        int i = 0;
        int wordLetters = 0;

        while (i < strlen(lineBuff)) {
            if (lineBuff[i] != ' ' && lineBuff[i] != '\n') {
                wordLetters++;
            } else if (wordLetters != 0) {
                wordCount++;
                wordLetters = 0;
            }
            i++;
        }
        if (wordLetters != 0) {
            wordCount++;
        }
    }
    rewind(inFile);
    return wordCount;
}

int numChars(FILE *inFile) {
    int charCount = 0;
    char lineBuff[MAX_NUM_CHAR];
    while (fgets(lineBuff , MAX_NUM_CHAR , inFile) != NULL) {
        // For each string passed into lineBuff, keep running sum of char
        charCount += strlen(lineBuff);
    }
    rewind(inFile);
    return charCount;
}

FILE* fileOpener(FILE *inFile, char* argPoint) {
// Opening the inFile with the ith argument to read from stream
    inFile = fopen(argPoint, "r");
// Checks if inFile pointer is NULL and if true prompt the user and EXIT_FAILURE
    if (inFile == NULL) {
        printf("wordcount: %s: No such file or director\n", argPoint);
        exit(EXIT_FAILURE);
    }
    return inFile;
}

int main(int argc, char* argv[]) {
    const char* lineOption = "-l";
    const char* wordOption = "-w";
    const char* charOption = "-c";
    FILE *inFile = NULL;

    // Check if there are no args passed and print usage message.
    if (argv[1] == NULL) {
       printf("%s", "Usage: ./wordcount requires an input file.\n");
       return (EXIT_FAILURE);
    }
    // Logic to check option flag, changing the output
    if (strncmp(argv[1], lineOption, strlen(lineOption)) == 0) {
        int lineCount = 0;
        if (argv[2] == NULL) {
                printf("%s", "Usage: ./wordcount requires an input file.\n");
                return (EXIT_FAILURE);
            }
        for (int j = 2; j < argc; j++) {
        // Open file passed as an argument and assign that file stream to inFile
            if (argv[j] == NULL) {
                printf("%s", "Usage: ./wordcount requires an input file.\n");
                return (EXIT_FAILURE);
            }
            inFile = fileOpener(inFile, argv[j]);
            lineCount = numLines(inFile);
            printf("lines: %d %s\n", lineCount, argv[j]);
            fclose(inFile);
        }
        exit(EXIT_SUCCESS);
    } else if (strncmp(argv[1], wordOption, strlen(wordOption)) == 0) {
        int wordCount = 0;
        for (int j = 2; j < argc; j++) {
            if (argv[j] == NULL) {
                printf("%s", "Usage: ./wordcount requires an input file.\n");
                return (EXIT_FAILURE);
            }
            inFile = fileOpener(inFile, argv[j]);
            wordCount = numWords(inFile);

            printf("words: %d %s\n", wordCount, argv[j]);
            fclose(inFile);
        }
        exit(EXIT_SUCCESS);

    } else if (strncmp(argv[1], charOption, strlen(charOption)) == 0) {
        int charCount = 0;
        for (int j = 2; j < argc; j++) {
            if (argv[j] == NULL) {
                printf("%s", "Usage: ./wordcount requires an input file.\n");
                return (EXIT_FAILURE);
            }
            inFile = fileOpener(inFile, argv[j]);
            charCount = numChars(inFile);
            // Print word count and fileName
            printf("chars: %d %s\n", charCount, argv[j]);
            fclose(inFile);
        }

        exit(EXIT_SUCCESS);
    }
    // If no options called, count words, chars, lines
    int totalNumOfLines = 0;
    for (int i = 1; i < argc; i++) {
    // Open file passed as an argument and assign that file stream to inFile
        if (argv[i] == NULL) {
            printf("%s", "Usage: ./wordcount requires an input file.\n");
            return (EXIT_FAILURE);
        }
        if (fopen(inFile, "r") == NULL) {
            printf("wordcount: %s: No such file or director\n", argv[i]);
            printf("Total Lines: %d\n", totalNumOfLines);
            exit(EXIT_SUCCESS);
        }
        // Opening the inFile with the ith argument to read from stream
        inFile = fileOpener(inFile, argv[i]);

        // Create varibles to return line, word, char
        int ls = 0;
        int ws = 0;
        int cs = 0;
        cs = numChars(inFile);
        ls = numLines(inFile);
        ws = numWords(inFile);
        totalNumOfLines += ls;
        // Print counted nums, lines, words
        printf("lines: %d words: %d characters: %d %s\n", ls, ws, cs, argv[i]);
        // Once done with the inFile, close it to prevent any unwanted problems
        fclose(inFile);
    }
    printf("Total Lines: %d\n", totalNumOfLines);
    exit(EXIT_SUCCESS);
}
