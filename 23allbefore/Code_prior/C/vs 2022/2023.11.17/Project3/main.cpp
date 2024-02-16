#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define QUEUE_SIZE 5//���пռ��С 
/*�������Ķ�����ʽ�洢��ʾ*/
typedef struct BTNode {
	char element;
	struct BTNode* leftChild;
	struct BTNode* rightChild;
}BTNode, * BTNodePtr;
/*���������еı�ʾ*/
typedef struct BTNodeQueue {
	BTNodePtr* nodePtrs; //�������ŵ��Ƕ��������ĵ�ַ
	int front;
	int rear;
}BTNodeQueue, * BTNodeQueuePtr;
/*���������еĳ�ʼ��(QueuePtr�����Ա�Ŀռ���估����ֵ)*/
BTNodeQueuePtr initQueue() {
	BTNodeQueuePtr QueuePtr = (BTNodeQueuePtr)malloc(sizeof(struct BTNodeQueue));
	QueuePtr->nodePtrs = (BTNodePtr*)malloc(QUEUE_SIZE * sizeof(struct BTNode));//���еĿռ���������������ĵ�ַ
	QueuePtr->front = 0;
	QueuePtr->rear = 1;
	return QueuePtr;
}
/*�ж��Ƿ�ӿգ�bool��*/
bool isQueueEmpty(BTNodeQueuePtr paraQueue) {
	if ((paraQueue->front + 1) % QUEUE_SIZE == paraQueue->rear) {
		return true;
	}
	return false;
}
/*���ָ�����(������������QueuePtr��NodePtr)*/
void enqueue(BTNodeQueuePtr paraQueue, BTNodePtr paraBTNodePtr) {
	//�ж϶����Ƿ�����
	if ((paraQueue->rear + 1) % QUEUE_SIZE == paraQueue->front % QUEUE_SIZE) {
		printf("The queue is full.Cannot enqueue data %c.\r\n", paraBTNodePtr->element);
	}
	//���ָ�����
	paraQueue->nodePtrs[paraQueue->rear] = paraBTNodePtr;
	paraQueue->rear = (paraQueue->rear + 1) % QUEUE_SIZE;
	printf("%c has enqueued.\r\n", paraBTNodePtr->element);
}
/*���ָ�����*/
BTNodePtr dequeue(BTNodeQueuePtr paraQueue) {
	//�ж϶����Ƿ�Ϊ��
	if (paraQueue->front == paraQueue->rear) {
		printf("The queue is empty.Cannot dequeue element.\r\n");
		return NULL;
	}
	//���ָ�����
	paraQueue->front = (paraQueue->front + 1) % QUEUE_SIZE;//front���ָ�����Ԫ�ص�ǰ���һ��λ�ã�������frontָ�����ָ�� 
	printf("dequeue %c ends.\r\n", paraQueue->nodePtrs[paraQueue->front]->element);
	return paraQueue->nodePtrs[paraQueue->front];
}
/*�������������*/
BTNodePtr constructBTNode(char parachar) {
	BTNodePtr tempNode = (BTNodePtr)malloc(sizeof(struct BTNode));
	tempNode->element = parachar;
	tempNode->leftChild = NULL;
	tempNode->rightChild = NULL;
	return tempNode;
}
/*�ø����ַ�������������*/
BTNodePtr stringToBTree(char* paraString) {
	int i, ch;
	//��ʼ��ָ����� 
	BTNodeQueuePtr tempQueue = initQueue();
	//ͷ���ָ����� 
	BTNodePtr Header, tempParent, tempLeftChild, tempRightChild;
	i = 0; ch = paraString[i]; Header = constructBTNode(ch);
	enqueue(tempQueue, Header);
	//�������� 
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
/*��α��������У���whileѭ����*/
void levelwise(BTNodePtr paraTreePtr) {
	BTNodePtr tempNodePtr;//���ܳ��ӵĽ��ָ�� 
	int i = 0; char tempString[100];//�������ַ����α������ַ����У�������� 
	//��ʼ�����д洢���ָ��
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
/*����������ݹ飩*/
void preOrder(BTNodePtr tempPtr) {
	if (tempPtr == NULL) {
		return;
	}
	printf("%c", tempPtr->element);
	preOrder(tempPtr->leftChild);
	preOrder(tempPtr->rightChild);
}
/*����������ݹ飩*/
void inOrder(BTNodePtr tempPtr) {
	if (tempPtr == NULL) {
		return;
	}
	inOrder(tempPtr->leftChild);
	printf("%c", tempPtr->element);
	inOrder(tempPtr->rightChild);
}
/*����������ݹ飩*/
void poOrder(BTNodePtr tempPtr) {
	if (tempPtr == NULL) {
		return;
	}
	poOrder(tempPtr->leftChild);
	poOrder(tempPtr->rightChild);
	printf("%c", tempPtr->element);
}
int main() {
	BTNodePtr tempHeader;//������ڵ� 
	//�����ַ� 
	tempHeader = constructBTNode('c');
	printf("There is only one node.preOrder visit:\r\n");
	preOrder(tempHeader);
	printf("\r\n");
	//�ַ���
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
	printf("Levelwise��\r\n");
	levelwise(tempHeader);
	printf("---- traversal ends, ----\r\n");
	return 0;
}