/**
    TODO: Fill in the following basic information.

    Author: [First and Last Name]
    UWNetID: [Your UWNetID]
    CSE 374 25su Homework 7: C++ Classes, Operators
    Date: [mm/dd/yyyy]

    Citations: [List external resources or people you consulted]

    Description: [Brief description of the purpose of this program]
*/

#ifndef _VECTOR_H_ // NOLINT
#define _VECTOR_H_ // NOLINT

// TODO: Includes for functions & types defined elsewhere.

namespace vector374 {

class Vector {
 public:
  // TODO: Declare any constructors, destructor

  // TODO: Any accessors or mutators needed (getters/setters)

  // TODO: Declare any member functions

  // TODO: Additional functions that are not members of Vector but
  //       need to be friends so they can access instance variables

 private:
  // A Vector is represented by a heap-allocated array of three
  // floats giving the x, y, and z magnitudes in v[0], v[1],
  // and v[2] respectively.
  float* v_;

  // TODO: Private member functions if needed
};

// TODO: Delcare any non-member and non-friend functions

}  // namespace vector374

#endif  //  _VECTOR_H_ NOLINT
