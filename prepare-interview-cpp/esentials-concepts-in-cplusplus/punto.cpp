#include "punto.hpp"

#include <iostream>

int contador_global = 0;

void incrementar()
{
	contador_global++;
}

template<class T, class U>
auto multiplicar(T a, U b) -> decltype(a * b) {
	return a * b;
}

int main()
{
	incrementar();
	std::cout << "value of contador  global: " << contador_global << std::endl;

	{
		std::cout << "Ejercicio 2: Múltiples nombres con declaradores\n";

		int* p;
		int q;
		int r[5]= {1,2, 3, 4, 5};
		int *t;

		q = 10;
		p = &q;
		t = &q;

		std::cout << "int *p: " << p << std::endl;
		std::cout << "\nint q: " << q << std::endl;
		std::cout << "\nint r[5]: " << std::endl;
		int i = 0;
		while (i < 5)
		{
			std::cout << "r[" << r[i] <<"] - " ;
			i++;
		}
		std::cout << "\nint *t: value store in *t: " << *t << std::endl;
	}

	{
		std::cout << "\n6.3.5 Initialization Ejercicio 1: Narrowing con {}\n";
		char c1 = 1000;
		// char c2 {1000};     // no compila por que 1000 no es un caracter y necesita que este entre literales
		//int x {3.14};     // no compila por el tipo de dato que es un double
		int x1 {3};
		double d {5};
		std::cout << "value of char c1: " << c1 << std::endl;
		std::cout << "\nvalue of int x3: " << x1 << std::endl;
		std::cout << "\nvalue of double d: " << d << std::endl;
	}

	{
		std::cout << "Ejercicio 2: auto + {} vs =\n" << std::endl;

		// auto a {1, 2, 3};	// fallar
		auto b = {1, 2, 3};
		auto c {1};
		auto d = 1;

		std::cout << "b : " << typeid(b).name() << '\n';
		std::cout << "c : " << typeid(c).name() << '\n';
		std::cout << "d : " << typeid(d).name() << '\n';

	}
	{
		std::cout << "\n6.3.6.3 decltype() Ejercicio 1: Tipo de retorno genérico\n" << std::endl;
		int valueTest1 = multiplicar(3, 4.5);
		std::cout << "return of multiplicar(3, 4.5): " << valueTest1 << "\n";
		// auto valueTest2 = multiplicar("hola", 2);
	}

	{
		/*
		*📘 Regla general de decltype(expr)
		Si expr es un nombre de variable,
		👉 decltype(expr) es el tipo declarado de esa variable.

		Si expr es una expresión que da un lvalue (objeto al que se puede asignar),
		👉 decltype(expr) es T&, donde T es el tipo del objeto.

		Si expr es una expresión que da un xvalue (objeto “movible”),
		👉 decltype(expr) es T&&.

		Si expr es un rvalue “puro” (como una suma, literal, o llamada que devuelve por valor),
		👉 decltype(expr) es T, el tipo del resultado.
		*/
		std::cout << "Ejercicio 2: decltype con expresiones" << "\n";
		int x = 5;
		const int& r = x;

		decltype(x) a;        // x es un nombre de variable → decltype devuelve su tipo declarado
		// decltype((x)) b;      // ?
		// decltype(r) c;        // r es una referencia constante → devuelve tipo declarado (const int&)
		decltype(x + 1.0) d;  // ?
	}
	return 0;
}
