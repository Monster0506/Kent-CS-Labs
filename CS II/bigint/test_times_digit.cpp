// Bigint Test Program
//
// Tests:	times_10, timesDigit, uses ==
//
// NEED TO IMPLEMENT
//
#include "bigint.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {
	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(123456);

		// Test
		bi = bi.timesDigit(4);

		// Verify
		assert(bi == 493824);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(987654);

		// Test
		bi = bi.timesDigit(2);

		// Verify
		assert(bi == 1975308);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(0);

		// Test
		bi = bi.timesDigit(7);

		// Verify
		assert(bi == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(1);

		// Test
		bi = bi.timesDigit(9);

		// Verify
		assert(bi == 9);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(999999);

		// Test
		bi = bi.timesDigit(5);

		// Verify
		assert(bi == 4999995);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(1234);

		// Test
		bi = bi.timesDigit(0);

		// Verify
		assert(bi == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(6789);

		// Test
		bi = bi.timesDigit(3);

		// Verify
		assert(bi == 20367);
	}
	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(1024);

		// Test
		bi = bi.timesDigit(1024);

		// Verify
		assert(bi == 1048576);
	}

	std::cout << "Done testing Bigint * digit" << std::endl;
	return 0;
}
