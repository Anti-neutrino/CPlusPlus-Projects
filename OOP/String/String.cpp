#include <iostream>
#include <string>
#include<cassert>

using namespace std;

class String
{

public:
	char *buf;

	String(char *s)
	{

		buf = new char[strlen(s) + 1];
		strcpy(buf, s);

	}

	String(const String& p)
	{
		buf = new char[strlen(p.buf) + 1];
		assert(buf);
		strcpy(buf, p.buf);
	}

	~String()
	{
		delete buf;
	}

	void print()
	{
		cout << buf << endl;
	}


	void concat(String s)
	{

		//buf, s.buf

		char *newbuf = new char[strlen(buf) + strlen(s.buf) + 1];

		strcpy(newbuf, buf);

		strcat(newbuf, s.buf);

		delete buf;
		buf = newbuf;

	}

	void concatChar(char c)
	{
		char *newbuf = new char[strlen(buf) +1 + 1];
		
		strcpy(newbuf, buf);

		strcat(newbuf, &c);

		delete buf;
		buf = newbuf;
	}

	bool lessThan(String s)
	{
		if (strcmp(buf, s.buf) > 0)
		{
			return true;
		}
		return false;
	}

	void remove(char c)
	{
		int k = 0;
		for (int j = 0; j < strlen(buf); j++)
		{
			for (int i = 0; i < strlen(buf); i++)
			{
				if (buf[i] == c)
				{
					k = i;
					while (buf[k] != '\0')
					{
						buf[k] = buf[k + 1];
						k++;
					}
				}
			}
		}
	}

};


int main()
{	
	char tmp[1000] = "Hello World";

	String s1(tmp),
		s2(tmp);

	s1.print();
	s2.print();

	s1.concat(s2);

	s1.print();


	cout << "\n\n\n";
	cout << boolalpha << s2.lessThan(s1) << endl;
	cout << endl;
	s2.concatChar('t');
	s2.print();
	cout << endl;
	s2.remove('l');
	s2.print();
	return 0;
}