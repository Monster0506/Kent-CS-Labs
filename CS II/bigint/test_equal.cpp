// Bigint Test Program
//
// Tests:	 ==, uses Bigint(int)
//
//
#include "bigint.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {

	{
		// Setup
		Bigint bi(0);
		// Test
		assert(bi == 0);
		// Verify
		std::cout << "0 == ";
		std::cout << bi;
		std::cout << std::endl;
	}

	{
		// Setup
		Bigint bi1(1234);
		Bigint bi2(1234);
		// Test
		assert(bi1 == bi2);
		// Verify
		std::cout << bi1;
		std::cout << " == ";
		std::cout << bi2;
		std::cout << std::endl;
	}

	{
		// Setup
		Bigint bi1(1234);
		Bigint bi2(234);
		// Test
		assert(!(bi1 == bi2));
		// Verify
		std::cout << bi1;
		std::cout << " != ";
		std::cout << bi2;
		std::cout << std::endl;
	}

	{
		// Setup
		Bigint bi1(1234);
		Bigint bi2(123);
		// Test
		assert(!(bi1 == bi2));
		// Verify
		std::cout << bi1;
		std::cout << " != ";
		std::cout << bi2;
		std::cout << std::endl;
	}
	{
		// Setup
		Bigint bi1(123);
		Bigint bi2(1234);
		// Test
		assert(!(bi1 == bi2));
		// Verify
		std::cout << bi1;
		std::cout << " != ";
		std::cout << bi2;
		std::cout << std::endl;
	}

	std::cout << "Done testing ==." << std::endl;
	return 0;
}
