/*
    Author: Cade Teets
    UWNetID: 2302720
    CSE 374 25su Homework 7: C++ Classes, Operators
    Date: 8/13/25

    Citations: [List external resources or people you consulted]

    Description: [Brief description of the purpose of this program]
*/

#ifndef _VECTOR_H_ // NOLINT
#define _VECTOR_H_ // NOLINT

#include <iostream>

namespace vector374 {

class Vector {
 public:
  // ctor, cctor, dtor
  Vector(float x, float y, float z);
  Vector();
  Vector(const Vector& copy);
  ~Vector();
  // Accessors/Mutators
  float get_X() const { return v_[0]; }
  float get_Y() const { return v_[1]; }
  float get_Z() const { return v_[2]; }

  void set_X(const float new_x) { v_[0] = new_x; }
  void set_Y(const float new_y) { v_[0] = new_y; }
  void set_Z(const float new_z) { v_[0] = new_z; }
  // Member functions:
  // Operators that modify by reference
  Vector& operator=(const Vector& v);
  Vector& operator+=(const Vector& v);
  Vector& operator-=(const Vector& v);
  // Helper functions
  Vector cross(const Vector& v) const;
  float length() const;

 private:
  // A Vector is represented by a heap-allocated array of three
  // floats giving the x, y, and z magnitudes in v[0], v[1],
  // and v[2] respectively.
  float* v_;
};

// Nonmember functions:
Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);
float operator*(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v, const float c);
Vector operator*(const float c, const Vector& v);
bool operator==(const Vector& v1, const Vector& v2);
bool operator!=(const Vector& v1, const Vector& v2);
std::ostream& operator<<(std::ostream& out, const Vector& v);
}  // namespace vector374

#endif  //  _VECTOR_H_ NOLINT
