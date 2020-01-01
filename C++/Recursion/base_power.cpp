#include <iostream>

using namespace std;

int power(int base, int exp);
int main()
{
	cout << power(3, 4);
	
	return 0;
}


int power(int base,int exp)
{
	if (exp == 1)
		return base;
	else
	{
		return base * power(base, exp - 1);
	}
}

