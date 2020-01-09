#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
	BinarySearchTree tree;
	tree.add(55);
	tree.add(29);
	tree.add(87);
	tree.add(-3);
	tree.add(42);
	tree.add(60);
	tree.add(91);

	tree.print(); cout << endl;
	cout << tree.getMin() << endl;
	tree.printSideways(); cout << endl;
	tree.remove(55);
	tree.printSideways(); cout << endl;

	return 0;
}