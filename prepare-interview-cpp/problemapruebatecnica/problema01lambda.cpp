#include <iostream>

void f(int a = []()
{
	static int b = 1;
	return b++;
}())
{
	std::cout << a;
}

int main(void)
{
	std::cout << "problema 01:\n";
	f();
	f();
	std::cout << "problema 02:\n";
	return 0;
}
