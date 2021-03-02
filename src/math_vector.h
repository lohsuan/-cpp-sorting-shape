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
    double a[dim] = {0};
    initialize(a, dim);
  }

  MathVector(double a[], int dim) {
    initialize(a, dim);
  }

  MathVector(MathVector const & v) {   // copy constructor
    initialize(v._vec, v._dim);
  }

  ~MathVector(){
    if(_vec != nullptr){
      delete [] _vec;
    }
  }

  MathVector & operator = (MathVector const & v) { // copy assignment
    if(_vec != nullptr){
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

  double & component(int index) const {
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

  double dot(MathVector const & v) {
    double result = 0;
    for(int i = 0; i < _dim; i++) {
      result += _vec[i] * v._vec[i];
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
    double result = 0;
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

  double angleWith(MathVector u) {
      double result = dot(u)/(length()*u.length());
      return acos(result)/M_PI*180;
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

MathVector centroid(MathVector u[], int n){
  MathVector result = u[0];
  for (size_t i = 1; i < n; i++) {
    result = result.add(u[i]);
  }
  return result.scale(1.0/n);
}

#endif
