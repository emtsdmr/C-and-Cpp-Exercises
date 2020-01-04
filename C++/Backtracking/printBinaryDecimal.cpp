#include <iostream>
#include <string>

using namespace std;

void printBinary(int digits, string prefix);
void printDecimal(int digits, string prefix);
int main()
{
	printBinary(3, "");
	//printDecimal(2, "");
	return 0;
}

void printBinary(int digits, string prefix)
{
	cout << "printBinary(" << digits << "," << prefix << ")" << endl;
	if (digits == 0)
		cout << prefix << endl;
	else
	{
		printBinary(digits - 1, prefix + "0");
		printBinary(digits - 1, prefix + "1");
	}

}
void printDecimal(int digits, string prefix)
{
	if (digits == 0)
		cout << prefix << endl;
	else
		for (int i = 0; i <= 9; i++)
			printDecimal(digits - 1, prefix + to_string(i));
}