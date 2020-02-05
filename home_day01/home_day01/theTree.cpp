#include "BTree.h"
#include <queue>
#include <stack>
Node *BTree::getRoot()//��ȡ���ڵ�ķ�װ����
{
	return root;
}

#pragma region //����������
Node *BTree::buildBinaryTree(vector<int> &arr)
{
	if (arr.size() == 0)
	{
		return NULL;
	}
	root = new Node(arr[0]);
	for (int i = 1; i < arr.size();i++)
	{
		Node *node = new Node(arr[i]);//�Ƚ�Ҫ�����Ľڵ�������
		Node *rootNode = root;//ָ���ʼ���ڵ��ָ��
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

void BTree::inorder(Node *root)//����������
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->lchild);
	cout << root->val << " ";
	inorder(root->rchild);
}
void BTree::preorder(Node *rootNode) //����������
{
	if (rootNode == NULL)
	{
		return;
	}
	cout << rootNode->val << " ";
	preorder(rootNode->lchild);
	preorder(rootNode->rchild);
}
void BTree::postorder(Node *root)//����������
{
	if (root==NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->val << " ";
}

Node* BTree:: searchNode(Node *root, int key)//�ڶ���������������keyֵ
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
Node* BTree::destroyTree(Node *root)//�ݻٲ��ͷ���
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

void BTree::layerorder(Node* root)//�������������
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
