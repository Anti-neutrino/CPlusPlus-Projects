#include "stdafx.h"
#include<iostream>
using namespace std;
struct ListNode
{
	int data;
	ListNode* link;
	ListNode(int a, ListNode* b)
	{
		data = a;
		link = b;
	}
};
class List
{
private:
	ListNode* first;
public:
	List()
	{
		first = NULL;
	}
	List(const List& a)
	{
		first = NULL;
		if (a.first)
		{
			ListNode* current = a.first;
			while (current)
			{
				toEnd(current->data);
				current = current->link;
			}
		}
	}
	void push(int a)
	{
		first = new ListNode(a, first);
	}
	void toEnd(int elemnt)
	{
		ListNode* newElem = new ListNode(elemnt, first);
		if (first == NULL)
		{
			first = newElem;
		}
		else
		{
			ListNode* cnt = first;
			while (cnt->link)
			{
				cnt = cnt->link;
			}
			cnt->link = newElem;
			cnt->link->link = NULL;
		}
	}
	void print()const
	{
		ListNode* cnt = first;
		while (cnt)
		{
			cout << cnt->data << " ";
			cnt = cnt->link;
		}
		cout << "\n";
	}
	~List()
	{
		ListNode* newList;
		while (first)
		{
			newList = first;
			first = first->link;
			delete newList;
		}
	}

	List& operator=(const List& a)
	{
		if (this != &a)
		{
			ListNode* n;
			while (first)
			{
				n = first;
				first->link;
				delete n;
			}
			first = NULL;
			ListNode* newElem=a.first;
			while (newElem)
			{
				toEnd(newElem->data);
				newElem = newElem->link;
			}
		}
		return *this;
	}
	int& operator[](int index)
	{
		int i = 0;
		ListNode* newList = first;
		while (i != index)
		{
			newList = newList->link;
			i++;
		}
		return newList->data;
	}

	ListNode& operator+(ListNode a)
	{
		ListNode* newElem = new ListNode(first->data + a.data, first);
		return *newElem;
	}
};
int main()
{
	List arr;
	arr.push(1);
	arr.push(4);
	arr.toEnd(5);
	arr.toEnd(10);
	arr.print();
	cout << endl;
	cout << arr[2]+arr[1];
	return 0;
}