/*  
	Sorting Elements of an Array by Frequency 
	sort the array according to frequency of elements. That is elements that have higher frequency come first. 
	If frequencies of two elements are same, then smaller number comes first.

	Constraints:
	5 ≤ Vector size ≤ 130
	1 ≤ Every element of the vector ≤ 60
	
	Example:
	5 5 4 6 4 -> 4 4 5 5 6
	9 9 9 2 5 -> 9 9 9 2 5
*/

#include <iostream>
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

	int get_size()
	{
		return size;
	}

	int get_capacity()
	{
		return capacity;
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
			previous->next=current;
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
						cout<<"Table "<<l<<endl;
						printHashTable(l);
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
				if (current==NULL)
					cout<<"Empty\n"<<endl;
				else
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
	//hs.printHashTable(0);	
	cout<<endl;
	for(int i=0;i<hs.get_capacity();i++)
	{
		cout<<"Table "<<i<<endl;
		hs.printHashTable(i);	
	}

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

	//vector<int> unsorted_v{1,3,7,7,7,3,2,2,2,7,3,1,7,1,6,3,5,5,4,5,6,2,1,2,4,7,3,1,3,5,4,1,7,2,6,1,2};
	//vector<int> sorted_v{1,1,1,1,1,1,1,2,2,2,2,2,2,2,7,7,7,7,7,7,7,3,3,3,3,3,3,5,5,5,5,4,4,4,6,6,6};
	//vector<int> sorted_v{1,1,1,1,1,1,1,2,2,2,2,2,2,2,7,7,7,7,7,7,3,3,3,3,3,3,5,5,5,5,4,4,4,6,6,6,7};//wrong case

	vector<int> unsorted_v{11,13,27,17,47,23,12,21,32,47,23,51,57,16,60,13,15,35,42,15,26,32,17,27,47,57,13,1,4,5,4,1,7,2,36,1,2};
	vector<int> sorted_v{1,1,1,13,13,13,47,47,47,2,2,4,4,15,15,17,17,23,23,27,27,32,32,57,57,5,7,11,12,16,21,26,35,36,42,51,60};
	//vector<int> sorted_v{1,1,1,13,13,13,2,2,4,4,5,7,11,12,15,15,16,17,17,21,23,23,26,27,27,32,32,35,36,42,47,47,47,51,57,57,60};//wrong case

	test_add(unsorted_v,hs);
	test_sort_remove(sorted_v,hs);

	return 0;
}
