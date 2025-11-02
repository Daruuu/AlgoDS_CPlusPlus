#include "inside-the-c++object-model-book/basics/max1.hpp"
#include <iostream>
#include <string>

template <typename  T1, typename T2, typename RT>
RT max(T1 a, T2 b)
{
	return b < a ? RT(a) : RT(b);
}

int main()
{
	// ::max<int, double, double> (4, 7,2);
	// ::max<double, int, double>(4, 7,2);
	std::cout << "This test show a TEMPLATE WITH 3 PARAMETERS: (Return Type)"<< std::endl;

	std::cout << "case <int, double, double> := [" << ::max<int, double, double> (4, 7.2) << "]" << std::endl;
	std::cout << "case <double, int, double> := [" << ::max<double, int, double>(4, 7.2)<< "]" << std::endl;
	return (0);
}

/*
	//basics/max1.cpp
int main()
{
	int i = 42;
	std::cout << "max(7,i): 	" << ::max(7,i) << "\n";

	double f1 = 3.4;
	double f2 = -6.7;
	std::cout << "max(f1,f2): " << ::max(f1,f2) << "\n";

	std::string s2 = "mathematics";
	std::string s1 = "math";

	std::cout << "max(s1,s2): " << ::max(s1,s2) << "\n";
}
*/