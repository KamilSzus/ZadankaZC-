#include <iostream>

using namespace std;

#include "Header.h"

int main()
{
    CCar car1(50);

    cout << car1.getPowerOfEngine() << endl;                                   // Prints: 50
    if (car1.getPowerOfEngine() != 50)
    {
        cerr << "Result 1 is wrong" << endl;
        return -1;
    }

    car1.increasePowerOfEngine(10);

    cout << car1.getPowerOfEngine() << endl;                                   // Prints: 60
    if (car1.getPowerOfEngine() != 60)
    {
        cerr << "Result 2 is wrong" << endl;
        return -1;
    }

    // Do tego miejsca: na 60%
#if defined(FOR_80) || defined(FOR_100)

    CCar car2(car1);
    if (car2.getPowerOfEngine() != 60)
    {
        cerr << "Result 3 is wrong" << endl;
        return -1;
    }

    car2.increasePowerOfEngine(20);

    cout << car1.getPowerOfEngine() << endl;                                   // Prints: 60
    cout << car2.getPowerOfEngine() << endl;                                   // Prints: 80
    if (car1.getPowerOfEngine() != 60 || car2.getPowerOfEngine() != 80)
    {
        cerr << "Result 4 is wrong" << endl;
        return -1;
    }

    // Do tego miejsca: na 80%
#if defined(FOR_100)

    CCar car3(100);
    (car3 = car1) = car2;

    cout << car1.getPowerOfEngine() << endl;                                   // Prints: 60
    cout << car2.getPowerOfEngine() << endl;                                   // Prints: 80
    cout << car3.getPowerOfEngine() << endl;                                   // Prints: 80

    if (car2.getPowerOfEngine() != 80 || car3.getPowerOfEngine() != 80)
    {
        cerr << "Result 5 is wrong" << endl;
        return -1;
    }

    // Do tego miejsca: na 100%
#endif /*defined(FOR_100)*/
#endif /*defined(FOR_80) || defined(FOR_100)*/

    return 0;
}

