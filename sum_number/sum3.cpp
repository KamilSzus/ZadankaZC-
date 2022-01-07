#include<iostream>
#include<vector>

int main()
{
	using My_vector = std::vector<int>;
	
	My_vector vector;

	vector.reserve(3);

	for (size_t i =0; i<3;i++)
	{
		int value = 0;

		std::cin >> value;

		vector.push_back(value);
	}

	auto result = 0;

	for (auto value : vector)
	{
		result += value;
	}

	std::cout << result;

	return 0;
}