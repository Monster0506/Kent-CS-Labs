/**

* TJ Raklovits

* fileio

* CS 23001

*/
// File: fileio.cpp
//
// CS II: File IO lab
//
// Compile: clang++ -Wall fileio.cpp -o fileio
// Usage:   ./fileio FILENAME

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    { //Part 1 Count every character in file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
	int i = 0;
        char ch = ' ';
	while (inFile.get(ch)){
		std::cout<<i<<": "<<ch<<std::endl;
		i+=1;
	}
	std::cout<<"Total: "<<i<<std::endl;


        std::cout << "Done with Part 1" << std::endl << std::endl;
        inFile.close();
    }

    { //Part 2 Count non white space character in a file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
	int i = 0;
        char ch = ' ';
	while (inFile>>ch){
		std::cout<<i<<": "<<ch<<std::endl;
		i+=1;
	}
	std::cout<<"Total: "<<i<<std::endl;

        std::cout << "Done with Part 2" << std::endl << std::endl;
        inFile.close();
    }


    { //Part 3 Count number of words in a file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
	int i = 0;
        char ch[1024];
	while (inFile>>ch){
		std::cout<<i<<": "<<ch<<std::endl;
		i+=1;
	}
	std::cout<<"Total: "<<i<<std::endl;

        std::cout << "Done with Part 3" << std::endl << std::endl;
        inFile.close();
    }


    { //Part 4 Count number lines in a file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
	int i = 0;
        char ch[1024];
	while (inFile.getline(ch, 1024)){
		std::cout<<i<<": "<<ch<<std::endl;
		i+=1;
	}
	std::cout<<"Total: "<<i<<std::endl;

        std::cout << "Done with Part 4" << std::endl << std::endl;
        inFile.close();
    }

    return 0;
}
