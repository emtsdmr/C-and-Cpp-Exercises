#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

int main()
{
	LinkedList list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.insert(1, 4);
	list.remove(0);
	
	cout << list << endl;
	return 0;
}
