#include<iostream>
#include<fstream>
using namespace std;
fstream input("fruits.txt");
enum color {brown=1,green=2 ,orange=3,red=4,yellow=5};

enum yna {no=0,yes=1};
struct Fruit
{
	char name[32];
	color cl;
	yna annual;
	yna perennial;
	yna tropical;
	void Print();
	void Color();
	void Annual();
	void Perennial();
	void Tropical();
};
void Fruit::Print()
{
	cout << "Name: "<<name<<endl;
	cout << "Color: ";
	Color();
	cout << "Annual: ";
	Annual();
	cout << "Perennial: ";
	Perennial();
	cout << "Tropical: ";
	Tropical();
	cout << "\n";
}

void Fruit::Color()
{
	switch (cl)
	{
	case brown:cout << "Brown" << endl;
		break;
	case green:cout << "Green" << endl;
		break;
	case orange:cout << "Orange" << endl;
		break;
	case red:cout << "Red" << endl;
		break;
	case yellow:cout << "Yellow" << endl;
		break;
	default:cout << "This color is undefined!" << endl;
		break;
	}
	
}
void Fruit::Annual()
{
	switch (annual)
	{
	case yes:cout << "yes" << endl;
		break;
	case no:cout << "no" << endl;
		break;
	default:cout << "NULL"; return;
	}
}
void Fruit::Perennial()
{
	switch (perennial)
	{
	case yes:cout << "yes" << endl;
		break;
	case no:cout << "no" << endl;
		break;
	default:cout << "NULL"; return;
	}
}
void Fruit::Tropical()
{
	switch (tropical)
	{
	case yes:cout << "yes" << endl;
		break;
	case no:cout << "no" << endl;
		break;
	default:cout << "NULL"; return;
	}
}

void Table()
{
	cout << "Colors: 1.brown 2.green 3.orange 4.red 5.yellow" << endl;
	cout << "Annual,Perennial,Tropical: 0.no 1.yes" << endl;
}

void createArray(Fruit arr[], int &n)
{
	input >> n;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		Table();
		cout << endl;
		cin.sync();
		/*input.getline(arr[i].name, 32);
		int m;
		input >> m;
		arr[i].cl =(color) m;
		input >> m;
		arr[i].annual = (yna)m;
		input >> m;
		arr[i].perennial = (yna)m;
		input >> m;
		arr[i].tropical = (yna)m;*/
		
		cout << "Name: ";
		cin.getline(arr[i].name, 32);
		int m;
		cout << "Enter color: ";
		cin >> m;
		arr[i].cl =(color) m;
		cout << "Annual: ";
		cin >> m;
		arr[i].annual = (yna)m;
		cout << "Perennial: ";
		cin >> m;
		arr[i].perennial = (yna)m;
		cout << "Tropical: ";
		cin >> m;
		arr[i].tropical = (yna)m;
	}
}

bool compareByName(Fruit* a, Fruit* b)
{
	return strcmp(a->name, b->name) < 0;
}

bool compareByColor(Fruit* a, Fruit* b)
{
	return a->cl < b->cl;
}

bool compareByAnnual(Fruit* a, Fruit* b)
{
	return a->annual > b->annual;
}

bool compareByPerrennial(Fruit* a, Fruit* b)
{
	return a->perennial > b->perennial;
}

bool compareByTropical(Fruit* a, Fruit* b)
{
	return a->tropical > b->tropical;
}

typedef bool(*FruitsComparator)(Fruit*, Fruit*);

void Sort(Fruit *arr[], int n,FruitsComparator compare)
{		
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = 0; j < n - 1; j++)
		{
			if (compare(arr[k],arr[j]))
			{
				k = j;
			}
		}
		Fruit* temp = arr[k];
		arr[k] = arr[i];
		arr[i] = temp;
	}
}

int main()
{
	int nFruit;
	Fruit arr[100];
	Fruit *parr[100];
	createArray(arr, nFruit);
	for (int i = 0; i < nFruit; i++)
	{
		parr[i] = &arr[i];
	}
	Sort(parr, nFruit,compareByName);
	for (int i = 0; i < nFruit; i++)
	{
		parr[i]->Print();
	}
	Sort(parr, nFruit, compareByColor);
	for (int i = 0; i < nFruit; i++)
	{
		parr[i]->Print();
	}
	system("pause");
	return 0;
}