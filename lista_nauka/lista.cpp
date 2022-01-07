#include<cstdio>
#include <iostream>
#include<list>
#include<vector>

std::list<int> kopiowanie_vector_list(const std::vector<int>& vec)
{
	std::list<int> lista;
	
	for (const auto& elem : vec)
	{
		lista.push_back(elem);
	}


	return lista;
}
 
void wypisz_element_listy(const std::list<int>& lista)
{
	auto i = lista.begin();
	size_t liczba = 4;
	
	for (size_t idx = 0; idx < liczba; idx++)
	//for(const auto& idx:lista)
	{
		i++;
		
		std::cout << idx << "\n";
		std::cout << *i << "\n";
	}


}

int main(void)
{
	std::list<int> mietka{10,9,1,2,3,4,5,6,7,8,9,10 };
	
	wypisz_element_listy(mietka);

	std::vector<int> vector{ 1,2,3,4,5,6,7,8,9,10 };

	std::list<int> lista = kopiowanie_vector_list(vector);


	return 0;

}