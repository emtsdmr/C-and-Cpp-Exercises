#include <iostream>

using namespace std;

void printBinary(int n);
int main()
{
	printBinary(48);
	return 0;
}

void printBinary(int n)
{

	if (n == 1)
		cout << n;
	else
	{
		int dev = n / 2;
		int rem = n % 2;
		//cout << rem; *reverse 000011
		printBinary(dev);
		cout << rem;          //110000
	}
}
