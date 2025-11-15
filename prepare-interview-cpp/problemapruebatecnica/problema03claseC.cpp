#include <iostream>
#include <map>

bool dc = false;
bool c = false;
bool a = false;

class C
{
public:
	C() { dc = true;}
	C(int) { c = true;}
	C& operator=(const C&)
	{
		a = true;
		return *this;
	}
};

int main()
{
	std::map<int, C> m;
	m[7] = C(1);

	//			true << true << false
	std::cout << dc << c << a;

	return 0;
}

