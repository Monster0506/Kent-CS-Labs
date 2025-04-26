// Bigint Test Program
//
// Tests: times_10, uses ==
//
#include "bigint.hpp"
#include <cassert>

//===========================================================================
int main() {
	{
		//------------------------------------------------------
		// Setup fixture
		Bigint bi(3);

		// Test
		bi = bi.times10(2);

		// Verify
		assert(bi == 300);
	}

	{
		//------------------------------------------------------
		// Test with zero
		Bigint bi(0);

		// Test
		bi = bi.times10(5);

		// Verify
		assert(bi == 0);
	}

	{
		//------------------------------------------------------
		// Test single-digit multiplication
		Bigint bi(7);

		// Test
		bi = bi.times10(3);

		// Verify
		assert(bi == 7000);
	}

	{
		//------------------------------------------------------
		// Test multi-digit number
		Bigint bi(123);

		// Test
		bi = bi.times10(4);

		// Verify
		assert(bi == 1230000);
	}

	{
		//------------------------------------------------------
		// Test large number
		Bigint bi(987654321);

		// Test
		bi = bi.times10(6);

		// Verify
		assert(bi == Bigint("987654321000000"));
	}

	{
		//------------------------------------------------------
		// Test edge case with a single leading zero
		Bigint bi(10);

		// Test
		bi = bi.times10(1);

		// Verify
		assert(bi == 100);
	}

	{
		//------------------------------------------------------
		Bigint bi(456);

		// Test
		bi = bi.times10(0);

		// Verify
		assert(bi == 456);
	}

	{

		Bigint bi(1);

		// Test

		bi = bi.times10(19);
		// Verify
		assert(bi == Bigint("10000000000000000000"));
	}

	{
		//------------------------------------------------------
		Bigint bi(2);

		// Test
		bi = bi.times10(1).times10(2).times10(3);

		// Verify
		assert(bi == 2000000);
	}

	return 0;
}
