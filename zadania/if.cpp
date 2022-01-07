#include<iostream>
#include<list>
#include <algorithm>


int main2(void)
{
	using m_List = std::list<std::string>;
	
	m_List test{
		"one"//0
		,"two"//1
		,"three"//2
		,"four"//3
		,"five"//4
		,"six"//5
		,"seven"//6
		,"eight"//7
		,"nine"//8
	};

	auto number = 0;

	std::cin >> number;

	if (number > 9)
	{

		std::cout << "Greater than 9";
	}
	else if (number > 0 )
	{
		m_List::iterator it = test.begin();

		std::cout << *std::next(it, number-1);;
	}
	else
	{
		std::cout << "error";
	}

	//std::copy(std::next(test.begin(),0),std::next(test.end(),-1*test.size()+1),
	//	std::ostream_iterator<ListT::value_type>(std::cout,"\n")
	//	);


	return 0;
}