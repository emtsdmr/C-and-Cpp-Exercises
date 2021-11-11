#include <iostream>
#include <string>
using namespace std;

struct HashNode{
	int index;
    int value;
    HashNode* next;
    HashNode(int i=0,int v=0, HashNode* n=NULL)
    {
		index=i;
        value=v;
        next=n;
    }
};

void add(int Ai,HashNode** elements)
{
	int status=0,indx;
	int order=(int)Ai/10; // hash code

	if(elements[order] == NULL)
	{
		HashNode* newNode=new HashNode(Ai,1,NULL);
		elements[order]=newNode;
	}
	else
	{
		HashNode* current=elements[order];
		if(Ai < current->index)
		{//	cout<<"***"<<endl;
			HashNode* newNode=new HashNode(Ai,1,NULL);
			newNode->next=current;
			elements[order]=newNode;
		}
		else
		{
			while(current->next != NULL)
			{
				
				if(current->index == Ai)
				{
					current->value++;
					status=1;
					break;
				}
				if(current->next->index > Ai)
				{
					break;
				}	

				current=current->next;
			}
			if(status==0)
			{//	cout<<"$$$"<<endl;
				HashNode* newNode=new HashNode(Ai,1,NULL);
				newNode->next=current->next;
				current->next=newNode;
			}
		}
	}
}

int main() {
	//code
	int T,N,A,capacity,status=0;
	HashNode** elements;
	cin>>T;
	for (int i=0; i<T;i++)
	{
	    cin>>N;
		capacity=60/10+1;//HashCode
		elements= new HashNode*[capacity]();
	    for(int j=0; j<N;j++)
	    {
			//cout<<"Add an element: ";
	        cin>>A;
	        add(A,elements);

	    }
			/*HashNode* current=elements[0];
			while(current!=NULL)
			{
				cout<< current->index<<" ";
				current=current->next;
			}cout<<endl;*/
		
		for(int k=60;k>0;k--)
		{
			for(int l=0;l<7;l++)
			{
				HashNode* current=elements[l];

				while(current != NULL)
				{
					if(current->value == k)
					{
						for(int m=k;m>0;m--)
							cout<<current->index<<" ";

						HashNode* trash=current;
						current=current->next;
						delete trash;
						status=1;
					}
					if(status == 0)
						current=current->next;
					else
						status=0;
				}
			}
		}cout<<endl;
	}
	return 0;
}
