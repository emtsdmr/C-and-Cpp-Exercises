#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverseLines(ifstream& file);
int main()
{
	ifstream file("text.txt");
	reverseLines(file);
	return 0;
}

void reverseLines(ifstream& file)
{
	string line;
	if (getline(file, line))
	{
		reverseLines(file);
		cout << line << endl;
	}

}
