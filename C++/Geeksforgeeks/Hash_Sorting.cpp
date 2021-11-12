#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct HashNode{
	int number;
    int frequency;
    HashNode* next;
    HashNode(int n=0,int f=0, HashNode* nx=NULL)
    {
		number=n;
        frequency=f;
        next=nx;
    }
};

class HashSort{
private:
	HashNode** elements;
	int capacity;
	int size;
	queue<int> sorted;
public:
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
		size++;
		int status=0;
		int index=hashCode(Ai);

		if(elements[index] == NULL)
		{
			HashNode* newNode=new HashNode(Ai,1,NULL);
			elements[index]=newNode;
		}
		else
		{
			HashNode* current=elements[index];
			if(Ai < current->number)
			{
				HashNode* newNode=new HashNode(Ai,1,NULL);
				newNode->next=current;
				elements[index]=newNode;
			}
			else
			{
				while(current->next != NULL || current->number == Ai)
				{
					
					if(current->number == Ai)
					{
						current->frequency++;
						status=1;
						break;
					}
					if(current->next->number > Ai)
					{
						break;
					}	

					current=current->next;
				}
				if(status==0)
				{
					HashNode* newNode=new HashNode(Ai,1,NULL);
					newNode->next=current->next;
					current->next=newNode;
				}
			}
		}
	}

	void remove(int index, HashNode* &current, HashNode* &previous)
	{
		size--;
		if(current==elements[index])
		{
			HashNode* trash=elements[index];
			elements[index]=elements[index]->next;
			current= elements[index];
			previous->next=elements[index];
			delete trash;

		}
		else
		{
			HashNode* trash=current;
			previous->next=current->next;
			current=previous->next;
			delete trash;
		}
	}

	void sort(int limit)
	{
		int status=0;
		for(int k=limit;k>0;k--)
		{
			for(int l=0;l<capacity;l++)
			{
				HashNode* current=elements[l];
				HashNode* previous=new HashNode(0,0,current);

				while(current != NULL)
				{
					if(current->frequency == k)
					{
						for(int m=k;m>0;m--)
							sorted.push(current->number);

						remove(l,current,previous);
						status=1;
						printHashTable(0);
					}
					if(status == 0)
					{
						previous=current;
						current=current->next;
					}
					else
						status=0;
				}
			}
		}

	}

	void printHashTable(int i)
	{
		
				HashNode* current=elements[i];
				cout<<"number->frequency:"<<endl;
				while(current!=NULL)
				{
					cout<<"    "<<current->number<<" -> "<<current->frequency<<endl;
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
	hs.sort(60);
	queue<int> temp=hs.getSortedQueue();
	int i=0;
	bool status=true;
	cout<<endl<<"outputs:";

	if(temp.size()!=sorted_v.size())
		status=false;

	while(!temp.empty())
	{
		if(sorted_v[i] != temp.front())
		{
			status=false;
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
	//vector<int> sorted_v{5,5,4,4,1,2,8,9};//wrong case

	vector<int> unsorted_v{1,3,7,7,7,3,2,2,2,7,3,1,7,1,6,3,5,5,4,5,6,2,1,2,4,7,3,1,3,5,4,1,7,2,6,1,2};
	vector<int> sorted_v{1,1,1,1,1,1,1,2,2,2,2,2,2,2,7,7,7,7,7,7,7,3,3,3,3,3,3,5,5,5,5,4,4,4,6,6,6};
	//vector<int> sorted_v{1,1,1,1,1,1,1,2,2,2,2,2,2,2,7,7,7,7,7,7,3,3,3,3,3,3,5,5,5,5,4,4,4,6,6,6,7};//wrong case

	test_add(unsorted_v,hs);
	test_sort_remove(sorted_v,hs);

	return 0;
}
