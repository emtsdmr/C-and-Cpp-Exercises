#include <stdio.h>
int IsFieldAvailable(int ar[100][100],int size,int choice,int x,int y);
void PlaceShip(int ar[100][100],int size,int choice,int x,int y);
void Fire(int ar[100][100],int a,int b);
int main(){
	
	int a,b,k,n,m,x,y,score,size,choice,ver,hor,available=0;
	int ar[100][100];
	
	printf("Please provide the length and width of the playing field:\n");
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ar[i][j]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) 
			printf("%d",ar[i][j]);
			printf("\n");}
			while(k!=0)
					{

						while (!available)
						{
							printf("x,y,size,horizontal(0)/vertical(1):\n");
							scanf("%d %d %d %d",&x,&y,&size,&choice);

							if (choice==0)
							{
								if((x+size)<m)
									available=1;
							}
							else
							{
								if((y+size)<n)
									available=1;		
							}

						}		
						available=IsFieldAvailable(ar,size,choice,x,y);
						if(available)
						{
							printf("Field is available\n");
							PlaceShip(ar,size,choice,x,y);
						}
						else
							printf("Ships overlap!\n");
						
						for(int i=0;i<n;i++)
						{
							for(int j=0;j<m;j++) 
							printf("%d",ar[i][j]);
							printf("\n");
						}
						printf("Do you want to continue? Yes(1)/No(0) ");
						scanf("%d",&k);	
						available=0;
					} 
	printf("Fire Cordinates:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	Fire(ar,a,b);
	
	return 0;
}
int IsFieldAvailable(int ar[100][100],int size,int choice,int x,int y)
{	int available;
	for(int i=0;i<size;i++)
	{
		if(choice==1)
		{
			if(ar[x+i][y] != 0)
			{
				available=0;
				break;
			}
		
			else
				available=1;
		}			
		if(choice==0)
		{
			if(ar[x][y+i] != 0)
			{
				available=0;
				break;
			}
		
			else		
				available=1;
		}
	}
	return available;
}

void PlaceShip(int ar[100][100],int size,int choice,int x,int y)
{
	for(int i=0;i<size;i++)
	{
		if(choice)
			ar[x+i][y] =size;
		else
			ar[x][y+i] =size;
	}
	printf("Placed in desired location\n");
}
void Fire(int ar[100][100],int a,int b)
{
	int score;
	score=ar[a][b];
	printf("Your Score: %d",score);
	
}
