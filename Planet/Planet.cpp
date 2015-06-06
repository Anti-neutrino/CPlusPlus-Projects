#include<iostream>
#include<fstream>
using namespace std;
fstream input("data.txt");
struct Planet
{
	char name[40];
	double distance;
	double diameter;
	double mass;
	void Print();
};
void createPlanet(Planet planet[],int &n)
{
	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> planet[i].name;
		input >> planet[i].distance;
		input >> planet[i].diameter;
		input >> planet[i].mass;
	}
}
typedef  bool(*PlanetComparator)(Planet*, Planet*);

bool compareByDistance(Planet* a, Planet *b)
{
	return a->distance < b->distance;
}

bool compareByDiameter(Planet* a, Planet *b)
{
	return a->diameter < b->diameter;
}
void Sort(Planet *planet[], int n,PlanetComparator compare)
{
		for (int i = 0; i < n; i++)
	{
			int k = i;
		for (int j = 0; j < n-1; j++)
		{
			if (compare(planet[k],planet[j]))
			{
				k = j;
			}
			
		}
		Planet *temp = planet[i];
		planet[i] = planet[k];
		planet[k] = temp;
	}
}
void Planet::Print()
{
	cout << "Name: " << name << endl;
	cout << "Distance: " << distance<<endl;
	cout << "Diameter: " << diameter << endl;
	cout << "Mass: " << mass << endl;
	cout << "\n";
}
int main()
{
	int nPlanet;
	Planet arr[100];
	Planet *parr[100];
	createPlanet(arr, nPlanet);
	for (int i = 0; i < nPlanet; i++)
	{
		parr[i] = &arr[i];
	}
    Sort(parr, nPlanet,compareByDiameter);
	
	for (int i = 0; i < nPlanet; i++)
	{
		parr[i]->Print();
	}
	Sort(parr, nPlanet,compareByDistance);
	for (int i = 0; i < nPlanet; i++)
	{
		parr[i]->Print();
	}
	system("pause");
	return 0;
}