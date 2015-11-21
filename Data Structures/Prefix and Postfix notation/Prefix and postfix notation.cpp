#include<iostream>
#include<stack>
#include<list>
#include<queue>
#include<string>
using namespace std;
char statement[101];
int k;

void convertInPrefixNotation()
{
	string postfixString = "";
	queue<int> newQueue;
	int index = 0;
	for (int i = 0; i < k; i++)
	{
		if (statement[i] >= '0'&&statement[i] <= '9')
		{
			newQueue.push(statement[i]);
		}
		else
		{
			postfixString = statement[i] + postfixString;
		}
	}

	while (newQueue.size() > 0)
	{
		postfixString += newQueue.front();
		newQueue.pop();
	}

	strcpy_s(statement, postfixString.c_str());
}

void input()
{
	cin >> statement;
	k = strlen(statement);
	convertInPrefixNotation();
}

void estimatePrefixStatement()
{
	int index = -1;
	bool check = true;
	list<int> st;
	for (int i = 0; i < k; i++)
	{
		if (statement[i] >= '0'&&statement[i] <= '9')
		{
			if (check)
			{
				index = i-1;
				check = false;
			}

			st.push_back(statement[i] - '0');
		}
	}

	if (index < 0)
	{
		cout << "Incorrect prefix statment." << endl;
		return;
	}
	

	for (int i = index; i >= 0; i--)
	{
		if (st.size() == 0)
		{
			cout << "Incorrect prefix statement." << endl;
			return;
		}

		int first = st.front();
		st.pop_front();

		if (st.size() == 0)
		{
			cout << "Incorrect prefix statement." << endl;
			return;
		}

		int second = st.front();
		st.pop_front();

		switch (statement[i])
		{
		case '+':st.push_front(first + second); break;
		case '-':st.push_front(first - second); break;
		case '*':st.push_front(first*second); break;
		case '/':st.push_front(first / second); break;
		case '^':st.push_front(pow(first, second)); break;
		}
	}

	if (st.size() == 1)
	{
		cout<<st.front()<<endl;
	}
	else
	{
		cout << "Incorrect prefix statemnt." << endl;
	}

}


void estimatePostfixStatement()
{
	stack<int> st;
	for (int i = 0; i < k; i++)
	{
		if (statement[i] >= '0'&&statement[i] <= '9')
		{
			st.push(statement[i] - '0');
		}
		else
		{
			if (st.empty())
			{
				cout << "Incorrect statement!" << endl;
				return;
			}

			int first = st.top();
			st.pop();

			if (st.empty())
			{
				cout << "Incorrect statement!" << endl;
				return;
			}

			int second = st.top();
			st.pop();

			switch (statement[i])
			{
			case '+':st.push(first + second); break;
			case '-':st.push(first - second); break;
			case '*':st.push(first*second); break;
			case '/':st.push(first / second); break;
			}
		}
	}

	if (st.size() == 1)
	{
		cout << st.top();
	}
	else
	{
		cout << "Incorrect statement!" << endl;
	}
}

int main()
{
	input();
	convertInPrefixNotation();
	//estimatePostfixStatement();
	estimatePrefixStatement();
	system("pause");
	return 0;
}