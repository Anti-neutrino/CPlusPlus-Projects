#ifndef VECTOR_HH
#define VECTOR

class Vector
{
	double x;
	double y;
	double z;
public:
	Vector(double, double, double);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator+=(const Vector&);
	Vector operator-=(const Vector&);
	Vector operator*(float);
	double operator*(const Vector&);
	Vector operator/(float);
	double operator[](int);
	void Print()const;
};

#endif