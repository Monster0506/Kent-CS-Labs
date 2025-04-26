###############################################################
# CS II Kent State University
# Project 2 (string)
# Make file for string class, tests, test oracle, and logview
#
# J. Maletic 
# Spring 2025
#

###############################################################
# Compile only string.cpp/hpp
# Compile and run all your provided test on string (Milestone 1)
# Compile and run all test oracles on string (Milestone 2 & 3)
# Compile and run the project (Milestone 4)
msg:
	@echo 'Targets are:'
	@echo '  string     - Compile only string.cpp/hpp.'
	@echo '  tests      - Compile string, all your tests, and run them.'
	@echo '  oracle     - Build and run oracle tests on string.'
	@echo '  oracle-mem - Build and run oracle tests with valgrind on string.'
	@echo '  logview    - Compile logview and string if necessary.'
	@echo '  clean      - Remove all object code and executables.'



###############################################################
# Variables
CPP     = clang++
OPTIONS = -g -Werror -W -Wunused -Wuninitialized -Wshadow -std=c++17

###############################################################
# Names of student test files - add them they are created.
# Names MUST start with "test_"
#  These are ones that need to be created:
#
MYCTOR = test_default_ctor test_ctor_charArray test_ctor_char
MYREL  = test_equal test_lessThan 
MYOPS  = test_concat test_subscript test_len_cap test_input test_find_char test_find_string test_substring test_split
MYM2   = test_ctor_copy test_swap_assign


###############################################################
# Names of testoracle files 
# Include or exclude ones to compile/run
# For Milestone 3: testoracle_split
#
CTOR = testoracle_ctor_default testoracle_ctor_char  testoracle_ctor_charArray
REL  = testoracle_equal testoracle_lessThan 
COPY = testoracle_ctor_copy testoracle_assign testoracle_swap_assign
OPS  = testoracle_concat testoracle_subscript testoracle_len_cap testoracle_input testoracle_find_char testoracle_find_string testoracle_substring testoracle_split


###############################################################
###############################################################
# Rules
###############################################################
###############################################################


###############################################################
# Compile string 
#
string: string.hpp string.cpp
	$(CPP) -c $(OPTIONS) string.cpp -o string.o

string.o: string.hpp string.cpp
	$(CPP) -c $(OPTIONS) string.cpp -o string.o


###############################################################
# Run all of student tests for Milestone 1, 2, and 3.
#
#  Un-comment the tests to run.  Or add
#  the ones that are named differently.
#
# For Milestone 2 add $(MYM2) to the end of the line below
#
tests: $(MYCTOR) $(MYOPS) $(MYREL) $(MYM2)
	./test_default_ctor
	./test_equal 
	./test_ctor_char 
	./test_ctor_charArray
	./test_lessThan 
	./test_concat 
	./test_subscript 
	./test_len_cap
	./test_find_char 
	./test_find_string 
	./test_substring
	./test_input 
	./test_split
#Milestone 2
	./test_ctor_copy 
	./test_swap_assign 



###############################################################
# Compile all student test programs
#
test_%: string.o test_%.o
	$(CPP) $(OPTIONS) string.o test_$*.o -o test_$*

test_%.o: string.hpp test_%.cpp
	$(CPP) -c $(OPTIONS) test_$*.cpp



###############################################################
# Run test oracle for Milestone 2 and 3
# Comment out what not to run
#
oracle: $(CTOR) $(REL) $(COPY) $(OPS)
	./testoracle_ctor_default
	./testoracle_equal 
	./testoracle_ctor_char 
	./testoracle_ctor_charArray
	./testoracle_ctor_copy
	./testoracle_assign
	./testoracle_swap_assign
	./testoracle_lessThan
	./testoracle_concat
	./testoracle_subscript 
	./testoracle_len_cap 
	./testoracle_input 	
	./testoracle_substring
	./testoracle_find_char 
	./testoracle_find_string 
	./testoracle_split

###############################################################
# Run test oracle with valgrind for Milestone 2 and 3
# Comment out what not to run
#
oracle-mem: $(CTOR) $(REL) $(COPY) $(OPS)
	valgrind ./testoracle_ctor_default
	valgrind ./testoracle_equal 
	valgrind ./testoracle_ctor_char 
	valgrind ./testoracle_ctor_charArray
	valgrind ./testoracle_ctor_copy 
	valgrind ./testoracle_assign
	valgrind ./testoracle_swap_assign
	valgrind ./testoracle_lessThan
	valgrind ./testoracle_concat
	valgrind ./testoracle_subscript 
	valgrind ./testoracle_len_cap 
	valgrind ./testoracle_input 	
	valgrind ./testoracle_substring
	valgrind ./testoracle_find_char 
	valgrind ./testoracle_find_string 
#	valgrind ./testoracle_split


###############################################################
# Link all test oracles
#
# Assumptions:
#  Running Makefile in your svn repo:
#     home/cs23001/string/
#  Test oracle object files are in:
#     home/shared/project2/testoracles/
#

ORACLEPATH = ../../shared/project2/testoracles/

testoracle_%: string.o $(ORACLEPATH)testoracle_%.o
	$(CPP) $(OPTIONS) string.o $(ORACLEPATH)testoracle_$*.o -o testoracle_$*



###############################################################
# Compile Milestone 4
#
logview.o: logview.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logview.cpp -o logview.o

logentry.o: logentry.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logentry.cpp -o logentry.o

logview: logview.o string.o logentry.o 
	$(CPP) $(OPTIONS) logview.o string.o logentry.o -o logview




###############################################################
# Instructor ONLY command  (students can not access M1PATH)
# Run tests on string for Milestone 1.
#
M1CTOR = testM1_ctor_default  testM1_ctor_char testM1_ctor_charArray  
M1REL  = testM1_equal testM1_lessThan
M1OPS  = testM1_concat testM1_subscript testM1_len_cap testM1_input testM1_substring testM1_find_char testM1_find_string 
M1PATH = ../../instructors/project2-mile1/tests/

checkM1: $(M1CTOR) $(M1REL) $(M1OPS)
	./testM1_ctor_default
	./testM1_equal 
	./testM1_ctor_char 
	./testM1_ctor_charArray
	./testM1_lessThan
	./testM1_concat
	./testM1_subscript 
	./testM1_len_cap 
	./testM1_input 	
	./testM1_substring
	./testM1_find_char 
	./testM1_find_string 


###############################################################
# Compile all test programs for Milestone 1 check.
#
testM1_%: string.o testM1_%.o
	$(CPP) $(OPTIONS) string.o testM1_$*.o -o testM1_$*

testM1_%.o: string.hpp $(M1PATH)testM1_%.cpp
	cp $(M1PATH)testM1_$*.cpp .
	$(CPP) $(OPTIONS) -c testM1_$*.cpp






###############################################################
# clean 
# Removes all .o files and all executables from folder
#
clean:
	rm -f *.o
	rm -f $(MYCTOR) $(MYREL) $(MYOPS)
	rm -f $(M1CTOR) $(M1REL) $(M1OPS)
	rm -f testM1_*
	rm -f $(CTOR) $(REL) $(COPY) $(OPS)
	rm -f logview


