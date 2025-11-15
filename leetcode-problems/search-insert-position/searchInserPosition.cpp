#include <iostream>
#include <algorithm>
#include <vector>

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
