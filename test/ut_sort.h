#include "../src/bubblesort.h"
// std::sort pratice

TEST(SortTest, SortAscending) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8);
  ASSERT_EQ(12, myints[0]);
  ASSERT_EQ(80, myints[7]);
}

template<class T>
bool greaterThan(T & a, T & b) {
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

TEST(SortTest, BubbleSortIntergers) {
  int a[5] = {5, 4, 3, 2, 1};
  bubbleSort<int *>(a, a+5);
  ASSERT_EQ(1, a[0]);
  ASSERT_EQ(2, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(4, a[3]);
  ASSERT_EQ(5, a[4]);
}

TEST(SortTest, BubbleSortDouble) {
  double a[5] = {5.5, 4.5, 3.5, 2.5, 1.5};
  bubbleSort<double*>(a, a+5);
  ASSERT_EQ(1.5, a[0]);
  ASSERT_EQ(2.5, a[1]);
  ASSERT_EQ(3.5, a[2]);
  ASSERT_EQ(4.5, a[3]);
  ASSERT_EQ(5.5, a[4]);
}

// template<class T>
// bool greaterThan(T & a, T & b) {
//   return a>b;
// }

TEST(BubbleSortTest, DescendingIntegers){
  int a[5] = {7, 13, 5, 91, 60};
  bubbleSort<int *>(a+0, a+5, greaterThan<int>);
  ASSERT_EQ(5, a[4]);
  ASSERT_EQ(7, a[3]);
  ASSERT_EQ(13, a[2]);
  ASSERT_EQ(60, a[1]);
  ASSERT_EQ(91, a[0]);
}


template<class T>
class ComparatorGreater{
public:
  bool operator() (T const & latter, T const & former){
    return latter > former;
  }
};

TEST(BubbleSortTest, DescendingIntegersByObject){
  int a[5] = {7, 13, 5, 91, 60};
  ComparatorGreater<int> greater;
  bubbleSort<int *>(a+0, a+5, greater);
  ASSERT_EQ(5, a[4]);
  ASSERT_EQ(7, a[3]);
  ASSERT_EQ(13, a[2]);
  ASSERT_EQ(60, a[1]);
  ASSERT_EQ(91, a[0]);
}

TEST(BubbleSortTest, DescendingIntegersByObjectOnArray){
  std::array<int, 5> a = {7, 13, 5, 91, 60};
  ComparatorGreater<int> greater;
  bubbleSort(&a[0], &a[0]+5, greater);
  ASSERT_EQ(5, a[4]);
  ASSERT_EQ(7, a[3]);
  ASSERT_EQ(13, a[2]);
  ASSERT_EQ(60, a[1]);
  ASSERT_EQ(91, a[0]);
}

TEST(BubbleSortTest, DescendingIntegersByObjectOnArrayIterator){
  std::array<int, 5> a = {7, 13, 5, 91, 60};
  ComparatorGreater<int> greater;
  bubbleSort(a.begin(), a.end(), greater);
  ASSERT_EQ(5, a[4]);
  ASSERT_EQ(7, a[3]);
  ASSERT_EQ(13, a[2]);
  ASSERT_EQ(60, a[1]);
  ASSERT_EQ(91, a[0]);
}
