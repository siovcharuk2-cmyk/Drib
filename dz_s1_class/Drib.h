#pragma once

class Drib
{
private:
	int num,
		den;

	int gcd();
	void simplify();

public:
	void input();
	void setNum(int newNum);
	void setDen(int newDen);

	void print();

	void sum(Drib other);
	void minus(Drib other);
	void mult(Drib other);
	void div(Drib other);
};

