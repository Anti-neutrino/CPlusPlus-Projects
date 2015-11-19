#include<iostream>
using namespace std;
struct elem
{
	int data;
	elem* link;
	elem(int d, elem* m)
	{
		data = d;
		link = m;
	}
};

class Queue
{
private:
	elem* first;
	void toEnd(int element)
	{
		elem* newElem = new elem(element, first);
		if (first == NULL)
		{
			first = newElem;
		}
		else
		{
			elem* q = first;
			while (q)
			{
				q = q->link;
			}
			q->link = newElem;
			q->link->link = NULL;
		}
	}
public:
	Queue()
	{
		first = NULL;
	}
	~Queue()
	{
		elem *p;
		while (first)
		{
			p = first;
			first = first->link;
			delete p;
		}
	}
	Queue(const Queue& a)
	{
		first = NULL;
		elem* p = a.first;
		while (p)
		{
			toEnd(p->data);
			p = p->link;
		}
	}
	void Enqueue(int element)
	{
		first = new elem(element, first);
	}
	void print()
	{
		elem* p = first;
		while (p)
		{
			cout << p->data << " ";
			p = p->link;
		}
		cout << endl;
	}
	bool isEmpty()const
	{
		return first == NULL;
	}
	bool Dequeue(int& x)
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			elem* p = first;
			elem* t = first;
			while (p->link)
			{
				p = p->link;
			}
			while (t->link != p)
			{
				t = t->link;
			}
			x = p->data;
			t->link = NULL;
			delete p;
		}
		return true;
	}
	int top()const
	{
		elem* p = first;
		while (p->link)
		{
			p = p->link;
		}
		return p->data;
	}
};
int main()
{
	int x;
	Queue qu;
	qu.Enqueue(123);
	qu.Enqueue(2);
	qu.Enqueue(5);
	qu.Enqueue(65);
	qu.Enqueue(1231);
	qu.print();
	qu.Dequeue(x);
	qu.Dequeue(x);
	qu.print();
	cout << x << endl;
	cout << qu.top() << endl;
	return 0;
}