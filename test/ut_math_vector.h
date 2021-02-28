#include "../src/math_vector.h"

TEST(InnerProduct, MathVector) {
  double a[] = {5, 7};
  MathVector v(a, 2);
  ASSERT_EQ(5, v.component(1));
  ASSERT_EQ(7, v.component(2));
}

TEST(InnerProduct, add) {
  double a[] = {5, 7};
  double b[] = {3, 2};
  MathVector v(a, 2);
  MathVector u(b, 2);
  ASSERT_EQ(8, v.add(u).component(1));
  ASSERT_EQ(9, v.add(u).component(2));
}

TEST(InnerProduct, copyConstructor){
  double u[] = {1, 2};
  MathVector a(u, 2);
  MathVector b = a;   // copy constructor
  ASSERT_EQ(1, b.component(1));
  ASSERT_EQ(2, b.component(2));
}

TEST(InnerProduct, object_assignment){
  double u[] = {1, 2};
  MathVector a(u, 2);
  {
    double v[] = {3, 4};
    MathVector b(v, 2);
    a = b;    // copy assignment
  }
  ASSERT_EQ(3, a.component(1));
  ASSERT_EQ(4, a.component(2));
}

TEST(InnerProduct, object_assignment2){
  double u[] = {1, 2};
  MathVector a(u, 2);
  double v[] = {3, 4};
  MathVector b(v, 2);
  double w[] = {5, 6};
  MathVector c(w, 2);
  a = b = c;    // copy assignment

  ASSERT_EQ(5, a.component(1));
  ASSERT_EQ(6, a.component(2));
}

TEST(InnerProduct, scale) {
  double a[] = {5, 7};
  MathVector v(a, 2);
  ASSERT_EQ(10, v.scale(2).component(1));
  ASSERT_EQ(14, v.scale(2).component(2));
}

TEST(InnerProduct, length) {
  double a[] = {5, 12};
  MathVector v(a, 2);
  ASSERT_EQ(13, v.length());
}

TEST(InnerProduct, areaWith) {
  double a[] = {1, 0};
  double b[] = {4, 0};
  double c[] = {4, 4};
  MathVector u(a, 2);
  MathVector v(b, 2);
  MathVector w(c, 2);

  ASSERT_EQ(6, v.areaWith(u, w));
}
