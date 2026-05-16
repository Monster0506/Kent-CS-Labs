# file to build
sources = wordListMain.cpp

# case sensitive or insensitive
case = insensitive

# file to output
target = wordCount

compiler = g++

# compiler flags
flags = -std=c++17

# build file
build:
	@$(compiler) $(flags) $(sources) -o $(target)

# run both tests saving their results to files
run: build
	@./$(target) file1.txt > test1Result.txt

# "clean" and "test" are not produced by make
.PHONY: clean test

# delete built file
clean:
	@rm -f $(target)
	@rm -f testClass

sensitive:
	@diff test1Result.txt caseSensitiveSolution.txt

insensitive:
	@diff test1Result.txt caseInsensitiveSolution.txt

# check if the programs output matches the desired output
test: run $(case)
	@$(compiler) $(flags) testWordList.cpp -o testClass
	@echo
	@./testClass
	@echo tests passed great job
