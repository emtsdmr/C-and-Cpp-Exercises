#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string message;
	map<string, string> mp;
	
	mp["E"] = ". ";
	mp["M"] = "__ ";
	mp["R"] = "._. ";
	mp["U"] = ".._ ";
	mp["L"] = "._.. ";
	mp["A"] = "._ ";
	mp["H"] = ".... ";

	mp[". "] = "E";
	mp["__ "] = "M";
	mp["._. "] = "R";
	mp[".._ "] = "U";
	mp["._.. "] = "L";
	mp["._ "] = "A";
	mp[".... "] = "H";

	cout << "Message: ";
	getline(cin, message);
	int start = 0;
	string s0;
	if (message[0] == '.' || message[0] == '_')
	{	
		for (int i = 0; i <= message.size(); i++)
			if (message[i] == ' ')
			{
				for (int j = start; j <= i; j++)
				{
					s0 += message[j];
				}
				cout << mp[s0];
				s0 = "";
				start=i+1;

				if (message[i + 1] == ' ')
				{
					cout << " "; i++; start++;
				}

			}
	}
	else
	{
		for (int i = 0; i <= message.size(); i++)
		{
			if (message[i] == ' ')
				cout << " ";
			else
			{
				string s1(1, message[i]);
				cout << mp[s1];
			}
		}	
	}

	return 0;
}