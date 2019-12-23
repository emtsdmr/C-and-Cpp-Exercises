#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{/*
	//Writing
	ofstream file("text.txt");

	if (file.is_open())
	{
		file << "13 Em 22\n";
		file << "014 Emr 23\n";
		file << "013 Emru 24\n";
		file.close();
	}
*/
/*
	//Reading0
	string line;
	ifstream file("text.txt");
	if (file.is_open())
	{
		while (getline(file, line))
			cout << getline(file, line);
			cout << line << endl;
		file.close();
	}
	else
		cout << "file is not open!" << endl;
*/		
	//Reading1
	int id;
	string name;
	int age;
	ifstream file("text.txt");
	if (file.is_open())
	{
		while (file>>id)
			cout <<id<<"," << endl;
		file.close();
	}
	else
		cout << "file is not open!" << endl;


	return 0;
}