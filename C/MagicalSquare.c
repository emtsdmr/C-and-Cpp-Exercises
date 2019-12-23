// the program that creates a magic square (square matrix with equal sum of all rows and columns) for the given b and n values in the range [b n]
// b=1 n=5
// 1 2 3 4 5
// 2 3 4 5 1
// 3 4 5 1 2
// 4 5 1 2 3
// 5 1 2 3 4
#include <stdio.h>
int main()
{
	int n,i,j,b;
	int mat[50][50];
	printf("The first and last value of the number range to create a magic square?\n");
	scanf("%d %d",&b,&n);
	n=n-b+1;

	for (i=0;i<n;i++)
		mat[0][i]=b++;

	/*
	for (i=1;i<n;i++)
	{
		for (j=0;j<n-1;j++)
			mat[i][j]=mat[i-1][j+1];

		mat[i][n-1]=mat[i-1][0];
	}
	*/


	for (i=1;i<n;i++)
	{
		for (j=0;j<n;j++)
			mat[i][j]=mat[i-1][(j+1)%n];
	}


	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}


}


