#include "3_stack_1.h"

void CElement::setValue(const int value)
{
	this->value = value;
}

int CElement::getValue()
{
	return value;
}

CStack& CStack::operator=(const CStack& cmp)
{
	if (&cmp == this)
	{
		return *this;
	}
	top = cmp.top;
	size = cmp.size;

	this->pData = new CElement[size];
	for (int i = 0; i < size; i++) {
		this->pData[i].setValue(cmp.pData[i].getValue());
	}

	return *this;
}


void CStack::push(int a)
{
	if (top == 0 && size == 0)
	{
		CElement* temp = (CElement*)new CElement[1];
		size = 1;
		pData = temp;
	}
	else if (top == size)
	{
		CElement* temp = new CElement[2 * (size)];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = pData[i];
		}
		size *= 2;
		delete[] pData;
		pData = temp;
	}

	//pData[this->top].value = a; gdyby value bylo public
	pData[this->top].setValue(a);
	top++;
}
