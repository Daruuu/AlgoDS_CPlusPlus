// Ejemplo completo basado en "A Tour of C++" - Section 5.2.1
// Muestra: new/delete vs unique_ptr vs objeto local

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

// Clase de ejemplo que imprime cuando se construye/destruye
struct X
{
	int id;

	X(int i = 0) : id(i)
	{
		cout << "X(" << id << ") constructed at " << this << endl;
	}

	~X()
	{
		cout << "X(" << id << ") destroyed at "  << this << endl;
	}

	void do_something() const
	{
		cout << "   -> X(" << id << ") doing something...\n";
	}
};

// Funciones que reciben shared_ptr (del libro)
void f(shared_ptr<X> sp)
{
	cout << "  [f] using shared X(" << sp->id << ")\n";
	sp->do_something();
}

void g(shared_ptr<X> sp)
{
	cout << "  [g] using shared X(" << sp->id << ")\n";
	sp->do_something();
}

// ================================================================
// 1. VERSIÓN PELIGROSA: new + delete manual (fácil olvidar delete)
// ================================================================

void dangerous(int i, int j)
{
	cout << "\n--- DANGEROUS: new + delete manual ---\n";
	X* p = new X(100);		//allocate a new X

	if (i < 99)
	{
		cout << "Throwing exception..\n";
		throw runtime_error("Z unsing new");
	}
	if (j < 77) {
		cout << "Early return...\n";
		// delete p;  // ¡OLVIDADO! → FUGA DE MEMORIA
		return;
	}
	p->do_something();
	delete p;	//solo llega aqui si no hay un return ni exception
}

void safe_with_unique_ptr(int i, int j)
{
	cout << "\n--- SAFE: unique_ptr (RAII) ---\n";
	unique_ptr<X> sp { new X(200)};			// allocate and give to unique_ptr
	if (i < 99)
	{
		cout << "throwing exception... \n";
		throw runtime_error("Z in unique_ptr");
	}
	if (j < 77)
	{
		cout << "Early return...\n";
		// delete p;  // ¡OLVIDADO! → FUGA DE MEMORIA
		return;
	}
	sp->do_something();
	//	<- delete automatico al salir
}

// ================================================================
// 3. VERSIÓN IDEAL: objeto local (sin new)
// ================================================================
void best_local_object(int i, int j)
{
	cout << "\n--- BEST: local object (NO new) ---\n";
	X x(300);				//	use a local varible

	if (i < 99)
	{
		cout << "throwing exception... \n";
		throw runtime_error("Z in local object");
	}
	if (j < 77)
	{
		cout << "Early return...\n";
		// delete p;  // ¡OLVIDADO! → FUGA DE MEMORIA
		return;
	}
	x.do_something();
	//	<- destructor automatico al salir
}

// ================================================================
// 4. shared_ptr: propiedad compartida (del libro)
// ================================================================
void shared_example() {
	cout << "\n--- SHARED_PTR: shared ownership ---\n";
	shared_ptr<X> sp {new X(400)};
	cout << "use_count: " << sp.use_count() << endl;

	f(sp);  // copia → use_count = 2
	cout << "after f, use_count: " << sp.use_count() << endl;

	g(sp);  // copia → use_count = 3
	cout << "after g, use_count: " << sp.use_count() << endl;

	// ← se destruye cuando el último shared_ptr sale
}

// ================================================================
// make_X: devolver unique_ptr (del libro)
// ================================================================
unique_ptr<X> make_X(int i) {
	return unique_ptr<X>{new X(i)};
}

int	main()
{
	cout << "=== RAII DEMO (basado en Bjarne Stroustrup) ===\n";
	try
	{
		dangerous(50, 80);
	}
	catch (...)
	{
		cout << "Exception caught (memory leaked in dangerous)\n";
	}
	try {
		safe_with_unique_ptr(50, 80);  // excepción → ¡sin fuga!
	} catch (...) {
		cout << "Exception caught (NO leak with unique_ptr)\n";
	}

	try {
		best_local_object(120, 50);    // return temprano → ¡sin fuga!
	} catch (...) {}

	shared_example();
	// Usar make_X
	cout << "\n--- Using make_X ---\n";
	auto ptr = make_X(500);
	ptr->do_something();
	return (0);
}
