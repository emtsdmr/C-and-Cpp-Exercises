#include <iostream>
#include <vector>
using namespace std;

bool IsMagicSquare(vector<vector<int> > & ar);
int main()
{
    int sizeX, sizeY, v;
    cout << "Size of Matrix:";
    cin >> sizeX >> sizeY;
	
	vector<vector<int> > arr;
	
    cout << "Elements of the Matrix:";
    for (int i = 0; i < sizeX; i++)
	{
		vector<int> temp;
        for (int j = 0; j < sizeY; j++)
		{	
			cin >> v;
			temp.push_back(v);
		}
		arr.push_back(temp);
	}

    if (IsMagicSquare(arr))
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << "\n";
            for (int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j];
        }
    }
    else
        cout << "Matrix isn't magical square! ";

    return 0;
}

bool IsMagicSquare(vector<vector<int> > & ar)
{
	int x=ar.size(),y=ar[0].size();
    if (x == y)
    {
    	vector<int> ver(y,0);
    	vector<int> hor(x,0);
        int cross0=0;
        int cross1=0;

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                hor[i] += ar[i][j];
                ver[j] += ar[i][j];
                if (i == j)
                    cross0 += ar[i][j];
                if (i + j == x - 1)
                    cross1 += ar[i][j];
            }
        }
        if (cross0 != cross1)
            return false;
        else
        {
            for (int i = 0; i < x; i++)
                if ((cross0 != ver[i]) || (cross1 != hor[i]))
                    return false;
        }
    }
    else
        return false;

    return true;
}
