#pragma once

class Drib
{
private:
	static int objCount;

	int num,
		den;

	int gcd();
	void simplify();

public:
	Drib(int newNum, int newDen)
		: num{ newNum },
		den{ newDen }
	{
		objCount++;
	}

	Drib() : Drib{ 0, 1 } {}

	void input();
	void setNum(int newNum) { num = newNum; }
	void setDen(int newDen) { newDen == 0 ? den = 1 : den = newDen; }

	void print();

	static int getObjCount();


	// operators
	Drib operator+(Drib other);
	Drib operator-(Drib other);
	Drib operator*(Drib other);
	Drib operator/(Drib other);
};