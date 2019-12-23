#include <stdio.h>
int main(){
	int m,n,i,j,l,k=1;
	static int mat[100][100];
	printf("Please provide the matrix size:\n"); 
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		if(i%2==0)
		{
			if((i/2)%2==0)
			{
				for(j=0;j<n;j++)
				{ mat[i][j]=k;k++;
				}
			}
			else
			{
				for(j=n-1;j>=0;j--)
				{ mat[i][j]=k;k++;
				}
			}
		}
		else
		{		if(l%2==0){
		
					int j=n-1;
					mat[i][j]=k;k++;
					}
				else{
				
					int j=0;
					mat[i][j]=k;k++;
					} l++;
		}
	}
	for(i=0;i<m;i++){
	
		
		for(j=0;j<n;j++){
		printf("%3d",mat[i][j]);
		}
		printf("\n");
		}
	 return 0;
 	
}
