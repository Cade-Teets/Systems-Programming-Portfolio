#include "Vector.h"
#include <cmath>

namespace vector374 {
    // Ctor, cctor, dtor
    Vector::Vector(const float x, const float y, const float z) {
        v_ = new float[3];
        v_[0] = x;
        v_[1] = y;
        v_[2] = z;
    }
    Vector::Vector() {
        v_ = new float[3];
        v_[0] = 0.0;
        v_[1] = 0.0;
        v_[2] = 0.0;
    }
    Vector::Vector(const Vector& copyme) {
        v_ = new float[3];
        v_[0] = copyme.v_[0];
        v_[1] = copyme.v_[1];
        v_[2] = copyme.v_[2];
    }
    Vector::~Vector() {
        delete[] v_;
    }
    // Member functions
    // cross function is performed on an Vector by a vector
    // and returns a new vector of its cross product
    // A x B <-> v1.cross(v2);
    Vector Vector::cross(const Vector& v) const {
        return Vector(get_Y() * v.get_Z()
          - get_Z() * v.get_Y(), get_Z() * v.get_X()
          - get_X() * v.get_Z(), get_X() * v.get_Y()
          - get_Y() * v.get_X());
    }
    float Vector::length() const {
        return std::sqrt(v_[0] * v_[0]
          + v_[1] * v_[1] + v_[2] * v_[2]);
    }
    // Member overloaded operators
    Vector& Vector::operator=(const Vector& v) {
        // Check for self assignment
        if (this != &v) {
            delete[] v_;
            v_ = new float[3];
            v_[0] = v.v_[0];
            v_[1] = v.v_[1];
            v_[2] = v.v_[2];
        }
        return *this;
    }
    Vector& Vector::operator+=(const Vector& v) {
        v_[0] += v.get_X();
        v_[1] += v.get_Y();
        v_[2] += v.get_Z();
        return *this;
    }
    Vector& Vector::operator-=(const Vector& v) {
        v_[0] -= v.get_X();
        v_[1] -= v.get_Y();
        v_[2] -= v.get_Z();
        return *this;
    }
    // Nonmember overloaded operators
    Vector operator+(const Vector& v1, const Vector& v2) {
        return Vector(v1.get_X() + v2.get_X(),
          v1.get_Y() + v2.get_Y(), v1.get_Z() + v2.get_Z());
    }
    Vector operator-(const Vector& v1, const Vector& v2) {
        return Vector(v1.get_X() - v2.get_X(),
          v1.get_Y() - v2.get_Y(), v1.get_Z() - v2.get_Z());
    }
    float operator*(const Vector& v1, const Vector& v2) {
        float temp = v1.get_X() * v2.get_X() +
          v1.get_Y() * v2.get_Y() + v1.get_Z() * v2.get_Z();
        return temp;
    }
    Vector operator*(const Vector& v, const float c) {
        return Vector(c * v.get_X(),
          c * v.get_Y(), c * v.get_Z());
    }
    Vector operator*(const float c, const Vector& v) {
        return Vector(c * v.get_X(),
          c * v.get_Y(), c * v.get_Z());
    }
    bool operator==(const Vector& v1, const Vector& v2) {
        return (v1.get_X() == v2.get_X() &&
          v1.get_Y() == v2.get_Y() &&
          v1.get_Z() == v2.get_Z());
    }
    bool operator!=(const Vector& v1, const Vector& v2) {
        return (v1.get_X() != v2.get_X() ||
          v1.get_Y() != v2.get_Y() ||
          v1.get_Z() != v2.get_Z());
    }
    std::ostream& operator<<(std::ostream& out, const Vector& v) {
        out << "(" << v.get_X() << "," << v.get_Y() << "," << v.get_Z() << ")";
        return out;
    }
}  // namespace vector374
