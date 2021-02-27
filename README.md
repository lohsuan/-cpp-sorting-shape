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
