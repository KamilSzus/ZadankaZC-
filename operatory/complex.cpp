#include "complex.h"

Complex::Complex(double Real, double Imag)
    :m_Real(Real),m_Imag(Imag)
{
};

Complex& Complex::operator= (const Complex& cmp)
{
    if (&cmp == this)
    {
        return *this;
    }
    m_Real = cmp.m_Real;
    m_Imag = cmp.m_Imag;
    return *this;
};

Complex& Complex::operator= (double value)
{
    m_Real = value;
    m_Imag = 0.0;
    return *this;
};

bool Complex::operator==(const Complex& cmp) const
{
    if (this->m_Real != cmp.m_Real)
    {
        return false;
    }
    if (this->m_Imag != cmp.m_Imag)
    {
        return false;
    }

    return true;
}

bool Complex::operator!=(const Complex& cmp) const
{
    //return !(*this == cmp);
    return !(this->operator==(cmp));
}

Complex Complex::operator+ (const Complex& cmp) const
{
    //Complex result;
    //result.m_Real = this->m_Real + cmp.m_Real;
    //result.m_Imag = this->m_Imag + cmp.m_Imag;
    //return result;

    //Complex result(this->m_Real + cmp.m_Real, this->m_Imag + cmp.m_Imag);
    //return result;

    return { this->m_Real + cmp.m_Real, this->m_Imag + cmp.m_Imag };
}

Complex& Complex::operator+=(const Complex& cmp)
{
    this->m_Real += cmp.m_Real;
    this->m_Imag += cmp.m_Imag;
    return *this;
}

Complex Complex::operator+(double value) const
{
    return { this->m_Real + value,this->m_Imag};
}

Complex& Complex::operator+=(double value)
{
    this->m_Real += value;
    return *this;
}

Complex Complex::operator- (const Complex& cmp) const
{
    //Complex result;
    //result.m_Real = this->m_Real - cmp.m_Real;
    //result.m_Imag = this->m_Imag - cmp.m_Imag;
    //return result;

    //Complex result(this->m_Real - cmp.m_Real, this->m_Imag - cmp.m_Imag);
    //return result;

    return { this->m_Real - cmp.m_Real, this->m_Imag - cmp.m_Imag };
}

Complex& Complex::operator-=(const Complex& cmp)
{
    this->m_Real -= cmp.m_Real;
    this->m_Imag -= cmp.m_Imag;
    return *this;
}

Complex Complex::operator-(double value) const
{
    return { this->m_Real - value,this->m_Imag };
}

Complex& Complex::operator-=(double value)
{
    this->m_Real -= value;
    return *this;
}

Complex Complex::operator/ (const Complex& cmp) const
{
    double re = m_Real * cmp.m_Real + m_Imag * cmp.m_Imag;
    double im = m_Imag * cmp.m_Real - m_Real * cmp.m_Imag;
    double cmp_abs = cmp.sum_sqr();
    return { re/cmp_abs,im/cmp_abs};
}

Complex& Complex::operator/=(const Complex& cmp)
{
    double re = m_Real * cmp.m_Real + m_Imag * cmp.m_Imag;
    double im = m_Imag * cmp.m_Real - m_Real * cmp.m_Imag;
    double cmp_abs = cmp.sum_sqr();
    m_Real = re / cmp_abs;
    m_Imag = im / cmp_abs;
    return *this;
}

Complex Complex::operator/(double value) const
{
    return { this->m_Real / value,this->m_Imag / value};
}

Complex& Complex::operator/=(double value)
{
    this->m_Real /= value;
    this->m_Imag /= value;
    return *this;
}

double Complex::abs() const
{
    return std::sqrt(sum_sqr());
}

double Complex::arg() const
{
    return std::atan2(m_Imag,m_Real);
}

Complex Complex::conj() const
{
    return { m_Real,-m_Imag };
}

double Complex::sum_sqr() const
{
    return m_Real * m_Real + m_Imag * m_Imag;
}

std::ostream& operator<< (std::ostream& ostr, const Complex& cmp)
{
   // ostr << "(" << cmp.m_Real << "i" << cmp.m_Imag << ")";
    ostr << cmp.m_Real << '+' << cmp.m_Imag << 'i';// << "\n";
    return ostr;
}

Complex operator+(double value, const Complex& cmp)
{
     return { value + cmp.m_Real ,cmp.m_Imag };
}

Complex operator-(double value, const Complex& cmp)
{
   return { value - cmp.m_Real,-cmp.m_Imag };
}

Complex operator/(double value, const Complex& cmp)
{
    return Complex(value)/cmp;
}