#include <iostream>
#include <vector>
#include <memory>

int main ()
{
	int x = 42;
	std::vector<int> v = {1, 2, 3, 4};
	auto p = std::make_unique<int>(99);
	std::cout << x << " " << v[0] << " " << *p << std::endl;

	return 0;
}