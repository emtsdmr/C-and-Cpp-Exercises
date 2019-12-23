
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ClosestPoints(int**,int,int**,int,int*,int*);
void ClosestPointsV2(int**,int,int**,int,int,int*,int*);
void ClosestPointsV3(int**,int,int**,int,int,int*,int*);
int FindDistance (int,int,char);
	
int main()
{
	int **E,**K;
	int N,M,ind1,ind2,k,i,j; 
	
	scanf("%d",&N);
	scanf("%d",&M);
	
	// 2 boyutta ucak bilgisi olsaydý
	/*
	E = (int **) calloc (N, sizeof(int *));
	for (i=0;i<N;i++)
		E[i] = (int *) calloc (2, sizeof(int));
	
	K = (int **) calloc (M, sizeof(int *));
	for (i=0;i<M;i++)
		K[i] = (int *) calloc (2, sizeof(int));
	
	for (i=0;i<N;i++)
		for (j=0;j<2;j++)
			scanf("%d",&E[i][j]);
			
	for (i=0;i<M;i++)
		for (j=0;j<2;j++)
			scanf("%d",&K[i][j]);
	
	
	ClosestPoints(E,N,K,M,&ind1,&ind2);
	*/
	
	// copcatan sitesinde k adet soru olsaydý
	// k adet soru
	scanf("%d",&k);
	E = (int **) calloc (N, sizeof(int *));
	for (i=0;i<N;i++)
		E[i] = (int *) calloc (k, sizeof(int));
	
	K = (int **) calloc (M, sizeof(int *));
	for (i=0;i<M;i++)
		K[i] = (int *) calloc (k, sizeof(int));
	
	for (i=0;i<N;i++)
		for (j=0;j<k;j++)
			scanf("%d",&E[i][j]);
			
	for (i=0;i<M;i++)
		for (j=0;j<k;j++)
			scanf("%d",&K[i][j]);

	
	ClosestPointsV2(E,N,K,M,k,&ind1,&ind2);
//	ClosestPointsV3(E,N,K,M,k,&ind1,&ind2);
	printf("%d %d\n",ind1,ind2);
}

/* 	E hava yollarýne ait uçaklarýn enlem ve boylam bilgisi E matrisinde (E[N][2]), 
	K hava yollarýne ait uçaklarýn enlem ve boylam bilgisi K matrisinde (K[M][2]), 
	Birbirine en yakýn uçaklarýn indislerini bulan fonksiyon
*/
//Ýki boyutlu veri için 
void ClosestPoints(int **E,int N,int **K, int M,int *ind1,int *ind2)
{
	int i,j,distMin=100000,dist;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
		{
			dist=abs(E[i][0]-K[j][0])+abs(E[i][1]-K[j][1]);
			if (dist<distMin)
			{
				distMin=dist;
				*ind1=i;
				*ind2=j;
			}
				
		}
}

/* Çöpçatan sitesi yapalým. N erkek, M kadýn dim soru
Sorular þöyle: Ayda kaç gün sinemaya gidersiniz? Tiyatro izlemeyi ne kadar seversiniz (1-5 arasý puanlayýn) Haftada kaç sayfa kitap okursunuz?
Erkeklerin cevaplarý E[N][dim],  Kadýnlarýn cevaplarý K[M][dim], 
Birbirine en uygun çift?
*/
// dim boyutlu veri için
void ClosestPointsV2(int **E,int N,int **K, int M,int dim,int *ind1,int *ind2)
{
	int i,j,k,distMin=100000,dist=0;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
		{
			for (k=0;k<dim;k++)
				dist+=abs(E[i][k]-K[j][k]); //dist+=FindDistance(E[i][k],K[j][k],'n');
			if (dist<distMin)
			{
				distMin=dist;
				*ind1=i;
				*ind2=j;
			}
			dist=0;	
		}
}

/*
Çöpçatan sitesinde sorular deðiþmiþ. Nümerik deðil kategorik sorular gelmiþ. Sorular þöyle:
Otostop çeken birini görseniz ne yaparsýnýz?
 1)Hýzlanýrým 2)Durup otostop yapmanýn her iki taraf için de tehlikeli olduðunu söylerim 3)Durup arabaya alýrým
Ne tür film izlemeyi seversiniz?
 1)Korku  2)Romantik Komedi 3)Polisiye 4)Bilim Kurgu
 
Cevaplar arasýnda nümerik distance bulmak mantýksýz. Ayný soruya ayný cevabý vermiþ mi diye bakmalýyým. Öyleyse distance metriðim deðiþmeli
*/
// dim boyutlu veri için Distance Metriði Farklý
void ClosestPointsV3(int **E,int N,int **K, int M,int dim,int *ind1,int *ind2)
{
	int i,j,k,distMin=100000,dist=0;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
		{
			for (k=0;k<dim;k++)
				dist+=FindDistance(E[i][k],K[j][k],'c');
			if (dist<distMin)
			{
				distMin=dist;
				*ind1=i;
				*ind2=j;
			}
			dist=0;	
		}
}

int FindDistance (int point1,int point2,char type)
{
	if (type=='c') //categorical
	{
		if (point1==point2)
			return 0;
		else 
			return 1;
	}
	else			// numerical
		return abs(point1-point2);
	
}



