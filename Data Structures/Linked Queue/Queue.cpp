#include<iostream>
using namespace std;
struct Elem
{
	int value;
	Elem* next;

	Elem(int val, Elem* el)
	{
		value = val;
		next = el;
	}
};

class Queue
{
	Elem* first;
	int count;

	void toEnd(int element)
	{
		Elem* newElem = new Elem(element, first);
		if (first == NULL)
		{
			first = newElem;
		}
		else
		{
			Elem* p = first;

			while (p->next)
			{
				p = p->next;
			}

			p->next = newElem;
			p->next->next = NULL;
		}
	}
public:
	Queue()
	{
		count = 0;
	}

	~Queue()
	{
		while (first)
		{
			Elem* p = first;
			first = first->next;
			delete p;
		}
	}

	Queue(const Queue& a)
	{
		if (a.first)
		{
			first = NULL;
			Elem* p = a.first;

			while (p)
			{
				toEnd(p->value);
				p = p->next;
			}
		}

		count = a.count;
	}

	Queue& operator=(const Queue& a)
	{
		if (this != &a)
		{
			Elem *p;
			while (first)
			{
				p = this->first;
				first = first->next;
				delete p;
			}

			if (a.first)
			{
				first = NULL;
				Elem* p = a.first;

				while (p)
				{
					toEnd(p->value);
					p = p->next;
				}
			}
		}
		count = a.count;

		return *this;
	}

	void push(int data)
	{
		count++;
		Elem* newEl = new Elem(data, first);
		first = newEl;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	int getCount()const
	{
		return count;
	}

	bool pop(int &x)
	{
		if (!isEmpty())
		{
			Elem* p = first;
			Elem* t = first;
			while (p->next)
			{
				p = p->next;
			}

			while ((t->next != p)&&t->next!=NULL)
			{
				t = t->next;
			}

			x = p->value;
			t->next = NULL;
			delete p;

			count--;
			if (count == 0)
			{
				first = NULL;
			}

			return true;
		}

		return false;
	}

	void print()const
	{
		Elem* newElem = first;
		while (newElem)
		{
			cout << newElem->value<<" ";
			newElem = newElem->next;
		}

		cout << endl;
	}
};

int main()
{
	int x;
	Queue queue;
	queue.push(1);
	queue.push(2);
	queue.push(12);
	cout << "Print queue start queue: ";
	queue.print();
	Queue newQueue(queue);
	queue.pop(x);
	cout << "Print start queue without first element: ";
	queue.print();
	cout << "Print newStack before deleting.";
	newQueue.print();
	newQueue = queue;
	cout << "Print newStack = stack.";
	newQueue.print();
	system("pause");
	return 0;
}