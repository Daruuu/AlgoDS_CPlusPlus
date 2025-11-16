#include <iostream>

//	estamos creando una copia de res dentro de la funcion
void sumaParamValue( int a, int b , int res)
{
    res = a + b;
}

//	estamos pasando el valor original de la variable res
//	si modificamos res despues de la llamada a esta funcion el valor estar
//	actualizado
void sumaParamRef( int a, int b , int &res)
{
    res = a + b;
}

int	 main(void)
{
	int a = 5;
	int	b = 3;

	int	res = 20;
	//sumaParamValue(a, b, res);
	sumaParamRef(a, b, res);

	std::cout << "value a: [" << a << "]" << std::endl;
	std::cout << "value b: [" << b << "]" << std::endl;
	std::cout << "result: [" << res << "]" << std::endl;


	return (0);
}
