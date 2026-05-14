#include "Drib.h"
#include <iostream>

int Drib::objCount = 0;

int Drib::gcd()
{
    int a = num,
        b = den;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Drib::simplify()
{
    int a = gcd();

    num /= a;
    den /= a;

    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

void Drib::input()
{
    int n;
    std::cout << "Enter numerator: ";
    std::cin >> n;
    int d;
    std::cout << "Enter denominator: ";
    std::cin >> d;
    setNum(n);
    setDen(d);
    simplify();
}

void Drib::print()
{
    std::cout << num << '\n';

    int a;
    if (num > 0)
        (num > den) ? a = num : a = den;
    else
        (-num > den) ? a = -num : a = den;

    int count = 0;
    if (a == 0) count = 1;

    while (a > 0)
    {
        a /= 10;
        count++;
    }

    for (int i = 0; i < count; i++)
        std::cout << '-';
    std::cout << '\n';

    std::cout << den << '\n';
}


int Drib::getObjCount() { return objCount; }


// ====== Operators ======
Drib Drib::operator+(Drib other)
{
    Drib temp;
    temp.num = num * other.den + other.num * den;
    temp.den = den * other.den;
    temp.simplify();
    return temp;
}

Drib Drib::operator-(Drib other)
{
    Drib temp;
    temp.num = num * other.den - other.num * den;
    temp.den = den * other.den;
    temp.simplify();
    return temp;
}

Drib Drib::operator*(Drib other)
{
    Drib temp;
    temp.num = num * other.num;
    temp.den = den * other.den;
    temp.simplify();
    return temp;
}

Drib Drib::operator/(Drib other)
{
    Drib temp;
    temp.num = num * other.den;
    temp.den = den * other.num;
    temp.simplify();
    return temp;
}