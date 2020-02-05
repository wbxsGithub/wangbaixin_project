#pragma once   //只包含一次
#include <iostream>
#include <vector>
using namespace std;
typedef struct TNode
{
	int val;
	struct TNode *lchild, *right;
	TNode(int val)
	{
		this->val = val;
	}
}TNode, *TreeList;

struct Node
{
	int val;
	Node *lchild, *rchild;
	Node(int val)
	{
		this->val = val;
		lchild = NULL;
		rchild = NULL;
	}
};

class BTree
{
	Node *root;
public:
	Node *getRoot();
	Node *buildBinaryTree(vector<int> &arr);

	void inorder(Node *root);
	void preorder(Node *root);
	void postorder(Node *root);

	Node* searchNode(Node *root,int key);
	Node* destroyTree(Node *root);
	int max(Node *root);
	int min(Node *root);

	void layerorder(Node* root);//按层遍历
	
};