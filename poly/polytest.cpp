#include <iostream>
#include "Poly.h"


int main()
{
	Poly P1;				//Declare object representing polynomial P1
	P1[3] = 2; P1[1] = 3.6; P1[0] = 7;	//Specify coefficients of P1 = 2x^3 + 3.6x + 7

	Poly P2 = 5;				//Declare object representing polynomial P2 = 5
	P2[1] = 3; P2[2] = 6; P2[4] = 1;	//Specify additional coefficients of P2 = x^4 + 6x^2 + 3x + 5

	std::cout << "Polynomial P1: " << P1 << std::endl;	//Print P1 	
	std::cout << "Polynomial P2: " << P2 << std::endl;	//Print P2

	Poly P3 = P1 + P2;						//Add P1 and P2 	
	std::cout << "Sum of polynomials P1 and P2: " << P3 << std::endl;	//Print sum of P1 and P2

	P3 = P1 * P2;							//Multiply P1 by P2 	
	std::cout << "Product of polynomials P1 and P2: " << P3 << std::endl;	//Print product of P1 and P2

	P3 = 2 * P1;							//Multiply P1 by 2 	
	std::cout << "Polynomial P1 multiplied by 2: " << P3 << std::endl;	//Print product of P1 and 2

	double val = P1(3.14);						//Calculate the value of P1 at point 3.14
	std::cout << "Value of polynomial P1 at point 3.14: " << val << std::endl;	//Print the value of P1 at point 3.14

	Poly P4; P4[0] = -1; P4[1] = 1;
	Poly P5; P5[0] = 1; P5[1] = 1;
	Poly P6 = P4 * P5;							//Multiply P1 by P2 
	std::cout << "Polynomial P4: " << P4 << std::endl;	//Print P1 	
	std::cout << "Polynomial P5: " << P5 << std::endl;	//Print P2
	std::cout << "Product of polynomials P4 and P5: " << P6 << std::endl;
};
