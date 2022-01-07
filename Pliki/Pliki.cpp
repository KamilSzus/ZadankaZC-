#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include<iomanip>


//Praca domowa zapis do strumienia i utworzyc plik tekstowy i napisaæ konstruktor w klasie person


template<typename TValue>
struct Number
{
	Number(TValue value)
		:m_value{ value }
	{}

	TValue operator ()()
	// TValue operator ()() const
	{
		TValue temp = m_value;

		m_value += 2;

		return temp;
	}

private:
	TValue m_value;
	//mutable TValue m_value;
};

class Person
{
public:
	Person(int value,float avg,const std::string& name)
		:m_value{value}
		,m_avg{avg}
		,m_name{name}
	{}
	~Person(){
		std::cout << "D-tor";
	}

	void serialize(std::ostream& ostr);
	
	void deserialize(std::ostream& ostr);// TO DO 

private:
	int m_value;
	
	float m_avg;

	std::string m_name;

};

void Person::serialize(std::ostream& ostr)
{

	//ostr.write(reinterpret_cast<char*>(this), sizeof(Person));

	ostr.write(reinterpret_cast<char*>(&m_value), sizeof(m_value));
	
	ostr.write(reinterpret_cast<char*>(&m_avg), sizeof(m_avg));
	
	//ostr.write(reinterpret_cast<char*>(&m_name), sizeof(m_name));
	
	size_t size = m_name.size();
	//size_t size = m_name.length();

	ostr.write(reinterpret_cast<char*>(&size), sizeof(size));

	ostr.write(m_name.data(), size + 1);
	//ostr.write(m_name.c_str() , size+1);


	char end = 1;
	ostr.write(&end, 1);

	int number = -2;

	ostr.write(reinterpret_cast<char*>(&number), 1);

	//ostr << "ala";
}

void Person::deserialize(std::ostream& ostr)
{
}



int main()
{
	bool test = true;

	std::cout << test<<'\n';

	std::cout << std::boolalpha;

	std::cout << test << '\n';

	std::cout << std::noboolalpha;

	std::cout << test << '\n';

	std::cout.precision(2);
	std::cout << std::setprecision(2);

	// std::cout << std::setw(6) << 123.45678;
	std::cout << std::fixed << 123.45678;

	std::cout.width(6);

	char sign = 'A';
	int value = 5;
	std::cout.write(&sign,1).write("lmnb",1).write("a",2).write((char*)&value,sizeof(int));

	//	typedef std::list<int> IntList;

	using IntList = std::list<int>;

	IntList data(10);

	std::iota(data.begin(), data.end(), 12);//wype³nia po koleji w tym przypadku od 12,13...

	//for (auto value : data)
	//{
	//	std::cout << value<<'\n';
	//}

	std::copy(std::next(data.begin(), 0), std::next(data.end(), 0),
		std::ostream_iterator<decltype(data.front())>(std::cout, " "));

	std::cout << '\n';

	std::copy(std::next(data.begin(), 3), std::next(data.end(), -2),
		std::ostream_iterator<IntList::value_type>(std::cout, "\n"));

	Number<IntList::value_type> number{ -4 };

	std::generate(data.begin(), data.end(), number);

	IntList::value_type init = 23;

	std::generate(data.begin(), data.end(), [&init]() {return init += 2;
		});
	std::cout << init << '\n';
	std::ofstream fout("output.txt", std::ios::out);

	if (fout.is_open())
	{
		std::copy(data.begin(), data.end(),
			std::ostream_iterator<IntList::value_type>(fout, "\n"));

		fout.close();
	}
	{
		Person person{ 5, -3.8f, "Beata" };

		std::ofstream bout{ "output.bin",std::ios::out | std::ios::binary };

		person.serialize(bout);

		bout.close();
	}
	//bout.write(char*)(&person),sizeof(Person));
	{
		Person osoba{ 0,0.0f,"NN" };

		std::ifstream bin{ "output.bin",std::ios::in | std::ios::binary };

		//bin.read(reinterpret_cast<char*>(&osoba), sizeof(Person));
		bin.close();
	}

	return 0;
}
