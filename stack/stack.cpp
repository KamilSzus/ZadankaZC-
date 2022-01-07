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
	printf("D-tor\n");
	delete[] m_data;
}

stack::stack(const stack& src)
{
	this->m_top = src.m_top;
	this->m_size = src.m_size;
	//this->m_data = src.m_data;
	this->m_data = new int[ m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		this->m_data[i] = src.m_data[i];
	}
}

stack& stack::operator=(const stack& src)
{
	// if(src == *this)
	if(&src==this)
	{
		return *this;
	}

	this->m_top = src.m_top;
	this->m_size = src.m_size;
	//this->m_data = src.m_data;
	
	delete[] m_data;
	this->m_data = new int[m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		this->m_data[i] = src.m_data[i];
	}
	
	return *this;
}

bool stack::operator==(const stack& src) const
{
	if (this->m_top != src.m_top)
	{
		return false;
	}
	if (this->m_size != src.m_size)
	{
		return false;
	}
	for (size_t i = 0; i < m_size; i++)
	{
		if (this->m_data[i] != src.m_data[i])
		{
			return false;
		}
	}

	return true;
}

bool stack::operator!=(const stack& src) const
{
	//return !(*this == src);
	return !(this->operator==(src));
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
	if (m_top == m_size)
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
