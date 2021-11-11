#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool ReadVector(ifstream& infile, vector<double>& vec);
int main()
{
	vector <double> roots;
	ifstream file("text.txt");
	bool a=ReadVector(file, roots);
	cout << a << endl;
	for (double i : roots)
		cout << i << " ";
	a = ReadVector(file, roots);
	cout <<"\n"<< a << endl;
	for (double i : roots)
		cout << i << " ";
	a = ReadVector(file, roots);
	cout << "\n" << a << endl;
	for (double i : roots)
		cout << i << " ";

	return 0;
}

bool ReadVector(ifstream& file, vector<double>& vec)
{
	string line;
	int size = vec.size();
	if (file.is_open())
	{
		while (getline(file , line))
		{
			if (line == "")
			{
				return true;
			}
			double line_d = stod(line);
			vec.push_back(line_d);
			//cout <<line<< endl; // typeid(line).name() 
		}
		if (size == vec.size())
		{
			file.close();
			return false;
		}
		return true;
	}
	else
		cout << "file is not open!" << endl;
}