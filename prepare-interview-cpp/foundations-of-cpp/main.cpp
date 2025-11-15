#include "Animal.hpp"
#include "Dog.hpp"

int main(void) {
	// Llamada estática: se ejecuta Animal::makeSound()
	// Animal a;
	// a.makeSound();

	{
		std::cout << "********** POLIMORFISMO EN HEAP **********\n";
		std::cout << "HEAP: Creamos un puntero de tipo Animal* que apunta a un objeto Dog creado con new.\n";
		std::cout << "Gracias al polimorfismo en tiempo de ejecución (gracias a virtual), \n";
		std::cout << "se llama a Dog::makeSound() aunque el puntero sea de tipo Animal*.\n";
		std::cout << "*************************************************\n";

		Animal* ptr = new Dog();   // Objeto en heap, tipo dinámico: Dog
		ptr->makeSound();          // → Llama a Dog::makeSound() [polimorfismo]
		delete ptr;                // Liberamos la memoria
	}
	{
		std::cout << "\n********** INSTANCIACIÓN DIRECTA EN HEAP **********\n";
		std::cout << "HEAP: Creamos un objeto Dog directamente (sin usar la clase base).\n";
		std::cout << "No hay polimorfismo aquí: el tipo estático y dinámico son Dog.\n";
		std::cout << "Se llama directamente a Dog::makeSound().\n";
		std::cout << "******************************************************\n";

		Dog* d = new Dog();        // Objeto en heap, tipo explícito: Dog
		d->makeSound();            // → Llama a Dog::makeSound() [sin polimorfismo]
		delete d;                  // Liberamos la memoria
	}


	return 0;
}