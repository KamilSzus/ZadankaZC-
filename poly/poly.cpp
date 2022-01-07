#include "Poly.h"
#include <iomanip>
#include <cmath>
Poly::Poly()
	: Poly(0)
{ }

Poly::Poly(double value)
	:m_polynomi_koko{ 1 }
{
	m_polynomi = new double[m_polynomi_koko];
	m_polynomi[0] = value;
}

Poly::Poly(const Poly& src)
{
	m_polynomi_koko = src.m_polynomi_koko;
	this->m_polynomi = new double[m_polynomi_koko];
	for (size_t i = 0; i < m_polynomi_koko; i++)
	{
		this->m_polynomi[i] = src.m_polynomi[i];
	}
}

Poly::~Poly()
{
	delete[] m_polynomi;
}

double& Poly::operator[](size_t index)
{
	if (index >= m_polynomi_koko)
	{
		double* new_polynomi = new double[index+1];
		for (size_t i = 0; i < m_polynomi_koko; i++)
		{
			new_polynomi[i] = m_polynomi[i];
		}
		for (size_t i = m_polynomi_koko; i <= index; i++)
		{
			new_polynomi[i] = 0.0;
		}
		delete[] m_polynomi;
		m_polynomi = new_polynomi;
		m_polynomi_koko = index+1;
	}
	return *(m_polynomi+index);
}

double Poly::operator[](size_t index) const
{
	return *(m_polynomi + index);
}

double Poly::operator()(double x) const
{
	double result = 0.0;
	for (size_t i = 0; i < m_polynomi_koko; i++)
	{
		if (m_polynomi[i] != 0)
		{
			result += m_polynomi[i] * my_pow(x, i);
		}
	}
	return result;
}

Poly& Poly::operator=(const Poly& src)
{

	if (&src == this)
	{
		return *this;
	}

	this->m_polynomi_koko = src.m_polynomi_koko;

	delete[] this->m_polynomi;
	this->m_polynomi = new double[m_polynomi_koko];
	for (size_t i = 0; i < m_polynomi_koko; i++)
	{
		this->m_polynomi[i] = src.m_polynomi[i];
	}

	return *this;
}

Poly Poly::operator+(const Poly& src) const
{
	Poly result;
	for (size_t i = 0; i < m_polynomi_koko; i++)
	{
		result[i] = (*this)[i];
	}
	for (size_t i = 0; i < src.m_polynomi_koko; i++)
	{
		result[i] += src[i];
	}
	return result;
}

Poly Poly::operator*(const Poly& src) const
{
	Poly result;
	for (int i = m_polynomi_koko-1; i >= 0; --i)
	{ 
		for (int j = src.m_polynomi_koko - 1; j >= 0; --j)
		{
			result[i + j] += m_polynomi[i] * src.m_polynomi[j];
		}
		
	}
	return result;
}

double Poly::my_pow(double number, size_t pow) const
{
	if (pow == 0)
	{
		return 1;
	}
	double result = 1.0;
	for (size_t i = 1; i <= pow; i++)
	{
		result *= number;
	}
	return result;
}

std::ostream& operator<<(std::ostream& ostr, const Poly& src)
{
	ostr << std::fixed << std::setprecision(2);
	for (int i = src.m_polynomi_koko-1; i >= 0 ; i--)
	{
		if (std::fabs(src[i]) > 1E-5)
		{
			if (src[i] > 0&&i!= src.m_polynomi_koko - 1)
			{
				ostr << " + ";
			}
			ostr << src[i];
			if (i == 1)
			{
				ostr << "*x";
			}
			else if(i != 0 )
			{
				ostr<< "*x^" << i;
			}			
		}
	}
	return ostr;
}

Poly operator*(double value, const Poly& src)
{
	return Poly{ value } * src;
}
