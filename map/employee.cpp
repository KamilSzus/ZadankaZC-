#include "employee.h"
Employee::Employee(const std::string& name, const std::string& position, int age)
	:Name(name)
	,Position(position)
	,Age(age)
{}

std::ostream& operator<<(std::ostream& ostr, const Employee& employee)
{
	ostr << employee.Name << ", " << employee.Position << ", " << employee.Age;
	return ostr;
}


