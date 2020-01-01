#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s);
int main()
{
	cout << isPalindrome("emrullah tasdemir rimedsat hallurme");
	return 0;
}


bool isPalindrome(string s)
{
	int length = s.size();
	if (length <= 1)
		return true;
	else
	{
		return s[0] == s[length - 1] and isPalindrome(s.substr(1, length - 2));
	}
}
