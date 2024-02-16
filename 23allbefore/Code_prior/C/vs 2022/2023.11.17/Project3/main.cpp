#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define QUEUE_SIZE 5//队列空间大小 
/*二叉树的二叉链式存储表示*/
typedef struct BTNode {
	char element;
	struct BTNode* leftChild;
	struct BTNode* rightChild;
}BTNode, * BTNodePtr;
/*二叉树队列的表示*/
typedef struct BTNodeQueue {
	BTNodePtr* nodePtrs; //队列里存放的是二叉树结点的地址
	int front;
	int rear;
}BTNodeQueue, * BTNodeQueuePtr;
/*二叉树队列的初始化(QueuePtr及其成员的空间分配及赋初值)*/
BTNodeQueuePtr initQueue() {
	BTNodeQueuePtr QueuePtr = (BTNodeQueuePtr)malloc(sizeof(struct BTNodeQueue));
	QueuePtr->nodePtrs = (BTNodePtr*)malloc(QUEUE_SIZE * sizeof(struct BTNode));//队列的空间用来存二叉树结点的地址
	QueuePtr->front = 0;
	QueuePtr->rear = 1;
	return QueuePtr;
}
/*判断是否队空（bool）*/
bool isQueueEmpty(BTNodeQueuePtr paraQueue) {
	if ((paraQueue->front + 1) % QUEUE_SIZE == paraQueue->rear) {
		return true;
	}
	return false;
}
/*结点指针入队(传两个参数：QueuePtr、NodePtr)*/
void enqueue(BTNodeQueuePtr paraQueue, BTNodePtr paraBTNodePtr) {
	//判断队列是否已满
	if ((paraQueue->rear + 1) % QUEUE_SIZE == paraQueue->front % QUEUE_SIZE) {
		printf("The queue is full.Cannot enqueue data %c.\r\n", paraBTNodePtr->element);
	}
	//结点指针入队
	paraQueue->nodePtrs[paraQueue->rear] = paraBTNodePtr;
	paraQueue->rear = (paraQueue->rear + 1) % QUEUE_SIZE;
	printf("%c has enqueued.\r\n", paraBTNodePtr->element);
}
/*结点指针出队*/
BTNodePtr dequeue(BTNodeQueuePtr paraQueue) {
	//判断队列是否为空
	if (paraQueue->front == paraQueue->rear) {
		printf("The queue is empty.Cannot dequeue element.\r\n");
		return NULL;
	}
	//结点指针出队
	paraQueue->front = (paraQueue->front + 1) % QUEUE_SIZE;//front最初指向出队元素的前面的一个位置，现在让front指向出队指针 
	printf("dequeue %c ends.\r\n", paraQueue->nodePtrs[paraQueue->front]->element);
	return paraQueue->nodePtrs[paraQueue->front];
}
/*创建二叉树结点*/
BTNodePtr constructBTNode(char parachar) {
	BTNodePtr tempNode = (BTNodePtr)malloc(sizeof(struct BTNode));
	tempNode->element = parachar;
	tempNode->leftChild = NULL;
	tempNode->rightChild = NULL;
	return tempNode;
}
/*用给定字符串创建二叉树*/
BTNodePtr stringToBTree(char* paraString) {
	int i, ch;
	//初始化指针队列 
	BTNodeQueuePtr tempQueue = initQueue();
	//头结点指针入队 
	BTNodePtr Header, tempParent, tempLeftChild, tempRightChild;
	i = 0; ch = paraString[i]; Header = constructBTNode(ch);
	enqueue(tempQueue, Header);
	//创建子树 
	while (!isQueueEmpty(tempQueue)) {
		tempParent = dequeue(tempQueue);
		//leftchild 
		i++; ch = paraString[i];
		if (ch == '#') {
			tempParent->leftChild = NULL;
		}
		else {
			tempLeftChild = constructBTNode(ch);
			enqueue(tempQueue, tempLeftChild);
			tempParent->leftChild = tempLeftChild;
		}
		//rightchild
		i++; ch = paraString[i];
		if (ch == '#') {
			tempParent->rightChild = NULL;
		}
		else {
			tempRightChild = constructBTNode(ch);
			enqueue(tempQueue, tempRightChild);
			tempParent->rightChild = tempRightChild;
		}
	}//Of while
	return Header;
}
/*层次遍历（队列）（while循环）*/
void levelwise(BTNodePtr paraTreePtr) {
	BTNodePtr tempNodePtr;//接受出队的结点指针 
	int i = 0; char tempString[100];//将结点的字符依次保存在字符串中，方便输出 
	//初始化队列存储结点指针
	BTNodeQueuePtr tempQueue = initQueue();
	enqueue(tempQueue, paraTreePtr);
	while (!isQueueEmpty(tempQueue)) {
		tempNodePtr = dequeue(tempQueue);
		tempString[i] = tempNodePtr->element;
		i++;
		if (tempNodePtr->leftChild != NULL) {
			enqueue(tempQueue, tempNodePtr->leftChild);
		}
		if (tempNodePtr->rightChild != NULL) {
			enqueue(tempQueue, tempNodePtr->rightChild);
		}
	}
	tempString[i] == '\0';
	printf("Levelwise:%s\r\n", tempString);
}
/*先序遍历（递归）*/
void preOrder(BTNodePtr tempPtr) {
	if (tempPtr == NULL) {
		return;
	}
	printf("%c", tempPtr->element);
	preOrder(tempPtr->leftChild);
	preOrder(tempPtr->rightChild);
}
/*中序遍历（递归）*/
void inOrder(BTNodePtr tempPtr) {
	if (tempPtr == NULL) {
		return;
	}
	inOrder(tempPtr->leftChild);
	printf("%c", tempPtr->element);
	inOrder(tempPtr->rightChild);
}
/*后序遍历（递归）*/
void poOrder(BTNodePtr tempPtr) {
	if (tempPtr == NULL) {
		return;
	}
	poOrder(tempPtr->leftChild);
	poOrder(tempPtr->rightChild);
	printf("%c", tempPtr->element);
}
int main() {
	BTNodePtr tempHeader;//保存根节点 
	//单个字符 
	tempHeader = constructBTNode('c');
	printf("There is only one node.preOrder visit:\r\n");
	preOrder(tempHeader);
	printf("\r\n");
	//字符串
	printf("---- the stringToBTree begins. ----\r\n");
	char* tempString = "acde#bf######";
	tempHeader = stringToBTree(tempString);
	printf("---- the stringToBTree ends. ----\r\n");
	printf("---- traversal begins, ----\r\n");
	printf("preOrder:");
	preOrder(tempHeader);
	printf("\r\n");
	printf("inOrder:");
	inOrder(tempHeader);
	printf("\r\n");
	printf("poOrder:");
	poOrder(tempHeader);
	printf("\r\n");
	printf("Levelwise：\r\n");
	levelwise(tempHeader);
	printf("---- traversal ends, ----\r\n");
	return 0;
}