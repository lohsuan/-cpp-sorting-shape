#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

template <class T>
void bubbleSort(T begin, T end) {
  int n = end - begin;
  for (size_t i = n-1; i > 0; i--) {
    for (size_t j = 0; j <=i-1; j++) {
      if(*(begin+j) > *(begin+j+1)){
        std::swap(*(begin+j), *(begin+j+1));
      }
    }
  }
}

#endif
