/**

* TJ Raklovits

* fileio2

* CS 23001

*/
// File: fileio2.cpp
//
// CS II: File IO lab
//
// Compile: clang++ -Wall fileio2.cpp -o fileio
// Usage:   ./fileio FILENAME

#include <iostream>
#include <fstream>

//Part 5 
//Read in a integer that is the number of lines to read
//Each line has only one word on it.
//Use data3.txt

int main(int argc, char *argv[]) {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cout << "Unable to open file: " << argv[1] << std::endl;
        exit(1);
    }
    int sentinal;
    inFile>>sentinal;
    std::cout<<sentinal<<std::endl;
    char line[1024];

    int i = 0;
    while(i < sentinal && inFile>>line){
	std::cout<<line<<std::endl;
	i+=1;
    }



    std::cout << "Done with Part 5" << std::endl << std::endl;
    inFile.close();
    return 0;
}
