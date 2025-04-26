// Bigint Test Program
//
// Tests:	subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include "bigint.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {

	{
		// Setup
		Bigint bi(800);

		// Test
		int digit = bi[0];

		// Verify
		assert(bi == 800);
		assert(digit == 0);
	}
	{
		// Setup
		Bigint bi(123456);

		// Test
		int digit = bi[5];

		// Verify
		assert(bi == 123456);
		assert(digit == 1);
	}
	{
		// Setup
		Bigint bi(0);

		// Test
		int digit = bi[0];

		// Verify
		assert(bi == 0);
		assert(digit == 0);
	}
	{
		// Setup
		Bigint bi(5);

		// Test
		int digit = bi[0];

		// Verify
		assert(bi == 5);
		assert(digit == 5);
	}
	{
		// Setup
		Bigint bi("23456789765456789654345678987654");

		// Test
		int digit = bi[31];

		// Verify
		assert(digit == 2);
	}

	std::cout << "All tests passed!" << std::endl;

	std::cout << "Done testing subscript." << std::endl;
	return 0;
}
