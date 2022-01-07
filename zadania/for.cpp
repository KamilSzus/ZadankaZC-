#include<iostream>
#include<list>
#include <algorithm>

using ListT = std::list<std::string>;

class Lista
{
public:
	void foo(int number);
	
	bool is_odd(int number);

	void sort();

private:
	

	ListT test{
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

};

void Lista::foo(int number)
{

		ListT::iterator it = test.begin();

		std::cout << *std::next(it, number - 1)<<'\n';

}

bool Lista::is_odd(int number)
{
	return number%2!=0;
}

void Lista::sort()
{
	test.sort();//TO DO lambda zrobic 
}


int main()
{
	Lista lista{};

	int min{};
	auto max = 0;

	std::cin >> min>>max;

	for (auto i = min; i <= max; i++)
	{
		if (i < 10)
		{
			lista.foo(i);
		}
		else
		{
			if (lista.is_odd(i))
			{
				std::cout << "odd" << '\n';
			}
			else
			{
				std::cout << "even" << '\n';
			}
		}
	}

	lista.sort();

	//std::copy(std::next(test.begin(),0),std::next(test.end(),-1*test.size()+1),
	//	std::ostream_iterator<ListT::value_type>(std::cout,"\n")
	//	);


	return 0;
}