PROGRAM=10_std_function
CXX       = g++
CXXFLAGS  = -g -std=c++17 -Wall -O3

$(PROGRAM): main.o
	$(CXX) -o $(PROGRAM) main.o

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


