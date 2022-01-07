#include<iostream>
#include<memory>

struct Ksiazka
{
	//Ksiazka() = default;
	Ksiazka(int c) 
		:x{c}
	{

	}
	int x =1;
	char b;
	float z=2.5;
};


int main()
{
	Ksiazka* book = new Ksiazka(-2);
	//Ksiazka* books = new Ksiazka[5];
	// Ksiazka* books = new Ksiazka[5]{Ksiazka(-2)};

	std::unique_ptr<Ksiazka> pBook ( new Ksiazka(-2));

	std::unique_ptr<Ksiazka> pBook_ = std::make_unique<Ksiazka>();


	book->b = 'a';

	pBook->b = 'a';

	std::unique_ptr<Ksiazka> pBook2{ pBook.release() };

	pBook.reset(new Ksiazka(24));

	pBook = std::move(pBook2);


	std::unique_ptr<Ksiazka> pBook3{ pBook.release() };


	//std::auto_ptr<Ksiazka> pBookOLD(new Ksiazka(666));

	//std::unique_ptr<Ksiazka[]> pBookTab(new Ksiazka[5]);
	std::unique_ptr<Ksiazka[]> pBookTab_ = std::make_unique<Ksiazka[],5>(8);


	std::shared_ptr<Ksiazka> psBook(new Ksiazka(-2));

	//std::shared_ptr<Ksiazka[]> psBookTab_ = std::make_shared<Ksiazka[]>(5);







	//int res = sizeof(book);

	//std::cout << res<<'\n';

	//res = alignof(Ksiazka);

	//std::cout << res;

	return 0;
}