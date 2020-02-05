#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BTree.h"
using namespace std;
int main()
{
	vector<int> arr = { 5, 3, 7, 9, 8, 2, 1, 6, 4 };
	
	BTree bt;//创建该类的对象
	bt.buildBinaryTree(arr);//创建二叉搜索树
	Node *root = bt.getRoot();
#pragma region //先、中、后遍历二叉树

	bt.preorder(root);
	cout << endl;

	bt.inorder(root);
	cout << endl;
	
	bt.postorder(root);
	cout << endl;

#pragma endregion 
	bt.layerorder(root);
//#pragma region //找key值
//	cout << "查找key值,并输出其lchild的val:" << endl;
//	Node *node = bt.searchNode(root, 3);
//	cout << node->lchild->val << endl;
//#pragma endregion 
//	cout << bt.max(root)<<endl;
//	cout << bt.min(root) << endl;
//	bt.destroyTree(root);
	return 0;
}