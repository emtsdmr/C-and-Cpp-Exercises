#include "LinkedList.h"

LinkedList::LinkedList() 
{
	front = NULL;
}
LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::add(int value)
{
	if (front == NULL)
		front = new ListNode(value);
	else
	{
		ListNode* current = front;
		while (current->next != NULL)
			current = current->next;
		current->next = new ListNode(value);
	}
}
void LinkedList::clear()
{
	while (front != NULL)
		remove(0);
}

int LinkedList::get(int index) const
{
	ListNode* current = front;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->data;
}
void LinkedList::set(int index,int value)
{
	ListNode* current = front;
	for (int i = 0; i < index; i++)
		current = current->next;
	current->data = value;
} 
void LinkedList::insert(int index,int value)
{
	if (index == 0)
	{
		ListNode* oldFront = front;//in order not to lose all data
		front = new ListNode(value);
		front->next = oldFront;
	}
	else
	{
		ListNode* current = front;
		for (int i = 0; i < index - 1; i++)
			current = current->next;

		ListNode* newNode = new ListNode(value);
		newNode->next = current->next;// it is the first one because I dont want
		current->next = newNode;	  // to lose the rest of the array
	}
}
void LinkedList::remove(int index)
{
	ListNode* trash;
	if (index == 0)
	{
		trash = front;
		front = front->next;
	}
	else
	{
		ListNode* current = front;
		for (int i = 0; i < index - 1; i++)
			current = current->next;
		trash = current->next;
		current->next = current->next->next;
	}
	delete trash;
}
bool LinkedList::isEmpty() const
{
	return front == NULL;
}
int LinkedList::size() const
{
	int count = 0;
	if(front!=NULL)
	{
		ListNode* current = front;
		while (current->next != NULL)
		{
			current = current->next;
			count++;
		}
		count++;
	}
	return count;
}
ostream& operator <<(ostream& out, LinkedList& list)
{
	out << "{";

	for (int i = 0; i < list.size(); i++)
	{
		if (i == 0)
			out << list.get(i);
		else
			out << ", " << list.get(i);
	}

	out << "}";
	return out;
}