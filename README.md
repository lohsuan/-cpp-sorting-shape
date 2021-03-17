# cpp practice - sorting shape

### Introduction

main target to practice:
- engineering practices, including **unit testing**, **version control**, **make**, incremental development, test driven development

- problem solving [How To Solve It](http://htsicpp.blogspot.com/2014/08/introducing-how-to-solve-it-cpp.html)


**Problem: : sorting shapes**
A simple geometry application called _geo_ is needed to sort shapes such as triangles, circles, rectangles and others. As a command line application, _geo_ reads shapes from an input file, sorts the shapes by area or perimeter in increasing order or decreasing order, and write the result to an output file. For example,
```
geo input.txt output.txt area inc
```
sorts the shapes in file _input.txt_ in increasing order by area, and writes the result to the file _output.txt_. And
```
geo input.txt output.txt perimeter dec
```
sorts the shapes in file _input.txt_ in decreasing order by perimeter, and writes the result to the file _output.txt_.

## notes
### static member variable
在 class 裡把 member variable 宣告成 static，代表他是「與 class 相關連」，而不是「與物件相關連」。他獨立配置記憶體，獨立於 class 的任何物件而存在，這個 class 產生的所有物件共用使同一個 static member variable，甚至不需要有物件也能夠被使用。

因為 static member variable 不屬於任何物件，所以必須定義在外面。與一般成員變數不同，static member variable 並不是經由 constructor 初始化，而是在定義時被初始化。

### static member function
static member function 跟 static member variable 一樣，獨立於物件存在。可以在沒有物件產生的狀況下被使用，所以他不能使用 this，也不能存取 class 裡的一般成員變數，當然也不能使用一般成員函式。也就是說，static member function 只能存取 static member variable。

### Factory
- an object that creates other objects
  - createConvexPolygon: sort vertices, and then create polygon

### C++ Template
- 將 **資料型態參數化 **的功能。
- function template
```cpp
template < 樣板參數型態 樣板參數名 [, 其他樣板參數] >
原型回傳型態 函數名(參數型態 原型參數名, ...) {
    //prototype codes;
}
```
```cpp
// normal function
int myAdd(int a, int b) {
    return a + b;
}

// function template
template <class T>
T myAdd(T a, T b)
{
    return a + b;
}

int a = 1, b = 2;
myAdd<int>(a, b);
```

- class template
```
//normal class:
class myClass {
    myClass& add(const myClass& a) {
        return *this;
    }
};

//class template:
template <class T>
class myTClass
{
    T& add(const T& a) {
        return *this;
    }
};

int main() {
    myTClass<int>  a, b;
    myTClass<double> x,y;
}
```

### std::sort
- refer to std::sort to write our bubbleSort function
- https://en.cppreference.com/w/cpp/algorithm/sort

```cpp
template< class RandomIt, class Compare >
void sort( RandomIt first, RandomIt last, Compare comp );
```
