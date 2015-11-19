#include<iostream>
#include<fstream>
using namespace std;
void Merge(ifstream& f1, ifstream& f2, ofstream& output)
{
	int firstNumber;
	int secondNumber;
	f1 >> firstNumber;
	f2 >> secondNumber;
	while (!f1.eof() && !f2.eof())
	{
		if (firstNumber < secondNumber)
		{
			output << firstNumber << " ";
			f1 >> firstNumber;
		}
		else
		{
			output << secondNumber << " ";
			f2 >> secondNumber;
		}
	}

	while (!f1.eof())
	{
		f1 >> firstNumber;
		output << firstNumber<<" ";
		
	}

	while (!f2.eof())
	{
		f2 >> secondNumber;
		output << secondNumber<<" ";
	}
}

int main()
{
	ifstream first("First.txt");
	ifstream second("Second.txt");
	ofstream result("Output.txt");
	Merge(first, second, result);
	system("pause");
	return 0;
}