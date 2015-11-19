#include<iostream>
#include"Polygon.h";
using namespace std;

float Segment::Line(Point a, Point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
float PolygonalLine::polygonLength()
{
	float sum = 0;
	for (int i = 0; i <count; i++)
	{
		sum=sum + Segment::Line(arr[i].first,arr[i].last);
	}
	return sum;
}

PolygonalLine longestPoligonalLine(PolygonalLine* arr, int n)
{
	PolygonalLine line = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (line.polygonLength() < arr[i].polygonLength())
		{
			line = arr[i];
		}
	}
	return line;
}
void PolygonSort(PolygonalLine *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i+1; j < n - 1; j++)
		{
			if (arr[k].polygonLength()>arr[j].polygonLength())
			{
				k = j;
			}
		}
		PolygonalLine temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}
bool FindWithBinnarySearch(PolygonalLine* arr, float target,int n)
{
	bool flag = false;
	int first = 0;
	int second = n-1;
	while (first <= second)
	{
		int mid = (first + second) / 2;
		float midValue = arr[mid].polygonLength();
		if (midValue < target)
		{
			first = mid + 1;
		}
		else if (midValue>target)
		{
			second = mid - 1;
		}
		else if (midValue == target)
		{
			flag = true;
		}
		mid = (first + second) / 2;
	}
	return flag;
}
int main()
{
	int nPolygon;
	cout << "Enter number of polygon lines:";
	cin >> nPolygon;
	PolygonalLine arrPolygon[100];
	for (int i = 0; i < nPolygon; i++)
	{
		cout << "Numbers of segments in this polygon line:";
		cin >> arrPolygon[i].count;
		for (int j = 0; j < arrPolygon[i].count; j++)
		{	
			if (j==0)
			{
				cout << "First x:";
				cin >> arrPolygon[i].arr[j].first.x;
				cout << "First y: ";
				cin >> arrPolygon[i].arr[j].first.y;
			}
			cout << "x:";
			cin >> arrPolygon[i].arr[j].last.x;
			cout << "y:";
			cin >> arrPolygon[i].arr[j].last.y;
			arrPolygon[i].arr[j + 1].first.x = arrPolygon[i].arr[j].last.x;
			arrPolygon[i].arr[j + 1].first.y = arrPolygon[i].arr[j].last.y;
		}
	}
	cout<<"Longest polygon line is with length: "<<longestPoligonalLine(arrPolygon, nPolygon).polygonLength()<<endl;
	PolygonSort(arrPolygon, nPolygon);
	cout << "Enter target: ";
	float target;
	cin >> target;
	cout << boolalpha << FindWithBinnarySearch(arrPolygon, target, nPolygon)<<endl;
	return 0;
}