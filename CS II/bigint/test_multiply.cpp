// Bigint Test Program
//
// Tests:	multiply, uses ==
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
		result = left * right;

		// Verify
		assert(left == 0);
		assert(right == 0);
		assert(result == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(1);
		Bigint right(0);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 1);
		assert(right == 0);
		assert(result == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(0);
		Bigint right(1);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 0);
		assert(right == 1);
		assert(result == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(123);
		Bigint right(56);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 123);
		assert(right == 56);
		assert(result == 6888);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(65);
		Bigint right(321);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 65);
		assert(right == 321);
		assert(result == 20865);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(9999);
		Bigint right(2);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 9999);
		assert(right == 2);
		assert(result == 19998);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(2);
		Bigint right(999999);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 2);
		assert(right == 999999);
		assert(result == 1999998);
	}
	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(99);
		Bigint right(99);
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == 99);
		assert(right == 99);
		assert(result == 9801);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left("2222");
		Bigint right("888888888888888888888888888888888888");
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == "2222");
		assert(right == "888888888888888888888888888888888888");
		assert(result == "1975111111111111111111111111111111109136");
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left("777777777777777777777777777777777777777777777");
		Bigint right("333333");
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == "777777777777777777777777777777777777777777777");
		assert(right == "333333");
		assert(result == "259258999999999999999999999999999999999999999740741");
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left("111111111111111111111111111111111111111111");
		Bigint right("999999999999999999999999999999999999999999");
		Bigint result;

		// Test
		result = left * right;

		// Verify
		assert(left == "111111111111111111111111111111111111111111");
		assert(right == "999999999999999999999999999999999999999999");
		assert(result == "111111111111111111111111111111111111111110888888888888888"
										 "888888888888888888888888889");
	}

	// Add test cases as needed.

	std::cout << "Done testing multiply" << std::endl;
	return 0;
}
