#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <cmath>

class MathVector {
public:
  MathVector(){
    _vec = nullptr;
    _dim = 0;
  }

  MathVector(int dim){
    _dim = dim;
    _vec[dim] = {0};
  }

  MathVector(double a[], int dim) {
    initialize(a, dim);
  }

  MathVector(MathVector const & v) {   // copy constructor
    initialize(v._vec, v._dim);
  }

  ~MathVector(){
    if(_vec){
      delete [] _vec;
    }
  }

  MathVector & operator = (MathVector const & v) { // copy assignment
    if(_vec){
      delete [] _vec;
    }
    initialize(v._vec, v._dim);
    return *this;
  }

  MathVector operator - (MathVector const & v) const {
    MathVector result = *this;
    for (size_t i = 0; i < result._dim; i++) {
      result._vec[i] -= v._vec[i];
    }
    return result;
  }

  double component(int index) const {
    return _vec[index-1];
  }

  int dimension() const {
    return _dim;
  }

  MathVector add(MathVector const & v) const {
    if(_dim != v._dim){
      throw std::string("Dimension error !");
    }
    MathVector result = *this;  // copy constructor
    for (size_t i = 0; i < _dim; i++) {
      result._vec[i] += v._vec[i];
    }
    return result;
  }

  MathVector scale(double scaler) const {
    MathVector result = *this;
    for (size_t i = 0; i < _dim; i++) {
      result._vec[i] *= scaler;
    }
    return result;
  }

  double length() const {
    double result;
    for (size_t i = 0; i < _dim; i++) {
      result += _vec[i] * _vec[i];
    }
    return sqrt(result);
  }

  double areaWith(MathVector const & u, MathVector const & v) const {
    double result = 0;
    double a = (u - *this).length();
    double b = (v - *this).length();
    double c = (u - v).length();
    double s = (a + b + c) / 2;
    result = s * (s-a) * (s-b) * (s-c);
    return sqrt(result);
  }

private:
  double * _vec;
  int _dim;

  void initialize(double * a, int dim){
    _dim = dim;
    _vec = new double[_dim];
    for (size_t i = 0; i < _dim; i++) {
      _vec[i] = a[i];
    }
  }

};

#endif
