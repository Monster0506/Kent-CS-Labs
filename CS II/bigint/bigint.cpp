/*
 * TJ Raklovits
 * Bigint
 * CS 23001
 */
#include "bigint.hpp"
#include <iostream>

// fill with zeros to avoid weird problems accessing undefined memory locations.
void Bigint::reset() {
	for (int i = 0; i < CAPACITY; i++) {
		digits[i] = 0;
	}
	size = 0;
}
// default constructor
Bigint::Bigint() {
	reset();
	size = 1;
	digits[0] = 0;
}
// char[] constructor
Bigint::Bigint(const char arr[]) {
	reset();
	int start = 0;

	while (arr[start] == '0' && arr[start + 1] != '\0') {
		start++;
	}

	if (arr[start] == '0' && arr[start + 1] == '\0') {
		size = 1;
		digits[0] = 0;
		return;
	}

	int count = 0;
	while (arr[count + start] != '\0') {
		count++;
	}
	size = count;

	for (int i = 0; i < size; i++) {
		digits[size - i - 1] = arr[i + start] - '0';
	}
}

// int constructor
Bigint::Bigint(int num) {
	reset();
	int savedNum = num;
	int count = 0;
	if (num == 0) {
		count = 1;
	} else {
		while (num != 0) {
			num /= 10;
			count++;
		}
	}
	size = count;
	for (int i = 0; i < size; i++) {
		digits[i] = savedNum % 10;
		savedNum /= 10;
	}
}

// Print all digits in reverse order separated by |
void Bigint::debugPrint(std::ostream &stream) const {
	for (int i = CAPACITY - 1; i > 0; i--) {
		stream << digits[i] << " | ";
	}
	stream << digits[0] << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bigint &bigint) {
	int start = bigint.size - 1;
	int count = 0;
	while (bigint.digits[start] == 0 && bigint.digits[start + 1] != '\0') {
		start--;
	}

	for (int i = start; i >= 0; i--) {
		out << bigint.digits[i];
		count++;
		if (count == 100 && i > 0) {
			out << std::endl;
			count = 0;
		}
	}

	return out;
}

// test equals
bool Bigint::operator==(const Bigint &bigint) const {
	if (size != bigint.size)
		return false;
	for (int i = 0; i < size; i++) {
		if (bigint.digits[i] != digits[i])
			return false;
	}
	return true;
};

// override instream operator
std::istream &operator>>(std::istream &in, Bigint &bigint) {
	bigint.size = 0;
	char ch;
	int newDigits[CAPACITY];
	bool leadingZero = true;

	while (in.get(ch)) {
		if (ch == ';') {
			break;
		}
		if (ch >= '0' && ch <= '9') {
			if (leadingZero && ch == '0') {
				continue;
			}
			leadingZero = false;
			newDigits[bigint.size++] = ch - '0';
		}
	}
	if (bigint.size == 0) {
		newDigits[bigint.size++] = 0;
	}

	for (int i = 0; i < bigint.size; i++) {
		bigint.digits[i] = newDigits[bigint.size - i - 1];
	}

	return in;
}

// override addition operator
Bigint Bigint::operator+(const Bigint &bigint) const {
	Bigint sum;
	int carry = 0;
	sum.size = 0;
	int maxSize = size > bigint.size ? size : bigint.size;
	for (int i = 0; i < maxSize; i++) {
		int myDigit = (i < size) ? digits[i] : 0;
		int otherDigit = (i < bigint.size) ? bigint.digits[i] : 0;

		int digitSum = myDigit + otherDigit + carry;
		sum.digits[sum.size++] = (digitSum % 10);
		carry = digitSum / 10;
	}
	if (carry > 0) {
		sum.digits[sum.size++] = carry;
	}

	return sum;
}

// override subscript operator
int Bigint::operator[](const int i) const {
	if (size <= i) {
		return -1;
	}
	return digits[i];
}
// multiply by a single int
Bigint Bigint::timesDigit(int a) const {
	if (a == 0) {
		Bigint zero;
		return zero;
	}

	Bigint product;
	int carry = 0;
	product.size = 0;

	for (int i = 0; i < size || carry > 0; i++) {
		int myDigit = (i < size) ? digits[i] : 0;
		int smallProduct = myDigit * a + carry;

		if (product.size < CAPACITY) {
			product.digits[product.size++] = (smallProduct % 10);
		}
		carry = smallProduct / 10;
	}

	return product;
}

// shift left by 1
Bigint Bigint::times10(int a) const {
	Bigint temp;
	if (digits[0] == 0 && size == 1)
		return temp;
	if (a >= CAPACITY)
		return temp;

	temp.size = size + a;
	if (temp.size > CAPACITY)
		temp.size = CAPACITY;

	for (int i = 0; i < size && (i + a) < CAPACITY; i++) {
		temp.digits[i + a] = digits[i];
	}

	for (int i = 0; i < a && i < CAPACITY; i++) {
		temp.digits[i] = 0;
	}

	return temp;
}

// override multiply operator
Bigint Bigint::operator*(const Bigint &bigint) const {
	if (size == 0 || bigint.size == 0) {
		Bigint zero;
		return zero;
	}

	Bigint product;

	for (int i = 0; i < bigint.size; i++) {
		if (bigint.digits[i] != 0) {
			Bigint temp = timesDigit(bigint.digits[i]);
			temp = temp.times10(i);
			product = product + temp;
		}
	}

	return product;
}
