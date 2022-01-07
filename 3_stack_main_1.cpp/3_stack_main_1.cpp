#include <iostream>

using namespace std;

#include "3_stack_1.h"

int main()
{
    int a, b;
    CStack stack1;

    stack1.push(1);
    stack1.push(2);

    a = stack1.pop();
    b = stack1.pop();

    cout << a << ' ' << b << endl;                                      // Prints: "2 1"
    if (a != 2 || b != 1)
    {
        cerr << "Result 1 is wrong" << endl;
        return -1;
    }


    stack1.push(1);
    stack1.push(2);

    CStack stack2(stack1); //konstruktor kopiujacy 

    a = stack1.pop();
    b = stack2.pop();

    cout << a << ' ' << b << endl;                                      // Prints: "2 2"
    if (a != 2 || b != 2)
    {
        cerr << "Result 2 is wrong" << endl;
        return -1;
    }

    stack2.push(3);

    a = stack1.pop();
    b = stack2.pop();

    cout << a << ' ' << b << endl;                                      // Prints: "1 3"
    if (a != 1 || b != 3)
    {
        cerr << "Result 3 is wrong" << endl;
        return -1;
    }

    // Do tego miejsca: na 80%

    stack1.push(1);
    stack1.push(2);

    stack2.push(3);
    stack2.push(4);

    CStack stack3;
    (stack3 = stack1) = stack2;

    a = stack1.pop();
    b = stack2.pop();
    int c = stack3.pop();

    cout << a << ' ' << b << ' ' << c << endl;                          // Prints: "2 4 4"
    if (a != 2 || b != 4 || c != 4)
    {
        cerr << "Result 2 is wrong" << endl;
        return -1;
    }

    // Do tego miejsca: na 100%

    return 0;
}
