#include<iostream>
#include<array>
#include<vector>


struct Point
{
	int m_x;
	int m_y;

	Point(int x, int y)
		:m_x{x}
		,m_y{y}
	{}

};

int main()
{
	std::ios::sync_with_stdio(false);

	std::cin.tie(nullptr);


	Point p(1.2,2);
	Point q{1,2};



	std::cout << p.m_x << ' ' << p.m_y << '\n';

	std::vector<int> vec = {2,4,6,8,2,4,6,8 ,2,4,6,8 ,2,4,6,8 };

	std::cout << sizeof(vec.data()) << '\n';
	
	std::cout << sizeof(vec)<<'\n';

	std::array arr = { 2,4,6,8 };
	std::array<int,1'000'000> arr_big = { 2,4,6,8 };

	std::cout << sizeof(arr) << '\n';

	//int* parr = new int[4];
	int parr[4];
	
	std::cout << sizeof(parr) << '\n';

	return 0;
}