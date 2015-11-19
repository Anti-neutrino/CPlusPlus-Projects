#include<iostream>
#include<stack>
#include<string>
using namespace std;

template<typename T>
struct Element
{
	T data;
	Element<T>* next;

	Element(T d, Element<T>* n)
	{
		data = d;
		next = n;
	}
};

template<typename T>
class Stack
{
private:
	Element<T>* first;
	int count;
	void toEnd(T element)
	{
		Element<T>* elem = new Element<T>(element, first);
		if (first == NULL)
		{
			first = elem;
		}
		else
		{
			Element<T>* current = first;
			while (current->next)
			{
				current = current->next;
			}

			current->next = elem;
			current->next->next = NULL;
		}
	}
public:
	Stack()
	{
		count = 0;
		first = NULL;
	}

	~Stack()
	{
		Element<T>* p;
		while (first)
		{
			p = first;
			first = first->next;
			delete p;
		}
	}

	Stack(const Stack& a)
	{
		if (a.first)
		{
			first = NULL;
			Element<T>* p = a.first;
			while (p)
			{
				toEnd(p->data);
				p = p->next;
			}
		}

		count = a.count;
	}

	Stack& operator=(const Stack& a)
	{
		if (this != &a)
		{
			while (first)
			{
				Element<T>* q = first;
				first = first->next;
				delete q;
			}

			first = NULL;
			Element<T>* q = a.first;
			while (q)
			{
				toEnd(q->data);
				q = q->next;
			}
		}

		count = a.count;

		return *this;
	}

	int Count()const
	{
		return this->count;
	}

	void push(T element)
	{
		Element<T>* elem = new Element<T>(element, first);
		first = elem;
		count++;
	}

	bool isEmpty()
	{
		return this->first == NULL;
	}

	bool pop()
	{
		if (!isEmpty())
		{
			count--;
			Element<T>* p = first;
			first = first->next;
			delete p;
			return true;
		}

		return false;
	}

	T top()
	{
		if (!isEmpty())
		{
			return this->first->data;
		}

		return NULL;
	}

	void print()
	{
		Element<T>* num = first;
		while (num)
		{
			cout << num->data << " ";
			num = num->next;
		}

		cout << endl;
	}
};

template<typename T>
class Queue
{
	Stack<T> firstStack;
	Stack<T> secondStack;
	int count;
public:
	Queue()
	{
		count = 0;
	}

	void Enqueue(T element)
	{

		firstStack.push(element);
		count++;
	}

	bool Dequeue(T &element)
	{
		if (firstStack.Count() > 0 || secondStack.Count() > 0)
		{
			if (secondStack.Count() > 0)
			{
				element = secondStack.top();
				secondStack.pop();
			}
			else
			{
				while (firstStack.Count() > 0)
				{
					T elem = firstStack.top();
					secondStack.push(elem);
					firstStack.pop();
				}

				element = secondStack.top();
				secondStack.pop();
			}

			count--;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool Contains(T element)
	{
		bool isContained = false;
		Stack<T> helperStack;
		while (firstStack.Count()!=0)
		{
			T elem = firstStack.top();
			if (elem == element)
			{
				isContained = true;
				break;
			}

			firstStack.pop();
			helperStack.push(elem);
		}

		while (helperStack.Count() != 0)
		{
			T elem = helperStack.top();
			helperStack.pop();
			firstStack.push(elem);
		}

		if (isContained)
		{
			return true;
		}

		while (secondStack.Count() != 0)
		{
			T elem = secondStack.top();
			if (elem == element)
			{
				isContained = true;
				break;
			}

			secondStack.pop();
			helperStack.push(elem);
		}

		while (helperStack.Count() != 0)
		{
			T elem = helperStack.top();
			helperStack.pop();
			secondStack.push(elem);
		}

		if (isContained)
		{
			return true;
		}

		return false;
	}

	bool Peek(T& elem)
	{
		if (!IsEmpty())
		{
			if (secondStack.Count() > 0)
			{
				elem = secondStack.top();
				return true;
			}
			else
			{
				Stack<T> helperStack;
				while (firstStack.Count() > 0)
				{
					T num = firstStack.top();
					helperStack.push(num);
					firstStack.pop();
				}

				T element = helperStack.top();
				
				while (helperStack.Count() > 0)
				{
					T helperNum = helperStack.top();
					firstStack.push(helperNum);
					helperStack.pop();
				}
				
				elem = element;
				return true;
			}
		}

		return false;
	}

	bool IsEmpty()
	{
	    return this->count == 0;
	}

	int Count()const
	{
		return count;
	}
};

int main()
{
	Queue<string> queue;
	queue.Enqueue("PHP");
	queue.Enqueue("C++");
	queue.Enqueue("JAVA");
	queue.Enqueue("JAVASCRIPT");
	queue.Enqueue("C#");
	cout<<"Queue contains C: " << boolalpha << queue.Contains("C") << endl;
	string x;
	queue.Peek(x);
	cout <<"First element: "<< x << endl;
	queue.Dequeue(x);
	cout << "Delete element: " << x << endl;
	cout << "Number of elements: " << queue.Count()<<endl;
	queue.Dequeue(x);
	cout << "Delete element: " << x << endl;
	queue.Dequeue(x);
	cout << "Delete element: " << x << endl;
	queue.Dequeue(x);
	cout << "Delete element: " << x << endl;
	queue.Dequeue(x);
	cout << "Delete element: " << x << endl;
	cout << "Queue is empty: " << boolalpha << queue.IsEmpty() << endl;
	system("pause");
	return 0;
}