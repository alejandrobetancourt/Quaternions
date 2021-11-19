#pragma once

#include <iostream>;

class Quaternion
{
	/* We provide a class to carry out computations with quaterions of 
	the form q = a + bI + cJ + dK, where a, b, c, and d are real numbers
	and I,J, K satisfy the usual relations I^2 = J^2 = K^2= IJK = -1. */
private:
	double mReal, mI, mJ, mK;
public:
	Quaternion(); //initializes to zero by default
	Quaternion(double, double, double, double);
	void setReal(double);
	void setI(double);
	void setJ(double);
	void setK(double);
	bool not_zero() const;
	double modulus() const;
	Quaternion conjugate() const;
	Quaternion inverse() const;
	Quaternion operator-() const;
	Quaternion operator*(double) const;
	Quaternion operator+(const Quaternion&) const;
	Quaternion operator-(const Quaternion&) const;
	Quaternion operator*(const Quaternion&) const;
	Quaternion operator/(const Quaternion&) const;
	Quaternion conjugate_by(const Quaternion&) const;
	friend void Print(const Quaternion&);
 };

void Print(const Quaternion&);