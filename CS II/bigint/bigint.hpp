/*
 * TJ Raklovits
 * Bigint
 * CS 23001
 */
#include <iostream>
#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP

const int CAPACITY = 300;

class Bigint {
private:
	int digits[CAPACITY];
	int size = 0;

public:
	void reset();
	Bigint();
	Bigint(const char[]);
	Bigint(int);
	void debugPrint(std::ostream &) const;
	bool operator==(const Bigint &) const;
	friend std::ostream &operator<<(std::ostream &, const Bigint &);
	friend std::istream &operator>>(std::istream &, Bigint &);
	Bigint operator+(const Bigint &) const;
	int operator[](const int) const;
	Bigint timesDigit(const int) const;
	Bigint times10(const int) const;
	Bigint operator*(const Bigint &) const;
};

#endif
