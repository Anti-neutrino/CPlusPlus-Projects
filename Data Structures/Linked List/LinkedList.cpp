#include <iostream>
#include <cassert>
using namespace std;

struct Element
{
	int data;
	Element* next;
};

class List
{
	Element* first;
	Element* last;
	int size;

public:
	List();
	~List();
	List(const List& l);
	List& operator=(const List& l);
	bool isEmpty() const;
	int getSize() const;
	int getFront() const;
	int getBack() const;

	void pushFront(int data);
	void pushBack(int data);
	void popFront();
	void popBack();

	void insertAtIndex(int idx, int data);
	void popAtIndex(int idx);
	int getAtIndex(int idx);
	void clear();
	void reverseList();
	void print();
private:
	void copy(const List& l);
	void destroy();
};


List::List() : first(NULL), last(NULL), size(0) {}

List::~List()
{
	destroy();
}

List::List(const List& l) : first(NULL), last(NULL), size(0)
{
	copy(l);
}

List& List::operator=(const List& l)
{
	if (this != &l)
	{
		destroy();
		copy(l);
	}
	return *this;
}

void List::pushFront(int data)
{
	Element* tmp = new Element;
	tmp->data = data;
	tmp->next = first;
	first = tmp;
	if (last == NULL)
		last = first;
	size++;
}

void List::pushBack(int data)
{
	Element* tmp = new Element;
	tmp->data = data;
	tmp->next = NULL;
	if (first == NULL)
		first = last = tmp;
	else
	{
		last->next = tmp;
		last = tmp;
	}
	size++;
}

void List::popFront()
{
	if (isEmpty())
		return;
	Element* tmp = first;
	first = first->next;
	delete tmp;
	size--;
	if (size == 0)
		first = last = NULL;
}

/// linear time complexity because of the impossibility of accessing the previous element in constant time
void List::popBack()
{
	if (size == 0)
		return;
	if (size == 1)
	{
		delete last;
		first = last = NULL;
	}
	else if (size == 2)
	{
		delete last;
		last = first;
	}
	else
	{
		Element* current = first;
		while (current->next->next)
		{
			current = current->next;
		}
		delete current->next;
		current->next = NULL;
		last = current;
	}
	size--;
}

void List::destroy()
{
	while (!isEmpty())
		popBack();
}

void List::copy(const List& l)
{
	Element* current = l.first;
	while (current)
	{
		pushBack(current->data);
		current = current->next;
	}
}

int List::getSize() const
{
	return size;
}

bool List::isEmpty() const
{
	return size == 0;
}

int List::getFront() const
{
	return first->data;
}

int List::getBack() const
{
	return last->data;
}

void List::clear()
{
	destroy();
}

void List::insertAtIndex(int index, int data)
{
	assert(index >= 0 && index <= size);
	if (index == 0)
	{
		pushFront(data);
		return;
	}
	if (index == size)
	{
		pushBack(data);
		return;
	}
	Element* current = first;
	for (int i = 0; i<index - 1; i++)
	{
		current = current->next;
	}
	Element* tmp = new Element;
	assert(tmp);
	tmp->data = data;
	tmp->next = current->next;
	current->next = tmp;
	size++;
}
void List::popAtIndex(int index)
{
	assert(index >= 0 && index < size);
	Element* current = first;
	if (index == 0)
	{
		popFront();
		return;
	}
	if (index == size - 1)
	{
		popBack();
		return;
	}
	for (int i = 0; i < index - 1; i++)
	{
		current = current->next;
	}
	Element* tempLink = current->next->next;
	Element* trash = current->next;
	current = tempLink;
	delete trash;
	size--;
}

int List::getAtIndex(int index)
{
	assert(index >= 0 && index < size);
	Element* current = first;

	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current->data;
}

void List::reverseList()
{
	if (this->first == NULL)
	{
		return;
	}

	Element *prev = NULL;
	Element* current = NULL;
	Element*next = NULL;
	current = this->first;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	first = prev;
}

void List::print()
{
	Element* p = this->first;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;
}

int main()
{
	List arr;
	arr.pushBack(1);
	arr.pushBack(1223);
	//arr.pushBack(987);
	cout << "List: ";
	arr.print();
	cout << "Revesresed list: ";
	arr.reverseList();
	arr.print();
	system("pause");
	return 0;
}