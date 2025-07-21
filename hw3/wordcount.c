/**
    Author: Cade Teets
    UWNetID: cteets
    CSE 374 25su Homework 3: Wordcount
    Date: 07/18/25

    Citations: [List external resources or people you consulted]
    //cplusplus.com for the fopen fget etc.

    Description: [Brief description of the purpose of this program]
*/

// TODO: Includes for functions & types defined elsewhere.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Defines for symbolic constants (if any).
#define MAX_NUM_CHAR 500
// TODO: Function declarations/prototypes (with appropriate comments).
int numLines (FILE *inFile);
int numWords (FILE *inFile);
int numChars (FILE *inFile);
// TODO: Function definitions.

int numLines(FILE *inFile) {
    int lineCounter = 0;
    char lineBuff [MAX_NUM_CHAR];
    
    while (fgets(lineBuff , MAX_NUM_CHAR , inFile) != NULL) {
        // Debug statement just print out the string in lineBuff
        //puts(lineBuff);
        // For each string passed into lineBuff, keep running sum of char
        
        // If the newline char is found in the string, increment line counter 
        if (strchr(lineBuff,'\n') != NULL) {
            lineCounter++;
        }
    }
    rewind(inFile);
    return lineCounter;
}

int numWords(FILE *inFile) {
    int wordCounter = 0;
    char lineBuff [MAX_NUM_CHAR];

    while(fgets(lineBuff, MAX_NUM_CHAR, inFile) != NULL) {
        // Parse through the string and pull word count
        // Debug statement to print the words found by the function
        puts(lineBuff);
        int i = 0;
        int wordLetters = 0;
        //int isNewline = 0;
        // maybe make it so its only looking for if the newline char is not present then if a space occurs to the wordLetter check
        // that way you stay in the while loop
        //while (lineBuff[i] != '\n') {
        while (i < strlen(lineBuff)) {
            if (lineBuff[i] != ' ' && lineBuff[i] != '\n') {
                wordLetters++;
            } else if (wordLetters != 0) {
                wordCounter++;
                wordLetters = 0;
            }
            i++;    
        }
        if (wordLetters != 0) {
            wordCounter++; 
        }
    }

    rewind(inFile);
    return wordCounter;
}

int numChars(FILE *inFile) {    
    int charCounter = 0;
    char lineBuff [MAX_NUM_CHAR];
    
    while (fgets(lineBuff , MAX_NUM_CHAR , inFile) != NULL) {
        // Debug statement just print out the string in lineBuff
        //puts(lineBuff);
        // For each string passed into lineBuff, keep running sum of char
        charCounter += strlen(lineBuff);
    }   
    rewind(inFile);
    return charCounter;
}

int main(int argc, char* argv[]) {

    const char* lineOption = "-l";
    const char* wordOption = "-w";
    const char* charOption = "-c";
    int i = 1;
    
    // Create a variable to store each line called lineBuf and make and File variable inFile 
    // LINEBUFF IS BEING USED BY THE FUNCTION ATM
    //char lineBuff [MAX_NUM_CHAR];
    FILE *inFile;

    // Check if there are no arguments passed to the program, print usage message.
    //WORKING
    if (argv[i] == NULL ) {
       printf("%s","Usage: ./wordcount requires an input file.\n");
       return (EXIT_FAILURE);
    }
    
    // add logic to check what option flag is used, and save that so that it can ouput properly
    /*
    The program should also accept these three options: -l, -w, -c.

    If an option is detected, the program will output only the number of lines, words, or characters respectively.
    If an option is specified, the program will NOT print the total number of lines in all the files.
    The program shouldn’t process more than one option. If more than one option is provided, only the first one should be activated.
    */
   
        // THIS IS WORKING BUT I PROBABLY NEED TO MOVE IT TO THE END SO THAT I CAN ENSURE THE OPTION CONTROLS THE OUTPUT
    if (strncmp(argv[1], lineOption, strlen(lineOption)) == 0) {
        //print only lines
        
        printf("Moving parameter over...\n");

        // maybe want to move the counter for the input variable pointer over
        i++;
    } else if (strncmp(argv[1], wordOption, strlen(wordOption)) == 0) {
        //print only words 
        printf("word option still not fully implemented\n");
    } else if (strncmp(argv[1], charOption, strlen(charOption)) == 0){
        // print only chars 
        printf("char option still not fully implemented\n");
    }
    
    // At this point its assumed every subsequent arg is a fileName
    if (argv[i] == NULL ) {
            printf("%s","Usage: ./wordcount requires an input file.\n");
            return (EXIT_FAILURE);
        }
        
    
        // fix the initializer on this for loop, as i is initialized outside the loop atm to catch the option earlier 
    for (; i < argc; i++) {
        // Open file passed as an argument and assign that file stream to inFile
        
        if (argv[i] == NULL ) {
            printf("%s","Usage: ./wordcount requires an input file.\n");
            return (EXIT_FAILURE);
        }
        
        // Opening the inFile with the ith argument to read from stream
        inFile = fopen(argv[i], "r");
    
        // If the inFile pointer is NULL, it doesn't exist so prompt the user and EXIT_FAILURE
        if (inFile == NULL) {
            printf("wordcount: <name of file>: No such file or director\n");
            exit(EXIT_FAILURE);
        }

        // Create varibles for the returns, which will be used depending on the option flag.
        int numOfLines = 0;
        int numOfWords = 0;
        int numOfChars = 0;

        //HERE SHOULD BE THE FUNCTION CALLS SO THAT THE LINES WORDS AND CHARS CAN BE COUNTED
        numOfChars = numChars(inFile);
        numOfLines = numLines(inFile);
        numOfWords = numWords(inFile);
        
        
        // Once done with the inFile, close it to prevent any unwanted problems
        fclose(inFile);
 
        
        //printf("characters: %d, and fileName is: %s\n", numOfChars, argv[i]);
        //printf("lines: %d characters: %d %s\n", numOfLines, numOfChars, argv[i]);
        printf("lines: %d words: %d characters: %d %s\n", numOfLines, numOfWords, numOfChars, argv[i]);
    }
exit(EXIT_SUCCESS);
}