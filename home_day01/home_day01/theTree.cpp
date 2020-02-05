#include "BTree.h"
#include <queue>
#include <stack>
Node *BTree::getRoot()//获取根节点的封装方法
{
	return root;
}

#pragma region //创建搜索树
Node *BTree::buildBinaryTree(vector<int> &arr)
{
	if (arr.size() == 0)
	{
		return NULL;
	}
	root = new Node(arr[0]);
	for (int i = 1; i < arr.size();i++)
	{
		Node *node = new Node(arr[i]);//先将要创建的节点存入堆中
		Node *rootNode = root;//指向初始根节点的指针
		while (1)
		{
			if (node->val < rootNode->val)
			{
				if (rootNode->lchild == NULL)
				{
					rootNode->lchild = node;
					break;
				}
				rootNode = rootNode->lchild;
			}
			else
			{
				if (rootNode->rchild == NULL)
				{
					rootNode->rchild = node;
					break;
				}
				rootNode = rootNode->rchild;
			}
		}
	}
}
#pragma endregion

void BTree::inorder(Node *root)//中序遍历输出
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->lchild);
	cout << root->val << " ";
	inorder(root->rchild);
}
void BTree::preorder(Node *rootNode) //先序遍历输出
{
	if (rootNode == NULL)
	{
		return;
	}
	cout << rootNode->val << " ";
	preorder(rootNode->lchild);
	preorder(rootNode->rchild);
}
void BTree::postorder(Node *root)//后序遍历输出
{
	if (root==NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->val << " ";
}

Node* BTree:: searchNode(Node *root, int key)//在二叉树中搜索给定key值
{
	if (root == NULL || root->val==key)
	{
		return root;
	}
	if (root->val > key)
		return searchNode(root->lchild, key);
	else
		return searchNode(root->rchild, key);
}
Node* BTree::destroyTree(Node *root)//摧毁并释放树
{
	if (root == NULL)
	{
		return root;
	}
	if (root->lchild!=NULL)
		return destroyTree(root->lchild);
	if (root->rchild != NULL)
		return destroyTree(root->rchild);
	delete root;

}
int BTree::max(Node *root)
{
	if (root->rchild == NULL)
	{
		return root->val;
	}
	max(root->rchild);
}
int BTree::min(Node *root)
{
	if (root->lchild == NULL)
	{
		return root->val;
	}
	min(root->lchild);
}

void BTree::layerorder(Node* root)//按层遍历搜索树
{
	if (root == NULL)
	{
		return;
	}
	
	queue<Node*> que;
	que.push(root);
	Node* last = root;
	Node* nlast = NULL;
	while (!que.empty())
	{
		Node* tem = que.front();
		cout << tem->val << " ";
		if (tem->lchild)
		{
			que.push(tem->lchild);
			nlast = tem->lchild;
		}
		if (tem->rchild)
		{
			que.push(tem->rchild);
			nlast = tem->rchild;
		}
		if (last == tem)
		{
			cout << endl;
			last = nlast;
		}
		que.pop();
	}
}
