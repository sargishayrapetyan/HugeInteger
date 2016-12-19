#include <iostream>
#include <vector>
#include "HugeInteger.h"

HugeInteger::HugeInteger(int value)
	: size(0)
{
	if (value < 0) {
		sign = -1;
		value = -1 * value;
	}
	else
		sign = 1;

	while (value) {
		vec.push_back(value % 10);
			value = value / 10;
			size++;
	}
	//std::reverse(vec.begin(), vec.end());
}

HugeInteger::HugeInteger(const HugeInteger& other)
	: sign(other.sign)
	, size(other.size)
	, vec(other.vec)
{

}

HugeInteger& HugeInteger::operator=(const HugeInteger& other)
{	
	//if (this == &other)
		//return *this;

	size = other.size;
	sign = other.sign;
	vec = other.vec;
	return *this;
}

HugeInteger::~HugeInteger() 
{

}

bool HugeInteger::operator==(const HugeInteger& other) const
{
	if (size != other.size || sign != other.sign)
		return false;
	for (int i = 0; i < size; ++i) {
		if (vec[i] != other.vec[i])
			return false;
	}
	return true;
}

bool HugeInteger::operator<(const HugeInteger& other) const
{
	if (sign != other.sign)
		return sign < other.sign;

	if (sign == 1)
	{
		if (size < other.size)
			return size < other.size;
		for (int i = size - 1; i >= 0; --i)
			if (vec[i] != other.vec[i]) {
				return(vec[i] < other.vec[i]);
		
	}

		return false;
	}

	else
	{
		HugeInteger temp1 = *this;
		HugeInteger temp2 = other;
		temp1.sign = 1;
		temp2.sign = 1;
		return (temp1 > temp2);
	}
}

bool HugeInteger::operator>(const HugeInteger& other) const
{
	return !(*this < other);
}

HugeInteger& HugeInteger::operator+(const HugeInteger& other)
{
	if (sign == 1 && other.sign == -1)
	{	
		return (*this - other);
	}

	if (sign == -1 && other.sign == 1)
	{
		HugeInteger temp = *this;
		temp.sign = 1;
		*this = other;
		return (*this - temp);
	}
	
	int rem = 0;
	int index;
	for (index = 0; index < size || index < other.size; ++index)
	{
		int first = 0;
		int second = 0;
		if (index < size)
			first = vec[index];
		if (index < other.size)
			second = other.vec[index];
		int rem1 = first + second + rem;
		vec[index] = rem1 % 10;
		rem = rem1 / 10;
	}
	
	if (index >= size) {
		for (int i = 0; i < size; ++i)
		size = index;
	}
	
	if (rem){
		vec.push_back(rem);
		++size;
		}
	
	while (size > 1 && vec[size - 1] == 0)
		--size;
		
	return *this;
}

HugeInteger& HugeInteger::operator-(const HugeInteger& other)
{
	
	if ((*this < other) &&
		!(sign == -1 && other.sign == -1))
	{
		HugeInteger temp = *this;
		*this = other;
		*this = *this - temp;
		sign = -1;
		return *this;
	}
	std::cout << "operator " << std::endl;

	if (sign == 1 && other.sign == -1)
	{
		HugeInteger temp = other;
		temp.sign = 1;
		return (*this + temp);

	}

	if (sign == -1 && other.sign == 1)
	{
		HugeInteger temp = other;
		temp.sign = -1;
		return (*this + other);
	}

	int rem = 0;
	int tempsize = size;
	for (int index = 0; index < tempsize || index < other.size; ++index)
	{
		int first = 0;
		int second = 0;
		 if (index < tempsize)
			first = vec[index];
		 if (index < other.size)
			 second = other.vec[index];
		 int rem1 = first - second - rem;
		 if (rem1 < 0)
		 {
			 vec[index] = 10 + rem1;
			 rem = 1;
		 }
		 else
		 {
			 vec[index] = rem1;
				 rem = 0;
		 }
		 if (vec[index])
		 {
			 std::cout << "here size = " << size << std::endl;
			 std::cout << "here index =" << index << std::endl;
			 size = index + 1;
		 }
	
	}
	while (size > 0 && vec[size - 1] == 0)
	{
			--size;
	}
	return *this;
}

void HugeInteger::multiply(int number)
{
	int rem = 0;
	for (int i = 0; i < size || rem; ++i)
	{
		int temp = 0;
		if (i < size)
			temp = vec[i];
		int temp1 = number * temp + rem;
		vec[i] = temp1 % 10;
		rem = temp1 / 10;

		if (i == size)
		{
			++size;
			break;
		}
	}
}

int HugeInteger::getsize() const
{
	return size;
}

void HugeInteger::print() const
{
	for (int i = size -1; i >= 0; --i)
		std::cout << vec[i];
	std::cout << std::endl;
	std::cout << "size = " << size << std::endl;
	std::cout << "sign = " << sign << std::endl;

}