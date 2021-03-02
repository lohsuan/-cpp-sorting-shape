
// std::sort pratice 

TEST(SortTest, SortAscending) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8);
  ASSERT_EQ(12, myints[0]);
  ASSERT_EQ(80, myints[7]);
}

bool greaterThan(int a, int b) {
  return a>b;
}

TEST(SortTest, SortDescending) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8, greaterThan);
  ASSERT_EQ(80, myints[0]);
  ASSERT_EQ(12, myints[7]);
}

bool distanceTo26(int a, int b) {
  return abs(a-26) < abs(b-26);
}

TEST(SortTest, SortAscendingByDistanceTo26) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8, distanceTo26);
  ASSERT_EQ(26, myints[0]);
  ASSERT_EQ(32, myints[1]);
  ASSERT_EQ(33, myints[2]);
  ASSERT_EQ(12, myints[3]);
}
