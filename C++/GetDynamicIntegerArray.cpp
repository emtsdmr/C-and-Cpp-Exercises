#include <iostream>
using namespace std;

int *GetDynamicIntegerArray(int sentinel, int & n);
int main(){
	int *arr,n,sentinel=-1;
	arr=GetDynamicIntegerArray(sentinel,n);
	cout<<arr[0]<<arr[1]<<n;
	return 0;
}
int *GetDynamicIntegerArray(int sentinel, int & n){
	int *arr = new int[45];
	int i,j=0;
	cout<<"Enter the elements of the array, one per line."<<endl;
	cout<<"Use "<<sentinel<<" to signal the end of the list."<<endl;
	while(1){
		cout<<"? ";
		cin>>i;
		if (i==sentinel){
			n=j;
			break;
		}
		
		arr[j]=i;j++;	
	}
	//delete[] arr;
	return arr;
}
