#include <iostream>
#include <cstdlib>

#include "Vector.h"

using std::cout;
using std::endl;
using vector374::Vector;

// You may comment out tests that you have not yet implemented
// or that you are not ready to test yet. This file will not fully compile
// until you have implemented the Vector class and all its methods/operators.

// Create several vectors and test their operations
int main() {
  // Test constructors and stream output
  Vector v1;
  cout << "default Vector v1, should be (0,0,0): " << v1 << endl;
  Vector v2(1, 2, 3);
  cout << "Vector v2 with initial values, should be (1,2,3): " << v2 << endl;
  Vector v3(v2);
  cout << "Vector v3 from copy constructor, should be (1,2,3): " << v3 << endl;

  // Test assignment (including chaining)
  Vector v4(3.1, -2.5, 2.7);
  v1 = v3 = v4;
  cout << "Vector assignment, should have three copies of (3.1,-2.5,2.7):\n";
  cout << "  v1: " << v1 << "  v3: " << v3 << "  v4: " << v4 << endl;

  // Test dot product
  cout << "Dot product:" << endl;
  cout << "  " << v2 << " * " << v2 << " = " << v2 * v2 << endl;
  cout << "  " << v4 << " * " << v2 << " = " << v4 * v2 << endl;

  // Test scalar product
  cout << "Scalar product:" << endl;
  cout << "  "       << v1 << " * 2 = " << v1 * 2 << endl;
  cout << "  -3.2 * " << v1 << " = " << -3.2 * v1 << endl;

  // Test update assignment operators
  cout << "Update assignment:" << endl;
  v1 += v2;
  cout << "  v1 += v2; v1 is now: " << v1 << endl;
  v1 -= v2;
  cout << "  v1 -= v2; v1 is now: " << v1 << endl;

  // Test addition and subtraction
  Vector v5(1.2, 3.4, -5.6);
  Vector v6(-2.1, 4.3, 6.5);
  Vector v7 = v5 + v6;
  cout << "Sum:" << endl;
  cout << "  "       << v5 << " + " << v6 << " = " << v7 << endl;

  Vector v8 = v6 - v5;
  cout << "Difference:" << endl;
  cout << "  "       << v6 << " - " << v5 << " = " << v8 << endl;

  // Test cross product
  Vector v9;  // TODO: call your cross product function for v5 x v6
  cout << "Cross product:" << endl;
  cout << "  "       << v5 << " x " << v6 << " = " << v9 << endl;

  // Test length
  cout << "Length:" << endl;
  float len1;  // TODO: replace with length function call for v5
  float len2;  // TODO: replace with length function call for v6
  cout << "  |" << v5 << "| = " << len1 << endl;
  cout << "  |" << v6 << "| = " << len2 << endl;

  // Test equals and not equals
  cout << std::boolalpha;  // Enable boolean output formatting

  // Calling == on two different vectors with different coordinates
  cout << "Equals:" << endl;
  cout << "  "       << v5 << " == " << v6 << " : " << (v5 == v6) << endl;

  // Calling == on the same vector
  cout << "  "       << v5 << " == " << v5 << " : " << (v5 == v5) << endl;

  // Calling == on two different vectors with the same coordinates
  cout << "  "       << v3 << " == " << v4 << " : " << (v3 == v4) << endl;

  // Calling != on two different vectors with different coordinates
  cout << "Not Equals:" << endl;
  cout << "  "       << v5 << " != " << v6 << " : " << (v5 != v6) << endl;

  // Calling != on the same vector
  cout << "  "       << v5 << " != " << v5 << " : " << (v5 != v5) << endl;

  // Calling != on two different vectors with the same coordinates
  cout << "  "       << v3 << " != " << v4 << " : " << (v3 != v4) << endl;

  return EXIT_SUCCESS;
}
