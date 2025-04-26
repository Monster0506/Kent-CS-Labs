CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Include paths for dependencies
INCLUDES = -I../string -I../assembler

# Object files
OBJS = infix2prefix.o ../string/string.o

# Main target
all: infix2prefix

# Linking the executable
infix2prefix: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compilation rules
infix2prefix.o: infix2prefix.cpp ../string/string.hpp ../assembler/stack.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c infix2prefix.cpp

# Clean rule
clean:
	rm -f *.o infix2prefix

