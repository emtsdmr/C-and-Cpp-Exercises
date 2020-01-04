#include <iostream>
#include <string>
#include <vector>

using namespace std;

void subLists(vector <string>& availabe,vector <string>& chosen);
void print(vector<string>& ar);
int main()
{
	vector <string> Available;
	vector <string> Chosen;
	Available.push_back("Em"); Available.push_back("Rul"); Available.push_back("Lah");
	subLists(Available, Chosen);

	return 0;
}

void subLists(vector <string>& available, vector <string>& chosen)
{
	if (available.empty())
		print(chosen);

	else
	{
		//there are two choices to explore
		string c = available[0];
		chosen.push_back(c);
		available.erase(available.begin()); 
		subLists(available, chosen); // choose and explore (with)

		chosen.pop_back();
		subLists(available, chosen); // choose and explore (without)

		available.insert(available.begin(),c); // un-choose in order to continue to search
	}
}

void print(vector<string>& ar)
{
	cout << "{";
	for (int i = 0; i < ar.size(); i++)
	{
		if (i == 0)
			cout << ar[i];
		else
			cout << ", " << ar[i];
	}
	cout << "}"<<endl;
}
