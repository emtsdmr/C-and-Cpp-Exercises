#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

using namespace std;
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data, TreeNode* left = NULL, TreeNode* right = NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
	~TreeNode()
	{

	}
};

class BinaryTree
{
public:
	BinaryTree(TreeNode* initializer_list);

	void print();
	bool contains(int value);
	void printSideways();

private:
	TreeNode* root;
	void printHelper(TreeNode* node);
	bool containsHelper(TreeNode* node, int value);
	void printSideways(TreeNode* node, string indent);
};

#endif;
