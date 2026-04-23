#pragma once

class Drib
{
private:
	int num,
		den;

	int gcd();
	void simplify();

public:
	Drib()
	{
		num = 0;
		den = 1;
	}

	Drib(int newNum, int newDen)
	{
		num = newNum;
		den = newDen;
	}

	void input();
	void setNum(int newNum) { num = newNum; }
	void setDen(int newDen) { newDen == 0 ? den = 1 : den = newDen; }

	void print();

	void sum(Drib other);
	void minus(Drib other);
	void mult(Drib other);
	void div(Drib other);
};