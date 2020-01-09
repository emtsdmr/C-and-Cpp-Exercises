#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

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

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void add(int value);
	int getMin() const;
	bool isEmpty() const;
	void print() const;
	bool contains(int value);
	void printSideways();
	void remove(int value);

private:
	TreeNode* root;
	void destructor(TreeNode* node);
	void add(TreeNode*& node, int value);
	int getMin(TreeNode* node) const;
	void remove(TreeNode*& node, int value);

	void printHelper(TreeNode* node) const;
	bool containsHelper(TreeNode* node, int value);
	void printSideways(TreeNode* node, string indent);
};

#endif;
