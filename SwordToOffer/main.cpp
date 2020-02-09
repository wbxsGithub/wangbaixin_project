#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BTree.h"
using namespace std;
int main()
{
	vector<int> arr = { 5, 3, 7, 9, 8, 2, 1, 6, 4 };
	
	BTree bt;//��������Ķ���
	bt.buildBinaryTree(arr);//��������������
	Node *root = bt.getRoot();
#pragma region //�ȡ��С������������

	bt.preorder(root);
	cout << endl;

	bt.inorder(root);
	cout << endl;
	
	bt.postorder(root);
	cout << endl;

#pragma endregion 
	bt.layerorder(root);
//#pragma region //��keyֵ
//	cout << "����keyֵ,�������lchild��val:" << endl;
//	Node *node = bt.searchNode(root, 3);
//	cout << node->lchild->val << endl;
//#pragma endregion 
//	cout << bt.max(root)<<endl;
//	cout << bt.min(root) << endl;
//	bt.destroyTree(root);
	return 0;
}