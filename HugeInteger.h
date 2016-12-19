#pragma once
#include <vector>

using std::vector;

class HugeInteger {

public:
	HugeInteger(int);
	HugeInteger(const HugeInteger& other);
	HugeInteger& operator=(const HugeInteger& other);

public:
	~HugeInteger();

public:
	bool operator==(const HugeInteger& other) const;
	bool operator>(const HugeInteger& other) const;
	bool operator<(const HugeInteger& other) const;

public:
	HugeInteger& operator+(const HugeInteger& other);
	HugeInteger& operator-(const HugeInteger& other);

public:
	int getsize() const;
	void multiply(int number);
	void print() const;
private:
	vector<int> vec;
	int sign;
	int size;

};