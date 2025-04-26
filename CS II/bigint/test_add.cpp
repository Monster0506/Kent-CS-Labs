// Bigint Test Program
//
// Tests: int constructor, uses ==
//
// Expanded with additional test cases
//
#include "bigint.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {
	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(0);
		Bigint right(0);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 0);
		assert(right == 0);
		assert(result == 0);
		std::cout<<"0+0=0 PASSED"<<std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(1);
		Bigint right(0);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 0);
		assert(result == 1);
		std::cout<<"0+1=1 PASSED"<<std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(1);
		Bigint right(1);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 1);
		assert(result == 2);
		std::cout<<"1+1=2 PASSED"<<std::endl;
	}

	{
		//------------------------------------------------------
		// Test large numbers
		Bigint left(999999999);
		Bigint right(1);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 999999999);
		assert(right == 1);
		assert(result == 1000000000);
		std::cout<<"999999999+1=1000000000 PASSED"<<std::endl;
	}

	std::cout << "Done with testing addition." << std::endl;
	return 0;
}
