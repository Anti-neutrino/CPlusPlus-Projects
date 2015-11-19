#include<iostream>
#include<string>
using namespace std;
template<typename T>
class CircularQueue
{
private:
	static const int InitialCapacity = 16;
	int count;
	int capacity;
	T *arr;
	int startIndex = 0;
	int lastIndex = 0;
	void grow()
	{
		T *newArr = new T[2 * capacity];
		for (int i = 0; i < count; i++)
		{
			newArr[i] = arr[i];
		}

		capacity = 2 * capacity;
		arr = newArr;
		startIndex = 0;
		lastIndex = count;
	}


public:
	CircularQueue(int capac = InitialCapacity)
	{
		arr = new T[capac];
		capacity = capac;
		count = 0;
	}

	~CircularQueue()
	{
		delete arr;
	}

	int getCount()const
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	void Enqueue(T element)
	{
		if (count >= capacity)
		{
			this->grow();
		}

		arr[lastIndex] = element;
		lastIndex = (lastIndex + 1) % capacity;
		count++;
	}
	
	bool Dequeue(T &x)
	{
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return false;
		}

		T* newArr = new T[startIndex];
		x = arr[startIndex];
		startIndex = (startIndex + 1) % capacity;
		this->count--;
		return true;
	}

	T Peek()
	{
		if (isEmpty())
		{
			return NULL;
		}

		return arr[startIndex];
	}
};

int main()
{
	CircularQueue<string> queue;
	queue.Enqueue("java");
	queue.Enqueue("c++");
	queue.Enqueue("c#");
	queue.Enqueue("racket");
	string str; 
	queue.Dequeue(str);
	cout << str<<endl;
	str=queue.Peek();
	cout << str << endl;
	system("pause");
	return 0;
}