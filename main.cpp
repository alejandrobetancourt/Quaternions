#include <iostream>;
#include "Quaternion.h";

int main()
{
	Quaternion q(1, 2, 3, 4);
	Quaternion p(2,3,6,2);
	std::cout << "We define a class to carry out computations with quaternions." << std::endl;
	std::cout << "We represent quaternions as vectors in R^4." << std::endl;
	std::cout << " " << std::endl;
	std::cout << "So for example q = 1 + 2i + 3j + 4k is represented by the" << std::endl;
	std::cout << "vector " << std::flush;
	Print(q);
	std::cout << " " << std::endl;
	std::cout << "We have the usual operations between quaternions, for example " << std::endl;
	std::cout << "calling the function q.conjugate() retrns the conjugate " << std::endl;
	Print(q.conjugate());
	std::cout << " " << std::endl;
	std::cout << "Likewise, q.inverse() will return the multiplicative inverse of q" << std::endl;
	Print(q.inverse());
	std::cout << " " << std::endl;
	std::cout << "We can also carry out the arithmetic operations +, -, *, /." << std::endl;
	std::cout << "The product of  " << std::flush;
	Print(p);
	std::cout << " and " << std::flush;
	Print(q);
	std::cout << " is " << std::endl;
	Print(p * q);
	Print(q * p);
	std::cin.get();
	return 0;
}