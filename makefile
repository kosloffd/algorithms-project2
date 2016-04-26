# ===========================================================================
# Title       : CS325 Project 2 Group 30 - Analysis of Algorithms
# Members	  : John Fitzpatrick, Dylan York, Jarrad Favre
# Date	      : 04/17/2016
# Subject     : Project 2 makefile
# Description : Simple makefile to build our C++ program to test algorithms
# 				Use 'make all' to build the program. an executable named
# 				'main' can be used to run the program.
# Arguments	  : Please provide on argument, a text file, in the form of
# 				[file_name].txt
# ===========================================================================



# Declaration of variables
CC = g++
CC_FLAGS = -w -std=c++11

# File names
EXEC = main
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)