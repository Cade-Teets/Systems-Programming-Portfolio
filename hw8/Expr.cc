#include "Expr.h"

#include <cmath>
#include <memory>

namespace expr {

std::ostream& operator<<(std::ostream& o, const shared_ptr<Expr>& eptr) {
  return o << eptr->toString();
}

string Num::toString() const {
  std::ostringstream s;
  s << num_;
  return s.str();
}

Sum::Sum(shared_ptr<Expr> left, shared_ptr<Expr> right)
    : left_(left), right_(right) {}

shared_ptr<Expr> Sum::clone() const {
  return std::make_shared<Sum>(left_->clone(), right_->clone());
}

shared_ptr<Expr> Num::clone() const { return std::make_shared<Num>(num_); }

shared_ptr<Expr> Var::clone() const { return std::make_shared<Var>(name_); }

shared_ptr<Expr> Num::setVariables(
    const std::map<std::string, double>& values) const {
      return clone();
}

shared_ptr<Expr> Sum::setVariables(
    const std::map<std::string, double>& values) const {
      auto updated_left = left_->setVariables(values);
      auto updated_right = right_->setVariables(values);

      return std::make_shared<Sum>(updated_left, updated_right);
}

shared_ptr<Expr> Var::setVariables(
    const std::map<std::string, double>& values) const {
  auto result = values.find(name_);
  // if not located in the map
  if (result == values.end()) {
    return clone();
  } else {
    return std::make_shared<Num>(result->second);
  }
}

shared_ptr<Expr> operator+(shared_ptr<Expr> lhs, shared_ptr<Expr> rhs) {
  return std::make_shared<Sum>(lhs, rhs);
}

double Var::evaluate() const { return NAN; }
double Num::evaluate() const { return num_; }
double Sum::evaluate() const { return left_->evaluate() + right_->evaluate(); }

// Prod
Prod::Prod(shared_ptr<Expr> left, shared_ptr<Expr> right)
  : left_(left), right_(right) {}

shared_ptr<Expr> Prod::clone() const {
  return std::make_shared<Prod>(left_->clone(), right_->clone());
}

shared_ptr<Expr> Prod::setVariables(
  const std::map<std::string, double>& values) const {
  auto updated_left = left_->setVariables(values);
  auto updated_right = right_->setVariables(values);

  return std::make_shared<Prod>(updated_left, updated_right);
}

shared_ptr<Expr> operator*(shared_ptr<Expr> lhs, shared_ptr<Expr> rhs) {
  return std::make_shared<Prod>(lhs, rhs);
}

double Prod::evaluate() const { return left_->evaluate() * right_->evaluate(); }

// Pow
Pow::Pow(shared_ptr<Expr> lhs, shared_ptr<Expr> rhs)
  : left_(lhs), right_(rhs) {}

shared_ptr<Expr> Pow::clone() const {
  return std::make_shared<Pow>(left_->clone(), right_->clone());
}

shared_ptr<Expr> Pow::setVariables(
  const std::map<std::string, double>& values) const {
    auto updated_left = left_->setVariables(values);
    auto updated_right = right_->setVariables(values);

    return std::make_shared<Pow>(updated_left, updated_right);
  }
double Pow::evaluate() const {
  return pow(left_->evaluate(), right_->evaluate());
}

shared_ptr<Expr> operator^(shared_ptr<Expr> lhs, shared_ptr<Expr> rhs) {
  return std::make_shared<Pow>(lhs, rhs);
}

}  // namespace expr
