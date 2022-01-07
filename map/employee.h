#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

class Employee
{
public:
	Employee(const std::string& name, const std::string& position, int age);
	~Employee() = default;
	friend int main();
	friend std::ostream& operator<< (std::ostream& ostr, const  Employee& employee);

private:
	std::string Name;
	std::string Position;
	int Age;
};

std::ostream& operator<< (std::ostream& ostr, const  Employee& employee);

#endif // !EMPLOYEE_H
