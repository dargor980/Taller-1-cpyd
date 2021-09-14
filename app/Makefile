CXX = g++
CXXFLAGS = -std=c++11 -g3 -Wall -fopenmp
MKDIR = mkdir -p
LIBS = -lm

directorios:
	$(MKDIR) build dist

clean:
	rm -fr *.o a.out build dist *.jpg

Convertidor.o: directorios Convertidor.cpp Convertidor.h
	$(CXX) $(CXXFLAGS) -c Convertidor.cpp -o build/Convertidor.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean directorios main.o Convertidor.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Convertidor.o $(LIBS)
	rm -fr build

.DEFAULT_GOAL := all
