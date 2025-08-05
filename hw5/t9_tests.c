#include <string.h>

#include "safe_assert.h"
#include "t9_lib.h"

void AssertReturnedStringEquals(char* expected, char* actual);

suite("T9") {
  test("Empty initialization") {
    T9* dict = InitializeEmptyT9();
    safe_assert(dict != NULL);
    DestroyT9(dict);
  }

  test("Testing PredictT9 for proper word prediction") {
    // Test creation of T9
    T9* dict = InitializeEmptyT9();
    safe_assert(dict != NULL);

    // Insert words
    AddWordToT9(dict, "book");
    AddWordToT9(dict, "cool");

    char* word = PredictT9(dict, "2665#");
    AssertReturnedStringEquals("cool", word);

    DestroyT9(dict);
  }
  // Additional Test 1: "Testing InitializeFromFileT9"
  // Designed to check if the InitializeFromFileT9 function 
  // will return null if an invalid file name is passed.
test("Testing InitializeFromFileT9 with dictionary.txt") {
  char* realFileName = "dictionary.txt";
  T9* dict = InitializeFromFileT9(realFileName);
  
  safe_assert(dict != NULL);
  char* word = PredictT9(dict, "228");
  AssertReturnedStringEquals("act", word);

  DestroyT9(dict);
}
test("Testing InitializeFromFileT9 with oneline_empty_dictionary.txt") {
  char* realFileName = "oneline_empty_dictionary.txt";
  T9* dict = InitializeFromFileT9(realFileName);
  
  safe_assert(dict != NULL);
  
  DestroyT9(dict);
}
//Additional Test 2: "Testing InitializeFromFileT9 with dictionary.txt file"
test("Testing InitializeFromFileT9 with invalid fileName") {
  char* fakeFileName = "foobar.txt";
  T9* dict = InitializeFromFileT9(fakeFileName);
  
  safe_assert(dict == 0);
  
}

//Additional Test 3: "Testing InitializeFromFileT9 with NULL"
test("Testing InitializeFromFileT9 with NULL") {
  T9* dict = InitializeFromFileT9(NULL);
  
  safe_assert(dict == NULL);
}
//Additional Test 3: "Testing InitializeFromFileT9 with space"
  test("Testing InitializeFromFileT9 with empty fileName") {
  T9* dict = InitializeFromFileT9("");
  
  safe_assert(dict == NULL);
}
//Additional Test 4: "Testing InitializeFromFileT9 with small_dict"
test("Testing InitializeFromFileT9 with small_dict file") {
  char* fileName = "small_dictionary.txt";
  T9* dict = InitializeFromFileT9(fileName);
  
  safe_assert(dict != NULL);
  
  DestroyT9(dict);
}

//Additional Test #: "Tesing InitializeFileFromT9 with empty_dict"
test("Testing Tesing InitializeFileFromT9 with empty_dictionary") {
  char* empty_dict = "empty_dictionary.txt";
  T9* dict = InitializeFromFileT9(empty_dict);

  safe_assert(dict != NULL);
  DestroyT9(dict);
}
//Additional Test #: "Tesing InitializeFileFromT9 with file of symbols
// test("Testing InitializeFileFromT9 with invalid_dictionary") {
//   char* invalid_dict = "invalid_dictionary.txt";
//   T9* dict = InitializeFromFileT9(invalid_dict);

//   safe_assert(dict == NULL);
// }


// Additional Test #: Testing AddWordToT9 NULL
// test("Testing AddWordToT9 with NULL"){
//   T9* dict = InitializeEmptyT9();
  
//   AddWordToT9(dict, NULL);

//   safe_assert(dict == NULL);
  

// }
// Additional Test #: Testing AddWordToT9 with empty string
test("Testing AddWordToT9 with empty string"){
  T9* dict = InitializeEmptyT9();
  
  char* space = " ";
  AddWordToT9(dict, space);
  

}
// Additional Test #: Testing AddWordToT9 with
test("Testing AddWordToT9 with word containing number"){
  T9* dict = InitializeEmptyT9();

  AddWordToT9(dict, "w0rld");

}
// Additional Test #: Testing AddWordToT9 with
// test("Testing AddWordToT9 with invalid chars and not asserting"){
//   T9* dict = InitializeEmptyT9();
//   AddWordToT9(dict, "ca t");
//   char* cat = PredictT9(dict, "228");
//   AssertReturnedStringEquals(NULL, cat);
// }

// Additional Test 4: "Testing AddWordToT9 with word in uppercase"
 test("Testing AddWordToT9 with word in uppercase") {
  T9* dict = InitializeEmptyT9();

  // adding capital letter, which should return NULL
  char* uppercaseInput = "CAT";
  AddWordToT9(dict, uppercaseInput);
  char* space = PredictT9(dict, "228");
  safe_assert (space == NULL);

  
//   //AssertReturnedStringEquals(invalidInput, space);
//   // returns actual value less than 0, because the actual comparison
//   // in this method will 


//   //AssertReturnedStringEquals("", word);
//   //AssertReturnedStringEquals(NULL, word);
  DestroyT9(dict);
}
// NOT WORKING AS INTENDED 
// test("Testing AddWordToT9 with a space") {
//   T9* dict = InitializeEmptyT9();

//   // Add valid word
//   char* valid_word = "cat";
//   AddWordToT9(dict, valid_word);
//   char* valid_return = PredictT9(dict, "228");
//   // Assert valid word is returned
//   safe_assert(strncmp(valid_return, valid_return, 3) == 0);

//   char* space = " ";
//   AddWordToT9(dict, space);
//   valid_return = PredictT9(dict, "228");
//   // Assert valid word is still returned
//   safe_assert(strncmp(valid_return, valid_return, 3) == 0);

//   char* invalid_return = PredictT9(dict, "228#");
//   safe_assert(strncmp(valid_return, invalid_return, 3) != 0);

//   DestroyT9(dict);
// }
  
// test("Testing AddWordToT9 with input containing symbol") {
//   T9* dict = InitializeEmptyT9();
//   DestroyT9(dict);
// }
  
// test("Testing AddWordToT9 with input containing number") {
//   T9* dict = InitializeEmptyT9();
//   DestroyT9(dict);

// }





// Additional Test 3: "Testing PredictT9 with NULL input"
test("Testing PredictT9 with NULL input") {
  T9* dict = InitializeFromFileT9("dictionary.txt");

  // Test passing in a NULL nums, should get out NULL
  char* invalid_input = PredictT9(dict, NULL);
  safe_assert(invalid_input == NULL)
  DestroyT9(dict);
}

// Additional Test 4: "Testing PredictT9 on words not in small dictionary"
test("Testing PredictT9 on small dictionary") {
  T9* dict = InitializeFromFileT9("small_dictionary.txt");

  // koala (56252), kiwi (5494)
  char* invalid_input = PredictT9(dict, "56252");
  safe_assert(invalid_input == NULL);
  char* invalid_input2 = PredictT9(dict, "5494");
  safe_assert(invalid_input2 == NULL);
  
  DestroyT9(dict);
}
// Additional Test 4: "Testing PredictT9 on words not in small dictionary"
test("Testing PredictT9 on small dictionary") {
  T9* dict = InitializeEmptyT9();

  // koala (56252)
  char* invalid_input = PredictT9(dict, "56252");
  safe_assert(invalid_input == NULL);
  
  DestroyT9(dict);
}
// Additional Test 5 : "Testing PredictT9 with only a pound"
test("Testing PredictT9 with only a pound") {
  T9* dict = InitializeFromFileT9("dictionary.txt");

  char* invalid_input1 = PredictT9(dict, "#");
  safe_assert(invalid_input1 == NULL);
  

  DestroyT9(dict);
}

// Additional Test 6: "Testing PredictT9 with number after pount"
test("Testing PredictT9 with number after pound") {
  T9* dict = InitializeFromFileT9("dictionary.txt");
  
  char* invalid_input2 = PredictT9(dict, "#1");
  safe_assert(invalid_input2 == NULL);

  DestroyT9(dict);
}

// Additional Test 7: "Testing PredictT9 on empty dictionary"
test("Testing PredictT9 on empty dictionary") {
  T9* dict = InitializeEmptyT9();
  
  char* nullReturn = PredictT9(dict, "wow");
  safe_assert(nullReturn == NULL);
  
  DestroyT9(dict);
}
// refactor this test
// Additional Test 8: "Testing PredictT9 on word not in dictionary"
test("Testing PredictT9 on word not in dictionary") {
  T9* dict = InitializeEmptyT9();
  
  AddWordToT9(dict, "wow");
  AddWordToT9(dict, "low");
  
  char* invalid_input1 = PredictT9(dict, "869"); //tow
  safe_assert(invalid_input1 == NULL);

  DestroyT9(dict);
}
test("Testing AddWordToT9 and PredictT9 for duplicate word") {
  T9* dict = InitializeEmptyT9();
  // adding duplicate word "cat"
  char* cat = "cat";
  AddWordToT9(dict, cat);
  

  // add "cat" again and check if it returns
  AddWordToT9(dict, cat);
  char* valid_return = PredictT9(dict, "228");
  AssertReturnedStringEquals(cat, valid_return);

  char* cat1 = PredictT9(dict, "228#");
  
  safe_assert(cat1 == NULL);

}


test("Testing AddWordToT9 and PredictT9 for given word") {
  T9* dict = InitializeEmptyT9();

  // Add valid word
  char* valid_word = "cat";
  AddWordToT9(dict, valid_word);
  char* valid_return = PredictT9(dict, "228");
  // Assert valid word is returned
  AssertReturnedStringEquals(valid_return, valid_word);
}  
test("Testing AddWordToT9 and PredictT9 space in empty dict") {
  T9* dict = InitializeEmptyT9();

  // Add invalid word
  AddWordToT9(dict, "");
  char* invalid_return = PredictT9(dict, "");
  // Assert valid word is returned
  safe_assert (invalid_return == NULL);
}  

test("Testing AddWordToT9 and PredictT9 for similar words") {
  T9* dict = InitializeEmptyT9();

  // Add valid words
  char* cat = "cat";
  char* cats = "cats";
  AddWordToT9(dict, cat);
  AddWordToT9(dict, cats);

  char* valid_return = PredictT9(dict, "228");

  AssertReturnedStringEquals(cat, valid_return);
}

test("Testing AddWordToT9 and PredictT9 for NULL") {
  T9* dict = InitializeEmptyT9();

  AddWordToT9(dict, NULL);

  char* word = PredictT9(dict, NULL);

  safe_assert(word == NULL);

}
test("Testing AddWordToT9 and PredictT9 for multiple valid inputs") {
  T9* dict = InitializeEmptyT9();
  char* validInput1 = "cat";
  char* validInput2 = "rat";
  AddWordToT9(dict, validInput1);
  AddWordToT9(dict, validInput2);

  char* cat = PredictT9(dict, "228");
  char* rat = PredictT9(dict, "728");

  AssertReturnedStringEquals(validInput1, cat);
  AssertReturnedStringEquals(validInput2, rat);
}
test("Testing AddWordToT9 and PredictT9 for similar words in reverse") {
  T9* dict = InitializeEmptyT9();

  // Add valid words
  char* cats = "cats";
  char* cat = "cat";
  
  AddWordToT9(dict, cat);
  AddWordToT9(dict, cats);

  char* valid_return = PredictT9(dict, "2287");

  AssertReturnedStringEquals(cats, valid_return);
}
test("Testing AddWordToT9 and PredictT9 for words with extra num") {
  T9* dict = InitializeEmptyT9();

  // Add valid words
  char* cat = "cat";
  
  AddWordToT9(dict, cat);
  char* invalid_return = PredictT9(dict, "2287");

  safe_assert (invalid_return == NULL);
}
// Additional Test 9 "Testing PredictT9 with num > 9"
test("Testing PredictT9 with num > 9") {
  /*
  Post: in ASCII numbers, nums needs to check 
  if (num > 47 && num < 58 || nums == 35)
  */
  T9* dict = InitializeFromFileT9("dictionary.txt");

  char* invalid_input = PredictT9(dict, "10");
  safe_assert(invalid_input == NULL);

  DestroyT9(dict);
}
// Additional Test 10: "Testing PredictT9 with three pounds"
test("Testing PredictT9 with three pounds") {
  /*
  Post: in ASCII numbers, nums needs to check 
  if (num > 47 && num < 58 || nums == 35)
  */
  T9* dict = InitializeFromFileT9("dictionary.txt");

  char* invalid_input = PredictT9(dict, "###");
  safe_assert(invalid_input == NULL);

  DestroyT9(dict);
}

// Additional Test 10: "Testing PredictT9 with three pounds after input"
test("Testing PredictT9 with three pounds after input") {
  /*
  Post: in ASCII numbers, nums needs to check 
  if (num > 47 && num < 58 || nums == 35)
  */
  T9* dict = InitializeFromFileT9("dictionary.txt");

  char* invalid_input = PredictT9(dict, "228###");
  safe_assert(invalid_input == NULL);

  DestroyT9(dict);
}

// Additional Test 10: "Testing PredictT9 with no input"
test("Testing PredictT9 with no input") {
  T9* dict = InitializeFromFileT9("dictionary.txt");

  char* invalid_input = PredictT9(dict, "");
  safe_assert(invalid_input == NULL);

  DestroyT9(dict);
}

}

void AssertReturnedStringEquals(char* expected, char* actual) {
  safe_assert(actual > 0);
  safe_assert(strlen(actual) == strlen(expected));
  safe_assert(strcmp(actual, expected) == 0);
}
