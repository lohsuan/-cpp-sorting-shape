#include <gtest/gtest.h>

#include "./ut_math_vector.h"
#include "./ut_convex_polygon.h"
#include "./ut_circle.h"

int main(int argc, char* argv[]){
  testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
