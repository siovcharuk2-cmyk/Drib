#include "Drib.h"
#include <iostream>

int Drib::gcd()
{
    int a = num,
        b = den;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0)
    {
        a %= b;

        int temp = a;
        a = b;
        b = temp;
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

void Drib::setNum(int newNum) { num = newNum; }
void Drib::setDen(int newDen) { newDen == 0 ? den = 1 : den = newDen; }

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

void Drib::sum(Drib other)
{
    num = num * other.den + other.num * den;
    den = den * other.den;
    simplify();
}

void Drib::minus(Drib other)
{
    num = num * other.den - other.num * den;
    den = den * other.den;
    simplify();
}

void Drib::mult(Drib other)
{
    num = num * other.num;
    den = den * other.den;
    simplify();
}

void Drib::div(Drib other)
{
    num = num * other.den;
    den = den * other.num;
    simplify();
}