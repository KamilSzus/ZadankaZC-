#include "complex.h"

int main()
{
	Complex a(-5, -15), b(5, 15), z(3), c;
	
	a /=b;
	std::cout << a << '\n';
	b /= 5.0;
	std::cout << b <<'\n';
	z /= 5.0;
	std::cout << z << '\n';
	c = a / b;
	std::cout << c << '\n';
	c = b / 5.0;
	std::cout << c << '\n';
	c = 5.0 / z;
	std::cout << c << '\n';
	z = a.arg();
	c = c.abs();
	std::cout << c<< '\n';
	std::cout << z << '\n';
	std::cout << c.conj() << '\n';
}
