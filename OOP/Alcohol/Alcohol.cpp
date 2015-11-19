#include<iostream>
#include"Alcohol.h";
using namespace std;

AlcoholicDrink::AlcoholicDrink(char* name1, double value, float abv1)
{
	strcpy_s(name, name1);
	price = value;
	abv = abv1;
}
AlcoholicDrink::AlcoholicDrink(){};
const char* AlcoholicDrink::getName()const
{
	return name;
}
double AlcoholicDrink::getPrice()const
{
	return price;
}
float AlcoholicDrink::getAbv()const
{
	return abv;
}
void AlcoholicDrink::setName(char* a)
{
	strcpy_s(name,a);
}
void AlcoholicDrink::setPrice(double pr)
{
	price = pr;
}
void AlcoholicDrink::setAbv(float b)
{
	abv = b;
}
void AlcoholicDrink::Print()
{
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Percentage of alcohol: " << abv << endl;
	cout << "\n";
}
double AlcoholicDrink::waterToLowerPercentage(double wantedPercentage, double litersOfAlcohol)
{
	if (wantedPercentage > abv)
	{
		return 0;
	}
	else
	{
		return litersOfAlcohol - ((wantedPercentage*litersOfAlcohol) / abv);
	}
}
AlcoholicDrink iWannaGetDrunk(AlcoholicDrink* arr, int n)
{
	AlcoholicDrink drink = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (drink.getAbv() < arr[i].getAbv())
		{
			drink = arr[i];
		}
	}
	return drink;
}
AlcoholicDrink iWannaGetDrunkAndIAmAPoorFMIStudent(AlcoholicDrink* arr, int n)
{
	AlcoholicDrink drink = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (drink.getAbv() / drink.getPrice() < arr[i].getAbv() / arr[i].getPrice())
		{
			drink = arr[i];
		}
	}
	return drink;
}
int main()
{
	
	AlcoholicDrink arr[20];
	cout << "Enter n: ";
	int n;
	cin >> n;
	cin.sync();
	for (int i = 0; i < n; i++)
	{
		cin.sync();
		cout << "Name: ";
		char name[32];
		cin.getline(name, 32);
		arr[i].setName(name);
		cout << "Price: ";
		double pr;
		cin >> pr;
		arr[i].setPrice(pr);
		cout << "Alcohol percentage: ";
		float ab;
		cin >> ab;
		arr[i].setAbv(ab);
	}
	for (int i = 0; i < n; i++)
	{
         cout << "Neccesery water: " << arr[i].waterToLowerPercentage(40, 1) << endl;
		 cout << endl;
	}
	
	iWannaGetDrunk(arr, n).Print();
	iWannaGetDrunkAndIAmAPoorFMIStudent(arr, n).Print();
	return 0;
}