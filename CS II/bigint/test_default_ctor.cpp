// Bigint Test Program
//
// Tests:	default constructor, uses ==
//
//
#include "bigint.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {
	// Setup

	// Test
	Bigint bi;

	// Verify
	std::cout << "0 == " << bi << std::endl;
	assert(bi == 0);

	std::cout << "Done testing default constructor." << std::endl;
	return 0;
}
