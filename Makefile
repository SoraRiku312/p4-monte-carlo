CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS = -std=c++14 -g -Wall

#OBJECTS = Calculations.o Analytics.o Customer.o Event.o
#HEADERS := $(shell find    "*.cpp" "*.hpp" )

#main: MainRunner.o $(OBJECTS)
#	$(CXX) $(CXXFLAGS) -o $@ $^
#
#$(OBJECTS): $(HEADERS)

Project4: main.o Dataset.o SimRange.o Simulation.o TextIO.o
	$(CXX) $(CXXFLAGS) -o $@ $^



#clean:
#	rm -rf *.dSYM
#	$(RM) *.o *.gc* main *.o