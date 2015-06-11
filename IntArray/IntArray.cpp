#include<iostream>
#include<cassert>
using namespace std;
class IntArray
{
	int *arr;
	int size;
public:
	IntArray()
	{
		size = 0;
		arr = NULL;
	}
	IntArray(int psize)
	{
		size = psize;
	}
	IntArray(const IntArray& p)
	{
		arr = new int[p.size];
		assert(arr);
		for (int i = 0; i < p.size; i++)
		{
			arr[i] = p.arr[i];
		}
		size = p.size;
	}
	void Add(int element)
	{
		int *newBuf = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			newBuf[i] = arr[i];
		}
		newBuf[size] = element;
		size = size + 1;
		delete[] arr;
		arr = newBuf;
	}
	void Remove(int index)
	{
		assert(!(index < 0 && index >= size));
		int *newBuf = new int[size - 1];
		for (int i = 0; i < size; i++)
		{
			int k = i;
			if (k >= index)
			{
				k = i - 1;
			}
			if (i != index)
			{
				newBuf[k] = arr[i];
			}
			
		}
		size = size - 1;
		delete[] arr;
		arr = newBuf;

	}

	double sum()
	{
		double totalSum = 0;
		for (int i = 0; i < size; i++)
		{
			totalSum = totalSum + arr[i];
		}
		return totalSum;
	}

	bool equals(IntArray &brr)
	{
		if (size != brr.size)
		{
			return false;
		}
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != brr.arr[i])
			{
				return false;
			}
		}
		return true;
	}

	void Concat(IntArray &brr)
	{
		int i, j;
		int *newBuf = new int[size + brr.size];
		for (i = 0; i < size; i++)
		{
			newBuf[i] = arr[i];
		}
		for (j = 0; j < brr.size; j++)
		{
			newBuf[i] = brr.arr[j];
			i++;
		}
		size = size + brr.size;
		delete[] arr;
		arr = newBuf;
	}

	IntArray& operator=(const IntArray& r)
	{
		if (this != &r)
		{
			delete arr;
			arr = r.arr;
			size = r.size;
		}
		return *this;
	}
	bool member(int elemnt)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == elemnt)
			{
				return true;
			}
		}
		return false;
	}

	void print()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};
int main()
{
	IntArray arr,crr;
	arr.Add(5);
	arr.Add(6);
	arr.Add(7);
	arr.Add(1);
	
	arr.print();
	
	arr.Remove(2);
	crr.Add(5);
	crr.Add(6);
	crr.Add(2);
	
	arr.print();

    arr = crr;

	arr.print();
	
	cout << "Sum of the elements is: " << arr.sum() << endl;

	cout << boolalpha << arr.equals(crr)<<endl;

	arr.Concat(crr);

	arr.print();

	cout << boolalpha << arr.member(123) << endl;

	system("pause");

	return 0;
}