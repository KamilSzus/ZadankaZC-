#include <cassert>
#include <cstdlib>
#include <cstdio>
#include "stack.h"

stack::stack()
{
	m_top = 0;
	allocation(1);
}

stack::~stack()
{
	delete[] m_data;
}
void stack::allocation(size_t count)
{
	m_size = count;
	m_data = new int[m_size];
}

void stack::clear()
{
	this->m_top = 0;
}

void stack::push(int a)
{
	if (m_top == (int)m_size)
	{
		int* temp = new int[2 * m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		m_size *= 2;
		delete[] m_data;
		m_data = temp;
	}
	//assert(this->m_top < STACKSIZE);
	this->m_data[this->m_top++] = a;
}

int stack::pop()
{
	assert(this->m_top > 0);
	return this->m_data[--this->m_top];
}
