#ifndef CIRCLE_H
#define CIRCLE_H
#include "./math_vector.h"
#include <cmath>

class Circle{
public:
  Circle(double r, MathVector origin = MathVector(2))
  : _r(r), _origin(origin)  // constructor initializer
  {
      // execution of constructor
  }

  double radius() const {
    return _r;
  }

  MathVector origin() const {
    return _origin;
  }

  double perimeter() const {
    return 2 * _r * M_PI;
  }

  double area() const {
    return _r * _r * M_PI;
  }

private:
  double _r;
  MathVector _origin;
};

#endif
