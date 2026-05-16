# file to build
sources = roster.cpp

# file to output
target = roster

compiler = g++

# compiler flags
flags = -std=c++17

# build file
build:
	@$(compiler) $(flags) $(sources) -o $(target)

# run both tests saving their results to files
run: build
	@./$(target) > result.txt

# "clean" and "test" are not produced by make
.PHONY: clean test

# delete built file
clean:
	@rm -f $(target)

