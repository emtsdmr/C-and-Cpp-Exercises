#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rollDice0(int dice,vector<string> & ar,string prefix);
void rollDice1(int dice, vector<int>& ar);
void rollDiceSum(int dice, vector<int>& ar, int desired, int sofar);
void print(vector<int>& ar);
//int call;
int main()
{

	vector<string> arr;
	rollDice0(2, arr,"");

	for (string s : arr)
		cout << s << endl;

	vector<int> ar;
	rollDice1(3, ar);

	vector<int> arSum;
	rollDiceSum(3, arSum, 7, 0); //Sum of 3 dices is 7
	//cout << call;

	return 0;
}

void rollDice0(int dice,vector<string> & ar,string prefix)
{
	if (dice == 0)
		ar.push_back(prefix);
	else
		for (int i = 1; i <= 6; i++)
		{
			if (prefix == "")
				rollDice0(dice - 1, ar, prefix + to_string(i));
			else
				rollDice0(dice - 1, ar, prefix + "," + to_string(i));
		}

}

void rollDice1(int dice, vector<int>& ar)
{
	if (dice == 0)
		print(ar);
	else
		for (int i = 1; i <= 6; i++)
		{
			ar.push_back(i);
			rollDice1(dice - 1, ar);
			ar.erase(ar.end() - 1);
		}

}

void rollDiceSum(int dice, vector<int>& ar, int desired, int sofar)
{	
	//call++;
	if (dice == 0)
		print(ar);
	else
		for (int i = 1; i <= 6; i++)
		{
			if (sofar + i + 1 * (dice - 1) <= desired && sofar + i + 6 * (dice - 1) >= desired)
			{
				ar.push_back(i);
				rollDiceSum(dice - 1, ar, desired, sofar + i);
				ar.erase(ar.end() - 1);
			}
		}
}
void print(vector<int>& ar)
{
	cout << "{";
	for (int i = 0; i < ar.size(); i++)
	{
		if (i == 0)
			cout << ar[i];
		else
			cout << "," << ar[i];
	}
	cout << "}" << endl;
}
