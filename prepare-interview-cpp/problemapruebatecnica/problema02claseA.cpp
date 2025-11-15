#include <iostream>

class A
{
	int foo = 0;

public:
	int& getFooRef() { return foo; }
	void printFoo () { std::cout << foo; }
};
// int* getFooPtr() { return foo; }

int main()
{
	A a;

	auto bar = a.getFooRef();
	bar++;
	a.printFoo();

	return 0;
}

/*
	auto& bar = a.getFoo();
	++bar;
	auto bar = a.getFooPtr();
	bar++;
	a.printFoo();
*/
