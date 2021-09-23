CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall -fopenmp
MKDIR = mkdir -p
LIBS = -lm

directorios:
	$(MKDIR) build dist

clean:
	rm -fr *.o a.out build dist *.jpg

Image.o: directorios Image.cpp Image.h
	$(CXX) $(CXXFLAGS) -c Image.cpp -o build/Image.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean directorios main.o Image.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Image.o $(LIBS)
	rm -fr build

.DEFAULT_GOAL := all
