#include <iostream>
#include <algorithm>
#include <vector>
/*
int	searchInsert(std::vector<int>& nums, int target)
{
	unsigned int i = 0;

	for(auto it = nums.begin(); it != nums.end(); ++it)
	{
		if (nums[i] == target)
		{
			return (i);
		}
		i++;
	}
	return (i);
}
*/
/*
 * El algoritmo de **búsqueda binaria**:
 * funciona dividiendo repetidamente a la mitad un **array ordenado** 
 * hasta encontrar el objetivo o determinar dónde debería insertarse.
 * Comienza definiendo dos punteros: `left` (inicio) y `right` (final).
 * Mientras `left <= right`, calcula el punto medio `mid`.
 * Si `nums[mid]` es igual al `target`, devuelve `mid`.
 * Si es menor, descarta la mitad izquierda (`left = mid + 1`);
 * si es mayor, descarta la derecha (`right = mid - 1`).
 * Al finalizar el bucle (cuando no hay más mitades), `left` señala la **posición exacta**
 * donde `target` debería insertarse para mantener el orden,
 * logrando una complejidad de **O(log n)** al reducir el espacio de búsqueda a la mitad en cada paso.
 */

int	searchInsert(std::vector<int>& nums, int target)
{
	int	 left = 0;
	int	 right = nums.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;	// evitamos overflow

		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (left);
}

int main()
{
	std::vector<int> v = {1, 3, 5, 6};

	int	result1 = searchInsert(v, 5);
	std::cout << "test1: [" << result1 << "]"<< std::endl;

	int	result2 = searchInsert(v, 2);
	std::cout << "test2: [" << result2 << "]"<< std::endl;

	int	result3 = searchInsert(v, 7);
	std::cout << "test3: [" << result3 << "]"<< std::endl;

	return (0);
}
