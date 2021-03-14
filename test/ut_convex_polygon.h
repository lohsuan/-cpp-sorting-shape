#include "../src/math_vector.h"
#include "../src/convex_polygon.h"

TEST(ConvexPolygonTest, CreatConvexPolygon) {
  double a[] = {1, 0};
  double b[] = {4, 0};
  double c[] = {4, 4};
  double d[] = {1, 4};
  MathVector u;
  MathVector v;
  MathVector w;
  MathVector x;

  u = MathVector(a, 2);
  v = MathVector(b, 2);
  w = MathVector(c, 2);
  x = MathVector(d, 2);

  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp = ConvexPolygon::create(vertices, 4);
  ASSERT_EQ(1, cp.vertex(0).component(1));
  ASSERT_EQ(0, cp.vertex(0).component(2));
  ASSERT_EQ(4, cp.vertex(1).component(1));
  ASSERT_EQ(0, cp.vertex(1).component(2));
}

class ConvexPolygonTestFixture : public ::testing::Test {
protected:
  void SetUp(){
    double a[] = {1, 0};
    double b[] = {4, 0};
    double c[] = {4, 4};
    double d[] = {1, 4};
    u = MathVector(a, 2);
    v = MathVector(b, 2);
    w = MathVector(c, 2);
    x = MathVector(d, 2);
  }
  MathVector u;
  MathVector v;
  MathVector w;
  MathVector x;
};

TEST_F(ConvexPolygonTestFixture, CreatConvexPolygonWithFixture) {
  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp = ConvexPolygon::create(vertices, 4);
  ASSERT_EQ(1, cp.vertex(0).component(1));
  ASSERT_EQ(0, cp.vertex(0).component(2));
  ASSERT_EQ(4, cp.vertex(1).component(1));
  ASSERT_EQ(0, cp.vertex(1).component(2));
}

TEST_F(ConvexPolygonTestFixture, Perimeter) {
  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp = ConvexPolygon::create(vertices, 4);
  ASSERT_EQ(14, cp.perimeter());
}

TEST_F(ConvexPolygonTestFixture, Area) {
  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp = ConvexPolygon::create(vertices, 4);
  ASSERT_EQ(12, cp.area());
}

TEST_F(ConvexPolygonTestFixture, Centroid){
  MathVector vertices[4] = {u, w, x, v};
  MathVector o = centroid(vertices, 4);
  ASSERT_EQ(2.5, o.component(1));
  ASSERT_EQ(2, o.component(2));
}

TEST_F(ConvexPolygonTestFixture, Scale) {
  MathVector v = w.scale(2);
  ASSERT_EQ(8, v.component(1));
  ASSERT_EQ(8, v.component(2));
}

TEST_F(ConvexPolygonTestFixture, Angle) {
  MathVector vertices[4] = {u, w, x, v};
  MathVector o = centroid(vertices, 4);
  ASSERT_EQ(2.5, o.component(1));
  ASSERT_EQ(2, o.component(2));
  MathVector v1 = u-o;
  MathVector v2 = v-o;
  ASSERT_NEAR(74, v1.angleWith(v2), 1.0);
}

TEST_F(ConvexPolygonTestFixture, SortVerticesNotOrdered){
  MathVector vertices[4] = {u, w, x, v};
  MathVector g = centroid(vertices, 4);
  MathVector r = vertices[0] - g;
  AngleComparator comp(g, r);
  std::sort(vertices, vertices+4, comp);
  ASSERT_EQ(1, vertices[0].component(1));
  ASSERT_EQ(0, vertices[0].component(2));
  ASSERT_EQ(4, vertices[1].component(1));
  ASSERT_EQ(0, vertices[1].component(2));
  ASSERT_EQ(4, vertices[2].component(1));
  ASSERT_EQ(4, vertices[2].component(2));
  ASSERT_EQ(1, vertices[3].component(1));
  ASSERT_EQ(4, vertices[3].component(2));
}

TEST_F(ConvexPolygonTestFixture, VerticesNotOrderedAreaPerimeter){
  MathVector vertices[4] = {u, w, x, v};
  ConvexPolygon cp = ConvexPolygon::create(vertices, 4);
  ASSERT_EQ(12, cp.area());
  ASSERT_EQ(14, cp.perimeter());
}
