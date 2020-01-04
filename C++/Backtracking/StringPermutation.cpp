#include <iostream>
#include <string>

using namespace std;

void permutationStr(string s,string chosen);

int main()
{
	permutationStr("ABC","");
	return 0;
}

void permutationStr(string s,string chosen)
{
	if (s == "")
		cout << chosen << endl;
		
	else
		for (int i = 0; i < s.size(); i++)
		{
			//cout << i << endl;
			char c = s[i];
			chosen += c;
			s.erase(i, 1);
			//cout << "P(" << s << "," << chosen << ")" << endl;
			permutationStr(s, chosen);
			//cout << "*" << endl;
			s.insert(i, 1, c);
			chosen.erase(chosen.size()-1, 1);
		}
}
