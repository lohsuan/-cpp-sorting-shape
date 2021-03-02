
// std::sort pratice

TEST(SortTest, SortAscending) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8);
  ASSERT_EQ(12, myints[0]);
  ASSERT_EQ(80, myints[7]);
}

template<class T>
bool greaterThan(T a, T b) {
  return a>b;
}

TEST(SortTest, SortDescendingInt) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8, greaterThan<int>);
  ASSERT_EQ(80, myints[0]);
  ASSERT_EQ(12, myints[7]);
}

TEST(SortTest, SortDescendingDouble) {
  double mydouble[] = {32.5,71.5,12.5,45.5,26.5,80.5,53.5,33.5};
  std::sort(mydouble+0, mydouble+8, greaterThan<double>);
  ASSERT_EQ(80.5, mydouble[0]);
  ASSERT_EQ(12.5, mydouble[7]);
}

template<class T>
bool distanceTo26(T a, T b) {
  return abs(a-26) < abs(b-26);
}

TEST(SortTest, SortAscendingByDistanceTo26) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8, distanceTo26<int>);
  ASSERT_EQ(26, myints[0]);
  ASSERT_EQ(32, myints[1]);
  ASSERT_EQ(33, myints[2]);
  ASSERT_EQ(12, myints[3]);
}
