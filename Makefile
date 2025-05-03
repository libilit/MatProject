CXX = g++
CXXFLAGS = -std=c++17 
VALGRIND = valgrind --leak-check=full

SRC = SquareMat.cpp main.cpp test.cpp
HEADERS = SquareMat.hpp doctest.h
OBJS = SquareMat.o main.o test.o

Main: SquareMat.o main.o
	$(CXX) $(CXXFLAGS) -o Main main.o SquareMat.o
	./Main

test: SquareMat.o test.o
	$(CXX) $(CXXFLAGS) -o test test.o SquareMat.o
	./test

valgrind: test
	$(VALGRIND) ./test

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp SquareMat.hpp doctest.h
	$(CXX) $(CXXFLAGS) -c test.cpp

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

clean:
	rm -f *.o Main test
