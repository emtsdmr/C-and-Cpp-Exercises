#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void showq(queue <string> gq);
int checkBalance(string s);
void stutter(queue<int>& q);
void mirror(queue<string>& q1);

int main()
{

	string s = "if (a(4) > 9) { foo(a(2)); }";//-1
	cout << checkBalance(s)<<endl;
	s = "for (i=0;i<a(3};i++) { foo{); )";//14
	cout << checkBalance(s) << endl;
	s = "while (true) foo(); }{ ()";//20
	cout << checkBalance(s) << endl;
	s = "if (x) {";//8
	cout << checkBalance(s) << endl;
	

	queue <int> q0;
	for (int i = 1; i < 4; i++)
		q0.push(i);
	stutter(q0);


	queue <string> q1;
	q1.push("a"); q1.push("b"); q1.push("c");
	mirror(q1);
	showq(q1);

	return 0;
}

int checkBalance(string str)
{
	stack <char> s;
	for (int i = 0; i < str.size(); i++)
	{		
		char c = str[i];
		if (c == '(' || c == '{'){
			s.push(c);}
		else if (c == ')')
		{
			if (s.empty() || s.top() != '(')
				return i;
			else
				s.pop();
		}
		else if (c == '}')
		{
			if (s.empty() || s.top() != '{')
				return i;
			else
				s.pop();
		}		
	}
	if (s.empty())
		return -1;
	else
		return str.length();
}
void stutter(queue<int>& q)//1,2,3=>1,1,2,2,3,3
{
	int size = q.size();
	for (int i = 0; i < size; i++)
	{
		int n = q.front();
		q.pop();
		q.push(n);
		q.push(n);
	}
}

void mirror(queue<string>& q)// a,b,c=>a,b,c,c,b,a
{
	stack <string> s;
	int size = q.size();
	for (int i = 0; i < size; i++)
	{
		string temp=q.front();
		q.pop();
		s.push(temp);
		q.push(temp);
	}
	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

void showq(queue <string> q)
{
	queue <string> g = q;
	while (!g.empty())
	{
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}