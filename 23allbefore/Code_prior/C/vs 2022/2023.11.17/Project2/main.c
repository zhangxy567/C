#include "BinaryTreeNode.h"
int main() {
	DataType arr[] = { 1, 2, 3, 0, 0, 0, 4, 5, 0, 0, 6 };
	BTNode* root = CreatBinaryTree(arr, sizeof(arr) / sizeof(arr[0]), -1);
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("二叉树节点个数为:%d\n", BinaryTreeSize(root));
	printf("二叉树叶子节点个数为:%d\n", BinaryTreeLeafSize(root));
	printf("二叉树第3层节点个数为:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("二叉树深度为:%d\n", Depth(root));
	BinaryTreeDestory(&root);
	system("pause");
	return 0;
}