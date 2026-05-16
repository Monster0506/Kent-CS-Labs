# file to build
sources = lab1.cpp

# file to output
target = diff

compiler = g++

# compiler flags
flags = -std=c++17

# build file
build:
	@$(compiler) $(flags) $(sources) -o $(target)

# run both tests saving their results to files
run: build
	@./$(target) file1.txt file2.txt > test1Result.txt
	@./$(target) file11.txt file12.txt > test2Result.txt

# "clean" and "test" are not produced by make
.PHONY: clean test

# delete built file
clean:
	rm -f $(target)

# check if the programs output matches the desired output
test: run
	@diff -C 3 test1Result.txt test1Solution.txt
	@diff -C 3 test2Result.txt test2Solution.txt
	@echo tests passed great job
