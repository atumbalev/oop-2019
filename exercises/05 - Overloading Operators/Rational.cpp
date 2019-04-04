#include <iostream>
#include <cassert>

namespace FMIMath
{
int gcd(int a, int b)
{
    while (a && b)
    {
        std::swap(a, b);
        b %= a;
    }

    return a ? a : b;
}

class Rational
{
 public:
    explicit Rational(int _nom = 0, int _denom = 1);

    operator bool() const;
    operator double() const;

    Rational operator++(int);
    Rational& operator++();
    Rational& operator+=(const Rational& other);
    Rational& operator+=(int other);

    // These don't really make sense in the context of rational numbers, but we are using them as example
    // This normally returns a reference, but that will break encapsulation and in turn the invariant
    int operator[](unsigned index);
    const int& operator[](unsigned index) const;

    friend std::istream& operator>>(std::istream& in, Rational& rat);
 private:
    int nom;
    int denom;

    void normalize();
};

void Rational::normalize()
{
    assert(denom);
    int divisor = gcd(nom, denom);
    nom /= divisor;
    denom /= divisor;
}

Rational::Rational(int _nom, int _denom):
    nom(_nom),
    denom(_denom)
{
    normalize();
}

std::ostream& operator<<(std::ostream& out, const Rational& rational)
{
    return out << rational[0] << "/" << rational[1];
}

std::istream& operator>>(std::istream& in, Rational& rational)
{
    in >> rational.nom >> rational.denom;
    rational.normalize();

    return in;
}

const int& Rational::operator[](unsigned index) const
{
    assert(index == 0 || index == 1);
    switch (index)
    {
        case 0:
            return nom;
        case 1:
            return denom;
    }
}

int Rational::operator[](unsigned index)
{
    assert(index == 0 || index == 1);
    switch (index)
    {
        case 0:
            return nom;
        case 1:
            return denom;
    }
}

Rational::operator bool() const
{
    return nom;
}

Rational::operator double() const
{
    return static_cast<double>(nom) / denom;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs[0] * rhs[1] + rhs[0] * lhs[1], lhs[1] * rhs[1]);
}

Rational operator+(int lhs, const Rational& rhs)
{
    return Rational(lhs) + rhs;
}

Rational operator+(const Rational& lhs, int rhs)
{
    return rhs + lhs;
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
    return lhs[0] * rhs[1] == lhs[1] * rhs[0];
}

bool operator!=(const Rational& lhs, const Rational& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
    return lhs[0] * rhs[1] < lhs[1] * rhs[0];
}

bool operator<=(const Rational& lhs, const Rational& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>(const Rational& lhs, const Rational& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs)
{
    return !(lhs < rhs);
}

Rational& Rational::operator+=(const Rational& other)
{
    return *this = *this + other;
}

Rational& Rational::operator+=(int other)
{
    return *this = *this + other;
}

Rational& Rational::operator++()
{
    return *this += 1;
}

Rational Rational::operator++(Rational)
{
    Rational tmp = *this;
    ++*this;
    return tmp;
}
}  // namespace FMIMath
int main()
{
    FMIMath::Rational x;
    FMIMath::Rational y(8, 6);

    std::cout << x << " " << y << std::endl;

    std::cout << std::boolalpha << static_cast<bool>(x)   << " " << static_cast<bool>(y)   << std::endl;
    std::cout <<                   static_cast<int>(x)    << " " << static_cast<int>(y)    << std::endl;
    std::cout <<                   static_cast<double>(x) << " " << static_cast<double>(y) << std::endl;

    std::cout << y + y << std::endl;
    std::cout << y + 1 << std::endl;
    std::cout << 1 + y << std::endl;

    std::cout << std::boolalpha << (x == y) << " " << (x != y) << " " << (x < y) << " " << (y < x) << std::endl;

    std::cout << x++ << std::endl;
    std::cout << ++x << std::endl;
    std::cout << (x += 10) << std::endl;

    std::cout << (x += x) << std::endl;
    return 0;
}
