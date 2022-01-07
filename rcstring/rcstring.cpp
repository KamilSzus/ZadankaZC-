#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "rcstring.h"

int main()
{
	rcstring a, b, c;
	a = "10";
	b = "ala ma kota";
	cout << a << " " << b << '\n'; // 10 ala ma ma kota
	c = a + b;
	cout << c << '\n'; // 10ala ma kota
	c = a + rcstring(" ") + b;
	cout << c << '\n'; //10 ala ma kota
	rcstring d("a");
	cout << d << '\n'; //a
	d += "ula";
	cout << d << '\n'; //aula
	d += "15";
	cout << d << '\n'; //aula15
	cout << d[3] << '\n'; //a
	d[3] = 'b';
	cout << d << '\n'; //aulb15
	d[2] = d[1] = d[0];
	cout << d << '\n'; //aaab15
	return 0;
}