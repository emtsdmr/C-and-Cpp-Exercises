#include <iostream>
using namespace std;

bool IsMagicSquare(int** ar,int x,int y);
int main()
{
    int sizeX, sizeY;
    bool a;
    cout << "Size of Matrix:";
    cin >> sizeX >> sizeY;

    int** arr = new int* [sizeY];
    for (int i = 0; i < sizeY; ++i)
    {
        arr[i] = new int[sizeX];
    }

    cout << "Elements of the Matrix:";
    for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
            cin >> arr[i][j];

    if (IsMagicSquare(arr, sizeX, sizeY))
    {
        for (int i = 0; i < sizeX; i++)
        {
            cout << "\n";
            for (int j = 0; j < sizeY; j++)
                cout << arr[i][j];
        }
    }
    else
    {
        for (int i = 0; i < sizeY; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }


    return 0;
}

bool IsMagicSquare(int** ar,int x, int y)
{
    if (x == y)
    {
        int* ver = new int[x]();
        int* hor = new int[y]();
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
