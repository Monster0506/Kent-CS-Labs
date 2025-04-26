#include "bigint.hpp"
#include <iostream>

Bigint nfact(int n) {
	Bigint result(1);
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

/*
 * countTrailingZeros implementation
 *	 GO through the number, and increment a count untl we hit a numner that is
 not 0

*/
int countTrailingZeros(Bigint n) {
	int count = 0;
	int i = 0;
	while (n[i] == 0) {
		count++;
		i++;
	}

	return count;
}

int main() {
	std::cout << nfact(100) << std::endl;
	std::cout << countTrailingZeros(nfact(100)) << std::endl;
}



/*
 * There are 24 zeros in 100!
* You can mathematically find the number of zeros in a n! by dividing	by 10
until you get a remainder that is not 0, and counting the number of times you
divided by 10.

* For example, 166! (the closest to 300 digit factorial at 298 digits)	could be
divided by 10 40 times, and 100! could be divided by 10 24 times.
*/
