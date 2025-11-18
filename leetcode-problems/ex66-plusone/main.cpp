#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits)
{
	int n = digits.size();

	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] < 9)
		{
			digits[i]++;
			return (digits);
		}
		digits[i] = 0;
	}

	std::vector <int> result(n + 1, 0);

	result[0] = 1;
	return (result);
}

int	main(void)
{
	std::vector<int> nums = {1, 2, 3, 4, 5};

	plusOne(nums);

	for (int n : nums)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;

	return (0);
}

