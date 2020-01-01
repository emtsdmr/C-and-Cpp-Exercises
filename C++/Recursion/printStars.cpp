#include <iostream>

using namespace std;

void PrintStars(int n);
int main()
{
	PrintStars(10);
	return 0;
}
void PrintStars(int n)
{
	if (n == 1)
		cout << "*";
	else
	{
		cout << "*";
		PrintStars(n - 1);
	}
}