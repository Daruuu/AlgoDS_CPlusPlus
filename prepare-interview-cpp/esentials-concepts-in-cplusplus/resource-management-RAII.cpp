#include <iostream>

struct unique_ptr<X> {
	X* ptr;
	~unique_ptr() { delete ptr; }  // ← RAII: destructor libera
};

void f(int i, int j)
{
	X* p = new X;
	if (i < 99)
		throw Z{};
	if (j < 77)
		return;
	p->do_something();
	delete p;
}

int main()
{
	std::cout << "Versión incorrecta (con new y delete manual)\n" << std::endl;
	f();
	return (0);
}
