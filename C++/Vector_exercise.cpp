#include <iostream>
#include <vector>

using namespace std;

int inRange(vector<int> v1, int min, int max);
void  removeAll(vector<string>& v2, string s);

int main()
{
	vector<int> v1{ 28, 1, 17, 4, 41, 9, 59, 8, 31, 30, 25 };
	cout<<inRange(v1, 10, 30)<<endl;

	vector<string> v2{ "a","b","c","b","b","a","b" };
	removeAll(v2, "b");
	for (string i : v2)
		cout << i<<' ';
}

int inRange(vector<int> v1, int min, int max)
{	
	int count = 0;
	for (int i : v1)
	{
		if (i <=max && i>=min)
			count++;
	}
	return count;
}

void  removeAll(vector<string>& v2, string s)
{
	for (int i = v2.size() - 1; i >= 0; i--)
	{
		if (v2[i] == s)
		{
			v2.erase(v2.begin() + i);
		}
	}
}