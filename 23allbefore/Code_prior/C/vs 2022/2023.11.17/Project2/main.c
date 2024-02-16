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
	printf("�������ڵ����Ϊ:%d\n", BinaryTreeSize(root));
	printf("������Ҷ�ӽڵ����Ϊ:%d\n", BinaryTreeLeafSize(root));
	printf("��������3��ڵ����Ϊ:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("���������Ϊ:%d\n", Depth(root));
	BinaryTreeDestory(&root);
	system("pause");
	return 0;
}