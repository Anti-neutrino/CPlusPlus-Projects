#include<iostream>
using namespace std;
struct elem
{
	int data;
	elem* link;
	elem(int d, elem* p)
	{
		data = d;
		link = p;
	}
};
class Stack
{
private:
	elem* first;
	void toEnd(int elemnt)
	{
		elem* newElem = new elem(elemnt, first);
		if (first == NULL)
		{
			first = newElem;
		}
		else
		{
			elem* cnt = first;
			while (cnt->link)
			{
				cnt = cnt->link;
			}
			cnt->link = newElem;
			cnt->link->link = NULL;
		}
	}
public:
	Stack()
	{
		first = NULL;
	}
	void push(int element)
	{
		first = new elem(element, first);
	}
	void pop()
	{
		if (!isEmpty())
		{
			elem* p = first;
		    first = first->link;
		    delete p;
		}
		
	}
	bool isEmpty()
	{
		return first == NULL;
	}
	void print()
	{
		elem* current = first;
		while (current)
		{
			cout << current->data << " ";
			current = current->link;
		}
		cout << endl;
	}
	~Stack()
	{
		elem* p;
		while (first)
		{
			p = first;
			first=first->link;
			delete p;
		}
	}
	Stack(const Stack& a)
	{
		if (a.first)
		{
			first = NULL;
			elem* q = a.first;
			while (q)
			{
				toEnd(q->data);
				q = q->link;
			}
		}
	}
	Stack& operator=(const Stack& a)
	{
		if (this != &a)
		{
			elem* p;
			while (first)
			{
				p = first;
				first = first->link;
				delete p;
			}

			first = NULL;
			elem* q = a.first;
			while (q)
			{
				toEnd(q->data);
				q = q->link;
			}
		}
	}
	int size()const
	{
		int i = 0;
		elem* p = first;
		while (p)
		{
			i++;
			p = p->link;
		}
		return i;
	}
	int& top()const
	{
		return first->data;
	}
};

int main()
{
	Stack st;
	st.push(2);
	st.push(1);
	st.push(123);
	Stack pr(st);
	st.print();
	st.pop();
	pr.print();
	cout << st.size() << endl;
	st.print();
	cout << st.top() << endl;
	return 0;
}