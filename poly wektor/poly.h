#ifndef __POLY_H__
#define __POLY_H__
#include <iostream>
#include <vector>

class Poly
{
public:
    Poly();
    Poly(double value);
    Poly(const Poly& src);
    ~Poly();

    double& operator[](size_t index);
    double operator[](size_t index) const;
    double operator()(double x) const;
    Poly& operator=(const Poly& src);
    Poly operator+(const Poly& src) const;
    Poly operator*(const Poly& src) const;

    friend std::ostream& operator<< (std::ostream& ostr, const Poly& src);
private:
    std::vector<double> m_polynomi;
    double my_pow(double number, size_t index) const;
};
std::ostream& operator<< (std::ostream& ostr, const Poly& src);

Poly operator*(double value, const Poly& src);

#endif
