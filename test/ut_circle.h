#include "../src/circle.h"

TEST(CircleTest, Circle){
  double a[2] = {0, 0};
  MathVector v(a, 2);
  Circle c(10, v);
  ASSERT_EQ(10, c.radius());
  ASSERT_EQ(0, c.origin().component(1));
  ASSERT_EQ(0, c.origin().component(2));
}

TEST(CircleTest, Perimeter){
  double a[2] = {0, 0};
  MathVector v(a, 2);
  Circle c(10, v);
  ASSERT_NEAR(62.8, c.perimeter(), 0.1);
}

TEST(CircleTest, Area){
  double a[2] = {0, 0};
  MathVector v(a, 2);
  Circle c(10, v);
  ASSERT_NEAR(314.15, c.area(), 0.1);
}
