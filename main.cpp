#include <iostream>
#include "HugeInteger.h"

using std::cout;
using std::endl;

int main()
{
	HugeInteger Hint(700);
	Hint.print();
	HugeInteger Hint2(500);
	//Hint2.print();
	//Hint.multiply(2);
	Hint = Hint + Hint2;
	Hint.print();
	Hint = Hint2 - Hint;
	Hint.print();
}