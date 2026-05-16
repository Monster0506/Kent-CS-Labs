# file to build
sources = testCollection.cpp

# file to output
target = testCollection

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

# check if the programs output matches the desired output
test: run
	@valgrind ./$(target) > memoryResult.txt
