CC = gcc
CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o AdvancedSort.o BasicSort.o NoComparisonSort.o FlashSort.o DataGenerator.o CommandProcess.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

AdvancedSort.o: AdvancedSort.h AdvancedSort.cpp Utilities.h BasicSort.h
	$(CXX) $(CXXFLAGS) -g -c AdvancedSort.cpp

BasicSort.o: BasicSort.cpp BasicSort.h Utilities.h
	$(CXX) $(CXXFLAGS) -g -c BasicSort.cpp

NoComparisonSort.o: NoComparisonSort.cpp NoComparisonSort.h
	$(CXX) $(CXXFLAGS) -g -c NoComparisonSort.cpp

FlashSort.o: FlashSort.cpp FlashSort.h Utilities.h BasicSort.h
	$(CXX) $(CXXFLAGS) -g -c FlashSort.cpp

DataGenerator.o: DataGenerator.cpp DataGenerator.h
	$(CXX) $(CXXFLAGS) -g -c DataGenerator.cpp

CommandProcess.o: CommandProcess.cpp CommandProcess.h BasicSort.h AdvancedSort.h NoComparisonSort.h FlashSort.h DataGenerator.h
	$(CXX) $(CXXFLAGS) -g -c CommandProcess.cpp

main.o: main.cpp BasicSort.h AdvancedSort.h NoComparisonSort.h FlashSort.h DataGenerator.h
	$(CXX) $(CXXFLAGS) -g -c main.cpp

clean:
	rm -f *.o *.exe