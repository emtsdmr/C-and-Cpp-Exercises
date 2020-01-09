#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	TreeNode* node = new TreeNode();
	node->data = 42;
	node->left = new TreeNode(59);
	node->right = new TreeNode(27);
	node->right->right= new TreeNode(86);

	BinaryTree tree(node);
	tree.print();
*/
	TreeNode* ll = new TreeNode(1);
	TreeNode* lr = new TreeNode(3);
	TreeNode* l = new TreeNode(2,ll,lr);

	TreeNode* rl = new TreeNode(5);
	TreeNode* rr = new TreeNode(7);
	TreeNode* r = new TreeNode(6, rl, rr);

	TreeNode* root = new TreeNode(4, l, r);

	BinaryTree tree(root);

	cout <<boolalpha<< tree.contains(1)<< "\n";
	cout << tree.contains(10) << "\n";

	tree.print();
	tree.printSideways();
	return 0;
}