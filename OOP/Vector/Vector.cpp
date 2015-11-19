#include<iostream>
#include"VECTOR.h"
using namespace std;
Vector::Vector(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}
Vector Vector::operator+(const Vector& a)
{
	Vector newVec(x + a.x, y + a.y, z + a.z);
	return newVec;
}
Vector Vector::operator-(const Vector& a)
{
	Vector newVec(x - a.x, y - a.y, z - a.z);
	return newVec;
}
Vector Vector::operator+=(const Vector& a)
{
	x = x + a.x;
	y = y + a.y;
	z = z + a.z;
	return *this;
}
Vector Vector::operator-=(const Vector& a)
{
	x = x - a.x;
	y = y - a.y;
	z = z - a.z;
	return *this;
}
Vector Vector::operator*(float a)
{
	Vector b(x*a, y*a, z*a);
	return b;
}
double Vector::operator*(const Vector& a)
{
	double sum = 0;
	sum = x*a.x + y*a.y + z*a.z;
	return sum;
}
Vector Vector::operator/(float a)
{
	Vector d(x / a, y / a, z / a);
	return d;
}
void Vector::Print()const
{
	cout << x << " " << y << " " << z << " ";
	cout << endl;
}
double Vector::operator[](int i)
{

	if (i >= 1 && i < 4)
	{

		if (i == 1)
		{
			return x;
		}
		else if (i == 2)
		{
			return y;
		}
		else if (i == 3)
		{
			return z;
		}
	}
	else
	{
		return -1;
	}

}