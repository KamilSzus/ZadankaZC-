#include <iostream>

#include "employee.h"			//defines class Employee
#include "map_template.h"		//defines template map_template<Key,Value>
#include"library.h"

int main()
{
	typedef unsigned int ID; 							//Identification number of Employee
	map_template<ID,Employee> Database;					//Database of employees

	Database.Add(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	Database.Add(510212881,Employee("Adam Nowak","storekeeper",54)); 	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	Database.Add(730505129,Employee("Anna Zaradna","secretary",32)); 	//Add third employee: name: Anna Zaradna, position: secretary, age: 32

	std::cout << Database << '\n';							//Print databese

	map_template<ID,Employee> NewDatabase = Database;	//Make a copy of database
	
	Employee* pE;
	pE = NewDatabase.Find(510212881);					//Find employee using its ID
	pE->Position = "salesman";							//Modify the position of employee
	pE = NewDatabase.Find(761028073);					//Find employee using its ID
	pE->Age = 29;										//Modify the age of employee

	Database = NewDatabase;								//Update original database
	
	std::cout << Database << '\n';							//Print original databese



	typedef std::string title;
	map_template<title, Library> Data;

	Data.Add("Wladca Pierscieni", Library("Tolkien", "Fantastyka", 1280,true)); 
	Data.Add("Zgroza w Dunwitch", Library("Lovecraft", "Horror", 793,true)); 
	Data.Add("Nadzor", Library("Fletcher", "Fantastyka", 539,false)); 

	std::cout << Data << '\n';							//Print databese

	map_template<title, Library> NewData = Data;	//Make a copy of database

	Library* pL;
	//pL = NewData.Find("Wladca Pierscieni");					//Find employee using its ID
	//pL->m_number_of_pages = 1300;							//Modify the position of employee
	pL = NewData.Find("Nadzor");					//Find employee using its ID
	pL->m_in_out = true;										//Modify the age of employee

	//Data = NewData;								//Update original database

	std::cout << Data << '\n';							//Print original databese
}