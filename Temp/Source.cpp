#include <string.h>
#include <iostream>

using namespace std;

#include "4_stack.h"

size_t CLimitedStack::SizeLimit = 40;

int main()
{
    CContainer* pStack = new CLimitedStack();

    if (pStack->getSizeLimit() != 40)
    {
        cerr << "Result 1 is wrong" << endl;
        return -1;
    }

    // Do tego miejsca: na 60%
#if defined(FOR_80) || defined(FOR_100)

    for (int i = 0; i < 6; ++i)
        pStack->push(i);

    for (int i = 0; i < 6; ++i)
    {
        int a = pStack->pop();
        cout << a << ' ';

        if (a != 5 - i)
        {
            cerr << "Result " << 2 + i << " is wrong" << endl;
            return -1;
        }
    }
    cout << endl;                                                       // Prints "5 4 3 2 1 0 "

    // Do tego miejsca: na 80%
#if defined(FOR_100)

    const size_t NewSizeLimit = 4;
    CLimitedStack::setSizeLimit(NewSizeLimit);

    for (int i = 0; ; ++i)
        if (!pStack->push(i))
            break;

    for (unsigned i = 0; i < NewSizeLimit; ++i)
    {
        int a = pStack->pop();
        cout << a << ' ';

        if ((unsigned)a != NewSizeLimit - i - 1)
        {
            cerr << "Result " << 8 + i << " is wrong" << endl;
            return -1;
        }
    }
    cout << endl;                                                       // Prints "3 2 1 0"

    // Do tego miejsca: na 100%
#endif /*defined(FOR_100)*/
#endif /*defined(FOR_80) || defined(FOR_100)*/

    delete pStack;

    return 0;
}