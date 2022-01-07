#pragma
#ifndef COMPLEX_H
#define COMPLEX_X


#include <cmath>
#include <complex>
#include <iostream>

class Complex
{
public:
    Complex(double Real=0.0, double Imag=0.0);
    //Complex(const Complex& cmp) = default;

    Complex& operator= (const Complex& cmp);
    Complex& operator= (double value);

    bool operator==(const Complex& cmp) const;
    bool operator!=(const Complex& cmp) const;

    Complex operator+ (const Complex& cmp) const;
    Complex& operator+= (const Complex& cmp);
    Complex operator+ (double value) const;
    Complex& operator+= (double value);

    Complex operator- (const Complex& cmp) const;
    Complex& operator-= (const Complex& cmp);
    Complex operator- (double value) const;
    Complex& operator-= (double value);

    Complex operator/ (const Complex& cmp) const;
    Complex& operator/= (const Complex& cmp);
    Complex operator/ (double value) const;
    Complex& operator/= (double value);

    double abs() const;
    double arg() const;
    Complex conj() const;
    
    friend std::ostream& operator<< (std::ostream& ostr, const Complex& cmp);
    
     friend Complex operator+ (double value, const Complex& cmp);
     friend Complex operator- (double value, const Complex& cmp);
     friend Complex operator/ (double value, const Complex& cmp);

private:
    double m_Real, m_Imag;

    double sum_sqr() const;
};

std::ostream& operator<< (std::ostream& ostr, const Complex& cmp);

Complex operator+ (double value, const Complex& cmp);
Complex operator- (double value, const Complex& cmp);
Complex operator/ (double value, const Complex& cmp);

#endif // !COMPLEX_H