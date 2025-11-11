#ifndef POINTERSANDREFERENCES
#define POINTERSANDREFERENCES

#include <iostream>
#include <memory>
#include <vector>

int suma(int a, int b)
{
	return a + b;
}

int main()
{
	std::cout << "🔸🔸🔸🔸🔸🔸🔸🔸 2.Diferencias entre * y & 🔸🔸🔸🔸🔸🔸🔸🔸 " << std::endl;
	int x = 10;
	int* ptr = &x;   // ptr guarda la dirección de x
	int& ref = x;    // ref es una referencia (alias) a x

	std::cout << "===== Estado inicial =====\n";
	std::cout << "Valor de x:                 " << x << "\n";
	std::cout << "Direccion de x (&x):        " << &x << "\n";
	std::cout << "Direccion guardada en ptr:  " << ptr << "\n";
	std::cout << "Direccion en formato HEX :  " << std::hex << ptr << std::dec;
	std::cout << "\nValor apuntado por *ptr:    " << *ptr << "\n";
	std::cout << "Direccion de ref (&ref):    " << &ref << "\n";
	std::cout << "Valor de ref:               " << ref << "\n\n";

	// Modificar valores a través del puntero y la referencia
	*ptr = 20;
	ref = 30;

	std::cout << "===== Después de modificar =====\n";
	std::cout << "Valor de x:                 " << x << "\n";
	std::cout << "Valor apuntado por *ptr:    " << *ptr << "\n";
	std::cout << "Valor de ref:               " << ref << "\n";
	std::cout << "Direccion de x (&x):        " << &x << "\n";
	std::cout << "Direccion de ref (&ref):    " << &ref << "\n";
	std::cout << "Direccion guardada en ptr:  " << ptr << "\n";

	std::cout << "\n🔸🔸🔸🔸🔸🔸🔸🔸 3. Puntero nulo(nulptr) since C++11 🔸🔸🔸🔸🔸🔸🔸🔸" << std::endl;
	std::cout << "Un puntero que no apunta a ninguna dirección válida." << std::endl;

	int	*p = nullptr;
	if (p == nullptr)
		std::cout << "no apunta a nada\n";

	// std::cout << "Valor apuntado por *p:   [" << *p << "]\n";
	std::cout << "dato guardado en p: [" << p << "]\n";
	int num = 5;
	p = &num;
	std::cout << "Direccion guardada en p: [" << p << "]\n";
	std::cout << "contenido de p: [" << *p << "]\n";

	std::cout << "\n🔸🔸🔸🔸🔸🔸🔸🔸 3. Puntero a funciones 🔸🔸🔸🔸🔸🔸🔸🔸 " << std::endl;
	std::cout
		<< "Un puntero a función guarda la dirección de una función (como si fuera un callback)."
	<< std::endl;

	// puntero a función que recibe (int, int) y devuelve int
	int (*pf)(int, int) = &suma;

	//	se puede llamar de esta manera:
	int resValue = pf(3, 5);
	std::cout << "Hemos creado una funcion suma(int a, int b)\n" << std::endl;
	std::cout << "valor de retorno de 'resValue': [" << resValue << "]" <<std::endl;

	std::cout << "\n🔸🔸🔸🔸🔸🔸🔸🔸 5. Puntero inteligentes🔸🔸🔸🔸🔸🔸🔸🔸 " << std::endl;
	std::cout << "Los smart pointers del '<memory>' son clases que administran automáticamente \n"
			  "la memoria del objeto que apuntan, evitando fugas o dobles liberaciones.\n"
	"std::unique_ptr<T>\nPosee exclusivamente el objeto.\nNo se puede copiar, solo mover (std::move)."
	<< std::endl;
	// std::unique_ptr<std::vector<int>> p1 = std::make_unique<std::vector<int>>(5, 10);

	// std::unique_ptr<int> p2 = std::move(p1); // transfiere propiedad

	{
		std::cout << "\n🔸🔸🔸🔸🔸🔸🔸🔸 6. Pequenyo problema a practicar:\n" << std::endl;

		// 1. Crear un entero x = 42
		int x = 423;

		// 2. Crear un puntero p que apunte a x
		int* p = &x;

		// 3. Crear una referencia r que referencie a x
		int& r = x;

		// Mostrar valores iniciales
		std::cout << "Valores iniciales:\n";
		std::cout << "x  = " << x  << std::endl;
		std::cout << "*p = " << *p << std::endl;
		std::cout << "r  = " << r  << std::endl;
		std::cout << std::endl;
		*p = 43;
		r = 100;
		// 5. Imprimir x, *p y r para mostrar que son iguales
		std::cout << "Después de modificar a través del puntero y la referencia:\n";
		std::cout << "x  = " << x  << std::endl;  // Debe ser 200
		std::cout << "*p = " << *p << std::endl;  // Debe ser 200
		std::cout << "r  = " << r  << std::endl;  // Debe ser 200
		std::cout << std::endl;

		// Bonus: Mostrar direcciones para entender mejor
		std::cout << "Direcciones (para entender punteros y referencias):\n";
		std::cout << "&x  = " << &x  << std::endl;
		std::cout << "p   = " << p   << std::endl;
		std::cout << "&r  = " << &r  << std::endl;
		std::cout << std::endl;

	}
	return 0;
}

#endif