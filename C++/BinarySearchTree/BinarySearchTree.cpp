#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	destructor(root);
}
void BinarySearchTree::destructor(TreeNode* node)
{
	if (node != NULL)
	{
		destructor(node->left);
		destructor(node->right);
		delete node;
	}
}
void BinarySearchTree::add(int value)
{
	add(root, value);
}

void BinarySearchTree::add(TreeNode*& node, int value) // & is very important
{
	if (node == NULL)
		node = new TreeNode(value);

	else if (value < node->data)
		add(node->left, value);

	else if (value > node->data)
		add(node->right, value);
	
	// else->duplicate 
}

/*    Long Way
void BinarySearchTree::add(int value)
{
	if (root == NULL)
		root = new TreeNode(value);
	else
		add(root, value);
}
void BinarySearchTree::add(TreeNode* node, int value)
{
	if (node == NULL)
		node = new TreeNode(value);
	else if (value < node->data)
	{
		if (node->left == NULL)
			node->left = new TreeNode(value);
		else
			add(node->left, value);
	}
	else if (value > node->data)
	{
		if (node->right == NULL)
			node->right = new TreeNode(value);
		else
			add(node->right, value);
	}
	// else->duplicate 
		
}*/
int BinarySearchTree::getMin() const
{
	if (root == NULL)
		cout << "there is no elements!";
	else
		return getMin(root);
}

int BinarySearchTree::getMin(TreeNode* node) const
{
	if (node->left == NULL)
		return node->data;
	else
		return getMin(node->left);
}

void BinarySearchTree::remove(int value)
{
	remove(root, value);
}
void BinarySearchTree::remove(TreeNode*& node, int value)
{
	if (node == NULL)
		;
	if (value < node->data)
		remove(node->left, value);
	else if (value > node->data)
		remove(node->right, value);
	else
	{
		TreeNode* trash = NULL;
		if (node->left == NULL && node->right == NULL) // Leaf
		{
			trash = node;
			node = NULL;
		}
		else if (node->right == NULL) //Left child only
		{
			trash = node;
			node = node->left;
		}
		else if (node->left == NULL) //Right child only
		{
			trash = node;
			node = node->right;
		}
		else                        //Left&Right subtrees
		{
			int newData = getMin(node->right); // or getMax(node->left)
			node->data = newData;
			remove(node->right,newData); //it won't visit here next time
		}	
		if (trash != NULL)
			delete trash;
	}
	
}
void BinarySearchTree::print() const
{
	printHelper(root);
}
void BinarySearchTree::printHelper(TreeNode* node) const
{
	if (node != NULL)
	{
		cout << node->data << endl;
		printHelper(node->left);
		printHelper(node->right);
	}
}
bool BinarySearchTree::contains(int value)
{
	return containsHelper(root, value);
}
bool BinarySearchTree::containsHelper(TreeNode* node, int value)
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
void BinarySearchTree::printSideways()
{
	printSideways(root, "");
}
void BinarySearchTree::printSideways(TreeNode* node, string indent)
{
	if (node != NULL)
	{
		printSideways(node->right,indent+ "    ");
		cout << indent<< node->data << endl;
		printSideways(node->left, indent + "    ");
	}
}
