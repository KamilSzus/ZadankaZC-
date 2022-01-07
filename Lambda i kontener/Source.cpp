#include<iostream>
#include<string>
#include<array>
#include<algorithm>

bool compare(int lhs,int rhs)
{
	return lhs > rhs;
}

struct Comparer
{
	Comparer(int pivot)
		:m_pivot{pivot}
	{ }
	bool operator()(int lhs, int rhs)
	{
		if (m_pivot > 2)
		{
			return lhs < rhs;
		}

		return lhs > rhs;
	}
	int m_pivot;
};

int main()
{
	std::array<int, 10> data{-8,6,0,-1,-7,5,3,-4,-2,5};

	//std::sort(data.begin(), data.end(), compare);
	
	int delim = 5;
	// std::sort(data.begin(), data.end(), Comparer(delim));
	Comparer comparer{ delim };

	//std::sort(data.begin(), data.end(), comparer);

	std::sort(data.begin(), data.end(),
		[delim](int lhs, int rhs)->bool {
		if (delim > 2)
	{
		return lhs < rhs;
	}

	return lhs > rhs; });
	

	for (auto elem : data)
	{
		std::cout << elem << ' ';
	}

	return 0;
}