.PHONY: directories clean stat

CFLAGS = -std=c++11 -Wfatal-errors #-fno-elide-constructors
TESTS = test/ut_math_vector.h test/ut_convex_polygon.h test/ut_circle.h \
				test/ut_sort.h
HEADERS = src/math_vector.h src/convex_polygon.h src/circle.h \


all: directories bin/test

bin/test: test/ut_all.cpp $(TESTS) $(HEADERS)
	g++ $(CFLAGS) test/ut_all.cpp -o bin/test -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -f bin/*

stat:
	wc -l src/* test/*
