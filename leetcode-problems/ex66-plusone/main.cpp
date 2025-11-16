#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits)
{

	std::string str = ""; 
	//char str[] = ""; 
	for (int i = 0; i <= digits.size() - 1; ++i)
	{
		str += digits[i] + '0';
	}
	std::cout << "value in string: "<< str << std::endl;
	int res = std::stoi(str);
	res++;
	std::cout << "value in integer: "<< res << std::endl;


	return (std::vector<int> {0});
}

int	main(void)
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	plusOne(nums);

	return (0);
}
