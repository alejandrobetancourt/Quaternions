#include <cassert>;
#include "Quaternion.h";

Quaternion::Quaternion() : mReal(0.0), mI(0.0), mJ(0.0), mK(0.0) {}


Quaternion::Quaternion(double a, double b, double c, double d) :
	mReal(a), mI(b), mJ(c), mK(d)
{}


void Quaternion::setReal(double a)
{
	mReal = a;
}


void Quaternion::setI(double a)
{
	mI = a;
}


void Quaternion::setJ(double a)
{
	mJ = a;
}


void Quaternion::setK(double a)
{
	mK = a;
}


bool Quaternion::not_zero() const
{
	//Returns true if the quaternion is not zero and false otherwise.
	bool test = (modulus() > 1.0e-8);
	return test;
}


double Quaternion::modulus() const
{
	double square_mod = mReal * mReal + mI * mI + mJ * mJ + mK * mK;
	return sqrt(square_mod);
}


Quaternion Quaternion::conjugate() const
{
	Quaternion q(mReal, -mI, -mJ, -mK);
	return q;
}


Quaternion Quaternion::inverse() const
{
	//Returns the multiplicative inverse of a (non-zero) quaternion.
	assert(not_zero());
	double mod = 1 / (modulus() * modulus());
	Quaternion q = conjugate();
	return q * mod;
}


Quaternion Quaternion::operator-() const
{
	Quaternion q(-mReal, -mI, -mJ, -mK);
	return q;
}


Quaternion Quaternion::operator*(double a) const
{
	double result_mReal = a * mReal;
	double result_mI = a * mI;
	double result_mJ = a * mJ;
	double result_mK = a * mK;
	Quaternion q(result_mReal, result_mI, result_mJ, result_mK);
	return q;
}


Quaternion Quaternion::operator+(const Quaternion& w) const
{
	Quaternion p;
	p.mReal = mReal + w.mReal;
	p.mI = mI + w.mI;
	p.mJ = mJ + w.mJ;
	p.mK = mK + w.mK;
	return p;
}


Quaternion Quaternion::operator-(const Quaternion& w) const
{
	Quaternion p;
	p.mReal = mReal - w.mReal;
	p.mI = mI - w.mI;
	p.mJ = mJ - w.mJ;
	p.mK = mK - w.mJ;
	return p;
}


Quaternion Quaternion::operator*(const Quaternion& w) const
{
	Quaternion p;
	p.mReal = mReal * w.mReal - mI * w.mI - mJ * w.mJ - mK * w.mK;
	p.mI = mReal * w.mI + mI * w.mReal + mJ * w.mK - mK * w.mJ;
	p.mJ = mReal * w.mJ - mI * w.mK + mJ * w.mReal + mK * w.mI;
	p.mK = mReal * w.mK + mI * w.mJ - mJ * w.mI + mK * w.mReal;
	return p;
}


Quaternion Quaternion::operator/(const Quaternion& w) const
{
	assert(w.not_zero());
	return (*this) * w.inverse();
}


Quaternion Quaternion::conjugate_by(const Quaternion& w) const
{
	/* For quaternions p, q the function p.conjugate_by(q)
	returns the quaternion q*p*q.inverse() */
	assert(w.not_zero());
	return w * (*this) * w.inverse();
}


void Print(const Quaternion& q)
{
	std::cout << "(" << q.mReal << ", " << q.mI <<
		", " << q.mJ << ", " << q.mK << ")" << std::endl;
}