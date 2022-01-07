#pragma once
#include <string.h>

class EmptyStack {};

class CElement
{
private :
    int value;

public:
    void setValue(const int value);
    int getValue();
};

class CStack
{
private:
    CElement* pData;
    unsigned int top;//wskazuje 1 wolny element
    unsigned int size;//wskazuje rozmiar

public:
    void push(int a);
    ~CStack() {
        delete[] pData;
    }
    int pop()
    {
        this->top--;
        //return pData[top].value; gdyby value bylo public
        return pData[top].getValue();
    };
    CStack() :
        pData(nullptr)
        , top(0)
        , size(0)
    {};

    //CStack(const CStack& stack) = default;//mo¿na poprosiæ kompilator aby utworzy³ za nas konstruktor kopiujacy

    //CStack(const CStack& stack) ://shall copy
    //    pData(stack.pData)
    //    , top(stack.top)
    //    , size(stack.size)
    //{};//https://www.geeksforgeeks.org/copy-constructor-in-cpp/

    CStack(const CStack& stack) :
        top(stack.top)
        , size(stack.size)
    {
        CElement* temp = new CElement[(size)];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = stack.pData[i];
        }
        pData = temp;
    };

    CStack& operator= (const CStack& cmp);

};