#include "bigint.hpp"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream in;			 // Define input stream
	in.open("data1-1.txt"); // Open a file
	if (!in) {							// Make sure file opened correctly
		std::cerr << "File not found: data1-1.txt" << std::endl;
		exit(1);
	}
	Bigint b1;
	Bigint b2;

	while (in >> b1 >> b2) {

		std::cout << "========================================" << std::endl;
		std::cout << b1 << std::endl << std::endl << b2 << std::endl << std::endl;
		Bigint sum = b1 + b2;
		std::cout << sum << std::endl;
	}
	return 0;
}
