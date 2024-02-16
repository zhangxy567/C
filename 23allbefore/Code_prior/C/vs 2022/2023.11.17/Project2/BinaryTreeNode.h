#pragma once
#include <stdio.h>
#include <windows.h>
#include <assert.h>
typedef int DataType;
typedef struct BinaryTreeNode {
	DataType data;
	struct BinaryTreeNode* left;//左孩子节点的地址
	struct BinaryTreeNode* right;//右孩子节点的地址
}BTNode;
extern BTNode* CreatBinaryTree(DataType* arr, int size, DataType invalid);
extern void PreOrder(BTNode* root);
extern void InOrder(BTNode* root);
extern void PostOrder(BTNode* root);
extern int BinaryTreeSize(BTNode* root);
extern int BinaryTreeLeafSize(BTNode* root);
extern int BinaryTreeLevelKSize(BTNode* root, int k);
extern BTNode* BinaryTreeFind(BTNode* root, DataType x);
extern int Depth(BTNode* root);
extern void BinaryTreeDestory(BTNode** root);
