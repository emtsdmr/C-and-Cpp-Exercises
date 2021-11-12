#include <iostream>
#include <string>
#include <queue>
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

class HashSort{
private:
	HashNode** elements;
	int capacity;
	int size;
public:
	queue<int> sorted;
	HashSort()
	{
		capacity=7;
		size=0;
		elements= new HashNode*[capacity]();
	}

	~HashSort()
	{
		delete[] elements;
	}

	queue<int> getSortedQueue()
	{
		return sorted;
	}

	int hashCode(int i)
	{
		return (int) i/10;
	}

	void add(int Ai)
	{
		int status=0;
		int order=hashCode(Ai);

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
				while(current->next != NULL || current->index == Ai)
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

	void sort_remove(int limit)
	{
		int status=0;
		for(int k=limit;k>0;k--)
		{
			for(int l=0;l<capacity;l++)
			{
				HashNode* current=elements[l];

				while(current != NULL)
				{
					if(current->value == k)
					{
						//sorting
						for(int m=k;m>0;m--)
							sorted.push(current->index);

						//removing
						HashNode* trash=current;
						current=current->next;//wrong bağı doğru kur
						delete trash;
						status=1;
						printHashTable(0);
					}
					if(status == 0)
						current=current->next;
					else
						status=0;
				}
			}
		}

	}

	void printHashTable(int i)
	{
		
				HashNode* current=elements[i];
				cout<<"index->value/number->frequency:"<<endl;
				while(current!=NULL)
				{
					cout<<"   "<<current->index<<" -> "<<current->value<<endl;
					current=current->next;
				}
	}
	
	

};

void test_add(vector<int> &unsorted_v, HashSort &hs)
{
	cout<<"inputs:";
	for(int i : unsorted_v)
	{
		cout<<" "<<i;
		hs.add(i);
	}
	cout<<endl;
	hs.printHashTable(0);	

}

void test_sort_remove(vector<int> &sorted_v, HashSort &hs)
{
	hs.sort_remove(60);
	queue<int> temp=hs.getSortedQueue();cout<<temp.size()<<endl;
	int i=0;
	bool status=true;
	cout<<endl<<"outputs:";
	while(!temp.empty())
	{
		if(sorted_v[i] != temp.front() || temp.size()!=sorted_v.size())
		{
			cout<<"...";
			status=false;
			break;
		}
		cout<<" "<<temp.front();
		temp.pop(); i++;
	}
	if(status)
		cout<<endl<<"Sorting was successful!"<<endl;
	else
		cout<<endl<<"Wrong sorting technic!"<<endl;
}

int main() {
	//code
	HashSort hs;
	//vector<int> unsorted_v{4,5,9,8,4,5,2,1};
	//vector<int> sorted_v{4,4,5,5,1,2,8,9};

	vector<int> unsorted_v{1,3,7,7,7,3,2,2,2,7,3,1,7,1,6,3,5,5,4,5,6,2,1,2,4,7,3,1,3,5,4,1,7,2,6,1,2};
	vector<int> sorted_v{1,1,1,1,1,1,1,2,2,2,2,2,2,2,7,7,7,7,7,7,7,3,3,3,3,3,3,5,5,5,5,4,4,4,6,6,6};

	test_add(unsorted_v,hs);
	test_sort_remove(sorted_v,hs);

	return 0;
}
