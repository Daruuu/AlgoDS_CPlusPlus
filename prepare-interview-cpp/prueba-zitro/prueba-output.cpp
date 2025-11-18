#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

auto my_comparor = [](const auto& i, const auto& j) {return (i > j);};

template <typename T>
using my_set = std::set<T, decltype(my_comparor)>;

template <typename T>
const my_set<T> Transform(const std::vector<T>& aElements)
{
	my_set<T> Return(my_comparor);
	std::for_each(aElements.cbegin(), aElements.cend(),
	[&Return](const T& aElement)
	{
		if (aElement % 2)
		{
			Return.emplace(aElement);
		}
	});
	return Return;
}

int	main()
{
	std::vector <int> Inds{2, 3, 4, 1, 7, 5, 8, 6, 9, 15, 10, 16, 14};

	auto&& Result = Transform(Inds);

	std::for_each(Result.crbegin(), Result.crend(), [](const auto& aInd)
	{
		std::cout << aInd << std::endl;
	});
}
