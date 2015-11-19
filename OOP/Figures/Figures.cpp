#include <iostream>
#include <math.h>
using namespace std;

class Figure
{
protected:
	double x, y;
public:
	virtual void read() = 0;
	virtual double surface() = 0;
	virtual double perimeter() = 0;
	virtual void print()const = 0;
};

class Rectangle : public Figure
{
private:
	double a, b;
public:
	Rectangle(double _x=0, double _y=0, double _a=0, double _b=0) :a(_a), b(_b)
	{
		x = _x;
		y = _y;
	}
	double surface()
	{
		return a*b;
	}
	double perimeter()
	{
		return 2 * (a + b);
	}
	void read()
	{
		cout << "Enter sideA: ";
		cin >> a;
		cout << "Enter sideB: ";
		cin >> b;
	}
	void print()const
	{
		cout << "Rectangle:" << endl << "sideA: " << a << " sideB: " << endl;
	}
};

class Triangle : public Figure
{
private:
	double a, b, c;
public:
	Triangle(double _x=0, double _y=0, double _a=0, double _b=0, double _c=0) :a(_a), b(_b), c(_c)
	{
		x = _x;
		y = _y;
	}

	double surface()
	{


		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	void read()
	{
		cout << "Enter A: ";
		cin >> a;
		cout << "Enter B: ";
		cin >> b;
		cout << "Enter C: ";
		cin >> c;
	}
	double perimeter()
	{
		return a + b + c;
	}
	void print()const
	{
		cout << "Triangle: " << endl << "sideA: " << a << " sideB: " << b << " sideC: " << c << endl;
	}
};

class Circle : public Figure
{
private:
	double r;
public:

	Circle(double _x=0, double _y=0, double _r=0) :r(_r)
	{
		x = _x;
		y = _y;

	}

	void read()
	{
		cout << "Enter radius: ";
		cin >> r;
	}
	double surface()
	{
		return 3.14*r*r;
	}
	double perimeter()
	{
		return 2 * 3.14*r;
	}
	void print()const
	{
		cout << "Circle: " << endl << " Radius: " << r << endl;
	}
};


double sumSurfaces(Figure& f1, Figure& f2)
{
	return f1.surface() + f2.surface();
}

void readFigures(Figure* figs[10])
{
	char choice;
	cout << "Enter 'r'-Rectangle 't'-Triangle 'c'-Circle "<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " element :";
		cin >> choice;
			switch (choice)
		{
			case 'r':figs[i] = new Rectangle;
				figs[i]->read(); break;
			case 't':figs[i] = new Triangle;
				figs[i]->read(); break;
			case 'c':figs[i] = new Circle;
				figs[i]->read(); break;
			default:cout << "Enter r t or c !!!" << endl;
				exit(1);
		}
	}
	double sum = 0;
	for (int i = 0;i < 10; i++)
	{
		sum = sum + figs[i]->surface();
	}
	cout << "Sum of surfaces of figures is " << sum << endl;
}
int main()
{

	Figure* figs[10];
	readFigures(figs);
	for (int i = 0; i < 10; i++)
	{
		figs[i]->print();
		cout << endl;
	}
	return 0;
}