#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

BinaryTree::BinaryTree(TreeNode* initializer_list)
{
	root = initializer_list;
}
void BinaryTree::print()
{
	printHelper(root);
}
void BinaryTree::printHelper(TreeNode* node)
{
	if (node != NULL)
	{
		cout << node->data << endl;
		printHelper(node->left);
		printHelper(node->right);
	}
}
bool BinaryTree::contains(int value)
{
	return containsHelper(root, value);
}
bool BinaryTree::containsHelper(TreeNode* node, int value)
{
	if (node == NULL)
		return false;
	else if (node->data == value)
		return true;
	else
	{
		return containsHelper(node->left, value) || containsHelper(node->right, value); //doest have to look right side if left was true
	}
}
void BinaryTree::printSideways()
{
	printSideways(root, "");
}
void BinaryTree::printSideways(TreeNode* node, string indent)
{
	if (node != NULL)
	{
		printSideways(node->right,indent+ "    ");
		cout << indent<< node->data << endl;
		printSideways(node->left, indent + "    ");
	}
}