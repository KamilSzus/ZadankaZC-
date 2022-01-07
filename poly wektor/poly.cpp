#include "Poly.h"
#include <iomanip>
#include <cmath>
Poly::Poly()
	: Poly(0)
{ }

Poly::Poly(double value)
{
	m_polynomi.push_back(value);
}

Poly::Poly(const Poly& src)
{
	m_polynomi = src.m_polynomi;
}

Poly::~Poly()
{
}

double& Poly::operator[](size_t index)
{
	if (index >= m_polynomi.size())
	{
		m_polynomi.resize(index+1);
	}
	return m_polynomi[index];
}

double Poly::operator[](size_t index) const
{
	return m_polynomi[index];
}

double Poly::operator()(double x) const
{
	double result = 0.0;
	for (size_t i = 0; i < m_polynomi.size(); i++)
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

	m_polynomi = src.m_polynomi;

	return *this;
}

Poly Poly::operator+(const Poly& src) const
{
	Poly result;
	for (size_t i = 0; i < m_polynomi.size(); i++)
	{
		result[i] = (*this)[i];
	}
	for (size_t i = 0; i < src.m_polynomi.size(); i++)
	{
		result[i] += src[i];
	}
	return result;
}

Poly Poly::operator*(const Poly& src) const
{
	Poly result;
	for (int i = m_polynomi.size() -1; i >= 0; --i)
	{ 
		for (int j = src.m_polynomi.size() - 1; j >= 0; --j)
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
	for (int i = src.m_polynomi.size() -1; i >= 0 ; i--)
	{
		if (std::fabs(src[i]) > 1E-5)
		{
			if (src[i] > 0&&i!= src.m_polynomi.size() - 1)
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
