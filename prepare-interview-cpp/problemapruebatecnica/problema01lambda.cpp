#include <iostream>
/*
 * la funcion 'f' tiene un parametro 'int a' con un valor por defecto definido
 * por una 'expresion lambda' " [](){ static int b = 1; return b++; }() ".
 * esta funcion lambda se ejecuta sola la primera vez que se llama a f() sin
 * argumento, iniciamos b a 1 y retornamos b sin actualizar el valor original.
 * al llamar a f() 1ra vez nos mostrara 1 y 
 * la segunda vez nos deberia mostrar 2.
 */

//	version C++11
void f(int a = []()
{
	static int b = 1;
	return b++;	// primero retorna el valor y despues incrementa(retorna 1)
}())
{
	std::cout << a << std::endl;
}

int main(void)
{
	std::cout << "problema 01:\n";
	f();
	f();
	return 0;
}
