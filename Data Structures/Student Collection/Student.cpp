#include<iostream>
#include<fstream>
#include<vector>
#include<vector>
using namespace std;
struct Student
{
	int fn;
	char name[100];
	Student()
	{
		fn = 0;
		strcpy_s(name, "");
	}

	Student(int facNum, char studName[100])
	{
		fn = facNum;
		strcpy_s(name, studName);
	}
};

class StudentCollection
{
public :
	virtual Student find(int fn) = 0;
	virtual void add(Student stud) = 0;
	virtual bool deleteStudent(int fn) = 0;
};

class ArrayStudentCollection:StudentCollection
{
private :
	Student student[100];
	int count;
public:
	ArrayStudentCollection()
	{
		count = 0;
	}

	ArrayStudentCollection(Student stud[100], int count)
	{
		count = 0;
	}

	Student find(int fn)
	{
		for (int i = 0; i < count; i++)
		{
			if (student[i].fn = fn)
			{
				return student[i];
			}
		}

		Student stud(-1, "nqma takav student");

		return stud;
	}

	void add(Student stud)
	{
		student[count ] = stud;
		count++;
	}

	bool deleteStudent(int fn)
	{
		for (int i = 0; i < count; i++)
		{
			if (student[i].fn == fn)
			{
				for (int j = i; j < count-1; j++)
				{
					student[j] = student[j + 1];
				}

				count--;
				return true;
			}
		}

		return false;
	}

	void print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << this->student[i].name << " " << this->student[i].fn << endl;
		}
	}
};

class FileStudentCollection:public StudentCollection
{
	fstream input;
	char fileName[100];
public:
	FileStudentCollection(char name[100])
	{
		strcpy_s(fileName, name);
	}

	Student find(int fn)
	{
		input.open(fileName);
		while (!input.eof())
		{
			int number;
			char name[100];
			input >> number;
			input.getline(name, 100);
			if (fn == number)
			{
				Student stud(number, name);
				return stud;
			}
		}

		input.close();
		Student stud(-1, "Nqma takav student.");
		return stud;
	}

	void add(Student stud)
	{
		input.open(fileName);
		input.seekp(0, ios::end);
		input << '\n';
		input << stud.fn << " " << stud.name;
		input.close();
	}

	bool deleteStudent(int fn)
	{
		vector<Student> listOfInts;
		input.open(fileName);

		while (!input.eof())
		{
			Student stud;
			input >> stud.fn >> stud.name;
			listOfInts.push_back(stud);
		}

		input.close();

		for (int i = 0; i < listOfInts.size(); i++)
		{
			if (listOfInts[i].fn == fn)
			{
				listOfInts.erase(listOfInts.begin()+i);
				return true;
			}
		}

		return false;
	}

	void print()
	{
		input.open(fileName);
		while (!input.eof())
		{
			int number;
			char name[100];
			input >> number;
			input.getline(name, 100);
			cout << number << " " << name << endl;
		}

		input.close();
	}
};

class BinaryStudentCollection:public StudentCollection
{
	fstream stream;
	char filename[100];
public:
	BinaryStudentCollection(char name[100])
	{
		strcpy_s(filename, name);
	}

	Student find(int fn)
	{
		stream.open(filename,ios::in|ios::out|ios::binary);
		Student newStudent;
		while (!stream.eof())
		{
			stream.read((char*) &newStudent,sizeof(Student));
			if (newStudent.fn == fn)
			{
				return newStudent;
			}
		}

		stream.close();
		Student emptyStudent(-1, "Nqma takav student");
		return emptyStudent;
	}

	void add(Student stud)
	{
		stream.open(filename,ios::in|ios::out|ios::binary);		
		stream.seekp(0, ios::end);
		stream.write((char*) &stud, sizeof(Student));
		stream.flush();
		stream.close();
	}

	bool deleteStudent(int fn)
	{
		stream.open(filename, ios::in | ios::out | ios::binary);
		Student student;
		vector<Student> students;
		while (!stream.eof())
		{
			if (stream.read((char*)&student, sizeof(Student)))
			{
				students.push_back(student);
			}
		}
	
		bool isContained = false;
		for (int i = 0; i < students.size(); i++)		
		{
			if (students[i].fn == fn)
			{
				students.erase(students.begin()+i);
				isContained = true;
				break;
			}
		}

		if (isContained)
		{
			stream.clear();
			stream.seekp(0);
			for (int i = 0; i < students.size(); i++)
			{
				stream.write((char*)&students[i], sizeof(Student));
			}

			stream.close();
			return true;
		}
		else
		{
			stream.close();
			return false;
		}
		
	}

	void print()
	{
		stream.open(filename,ios::in|ios::out|ios::binary);
		Student stud;
		while (!stream.eof())
		{
			if (stream.read((char*)&stud, sizeof(Student)))
			{
				cout << stud.fn << " " << stud.name << endl;
			}
		}

		stream.close();
	}
};

struct Element
{
	Student value;
	Element* next;

public:
	Element(Student stud, Element* elem)
	{
		this->value = stud;
		this->next = elem;
	}
};

class LinkedListStudent:StudentCollection
{
	Element* first;
	int count;
	void toEnd(Student element)
	{
		Element* newElem = new Element(element, first);
		if (first == NULL)
		{
			first = newElem;
		}
		else
		{
			Element* p = first;

			while (p->next)
			{
				p = p->next;
			}

			p->next = newElem;
			p->next->next = NULL;
		}
	}

	void printRecursiveStight(Element* p)
	{
		if (p == NULL)
		{
			return;
		}

		cout << p->value.fn << " " << p->value.name << endl;
		printRecursiveStight(p->next);
	}

	void printBack(Element* p)
	{
		if (p == NULL)
		{
			return;
		}

		Element* q=p;
		while (p->next)
		{
			p = p->next;
		}

		cout << p->value.fn << " " << p->value.name << endl;
		printBack(q->next);
	}
public:
	LinkedListStudent()
	{
		this->first = NULL;
		this->count = 0;
	}

	~LinkedListStudent()
	{
		while (first)
		{
			Element* elem = first;
			first = first->next;
			delete elem;
		}
	}

	LinkedListStudent(const LinkedListStudent& stud)
	{
		if (stud.first)
		{
			Element* p = stud.first;
			while (p)
			{
				toEnd(p->value);
				p = p->next;
			}
		}
	}

	LinkedListStudent& operator=(const LinkedListStudent& a)
	{
		if (this != &a)
		{
			while (first)
			{
				Element* elem = first;
				first = first->next;
				delete elem;
			}

			Element*p = a.first;
			while (p)
			{
				toEnd(p->value);
				p = p->next;
			}
		}

		return *this;
	}

	LinkedListStudent operator+(const LinkedListStudent& a)
	{
		Element* firstList = this->first;
		Element* secondList = a.first;
		LinkedListStudent result;

		while (firstList != NULL&&secondList != NULL)
		{
			if (firstList->value.fn < secondList->value.fn)
			{
				result.add(firstList->value);
				firstList = firstList->next;
			}
			else
			{
				result.add(secondList->value);
				secondList = secondList->next;
			}
		}

		while (firstList != NULL)
		{
			result.add(firstList->value);
			firstList = firstList->next;
		}

		while (secondList != NULL)
		{
			result.add(secondList->value);
			secondList = secondList->next;
		}


		return result;
	}

	void add(Student stud)
	{
		if (first == NULL)
		{
			first = new Element(stud, NULL);
		}
		else
		{
			Element* elem = first;
			while (elem->next)
			{
				elem = elem->next;
			}

			elem->next = new Element(stud, NULL);
		}

		count++;
	}

	Student find(int fn)
	{
		Element* p = first;
		while (p)
		{
			if (p->value.fn == fn)
			{
				return p->value;
			}

			p = p->next;
		}

		Student stud(-1, "Nqma takav student");
		return stud;
	}

	void reverseList()
	{
		if (this->first==NULL)
		{
			return;
		}

		Element* prev = NULL;
		Element* current = NULL;
		Element* next = NULL;
		current = this->first;

		while (current!=NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		this->first = prev;
	}

	/*void reverse(Element* p) {
		if (!p) return;
		Element* rest = p->next;
		if (!rest) return;
		reverse(rest);
		p->next->next = p;
		p->next = NULL;
		p = rest;
	}*/

	bool deleteStudent(int fn)
	{
		Element* elem = first;
		if (elem->value.fn == fn)
		{	
			Element* elementForDelete = elem;
			first = first->next;
			delete elementForDelete;
			count--;

			return true;
		}
		else
		{
			while (elem->next)
			{
				if (elem->next->value.fn == fn)
				{
					Element* elementForDelete = elem->next;
					elem->next = elem->next->next;
					delete elementForDelete;
					count--;

					return true;
				}

				elem = elem->next;
			}
		}

		return false;
	}

	void print()const
	{
		Element* q = first;
		while (q)
		{
			cout << q->value.fn << " " << q->value.name << endl;
			q = q->next;
		}
	}
};

int main()
{
	LinkedListStudent collection;
	LinkedListStudent newCollection;
	Student stud1(123, "momo");
	Student stud2(321, "bai kolio");
	Student stud3(1488, "barabanche");
	Student stud4(200, "Karlson");
	Student stud5(1011, "Selio Kodo");
	newCollection.add(stud4);
	newCollection.add(stud5);
	collection.add(stud1);
	collection.add(stud2);
	collection.add(stud3);
	LinkedListStudent result= collection + newCollection;

	result.print();
	cout << endl;
	result.reverseList();
	result.print();
	system("pause");
	return 0;
}