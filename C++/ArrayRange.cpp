#include <iostream>
using namespace std;
double *range(double array[]);
int main(){
	double array[10],*arr;
	double i=0;int j=0,size;
	cout<<"Enter the elements of the array, one per line."<<endl;
	cout<<"Use -1 to signal the end of the list."<<endl;
	while(i!=-1){
		cout<<"? ";
		cin>>i;
		array[j]=i;j++;
	}
	//size=sizeof array/sizeof array[0];
	//size = *(&array + 1) - array;
	arr=range(array);
	cout<<"The range of values is "<<arr[0]<<'-'<<arr[1];
	return 0;
}
double *range(double array[]){
	//int size=sizeof array/sizeof array[0];  *son elemana -1 ata,oraya gelince de dögüden break ile çik
	//cout<<sizeof array<<sizeof array[0];
	double max=0,min=100000000,x;
	int i=0;
	while(x!=-1){
		x=array[i];
		if (x==-1)
			break;
		else if (x<min)
			min=x;
		else if(x>max)
			max=x;
		i++;
	}
	double arr[2]={min,max};
	return arr;
}
