#include <stdio.h>
#include <stdlib.h>

struct Node 
//Node �ṹ�壺��ʾͼ�е�ÿ���ڵ㣬����һ�����ݳ�Ա data ��ʾ�ڵ��ֵ���Լ�һ��ָ����һ���ڵ��ָ�� next��
{
    int data;
    struct Node* next;
};

struct Graph
//Graph �ṹ�壺��ʾ����ͼ������������ V ��һ��ָ��ڵ������ָ�� array���ڵ������е�ÿ��Ԫ����һ��������ʾ��ö������ڵ��������㡣
 {
    int V;
    struct Node** array;
};

struct Node* createNode(int data) 
//createNode ���������ڴ���һ���µĽڵ�
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) 
//createGraph ���������ڴ���һ���µ�ͼ����ʼ�����������ڽӱ�
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) 
//addEdge ������������ͼ�����һ���ߡ�
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}

void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Node** stack, int* stackIndex) 
//topologicalSortUtil �����������������ʵ��ʵ�֡����ݹ�ر���ͼ�еĶ��㣬��δ���ʵĶ������ջ�С�
{
    visited[v] = 1;
    struct Node* temp = graph->array[v];
    while (temp != NULL) {
        if (!visited[temp->data])
            topologicalSortUtil(graph, temp->data, visited, stack, stackIndex);
        temp = temp->next;
    }
    stack[*stackIndex] = createNode(v);
    (*stackIndex)++;
}

void topologicalSort(struct Graph* graph)
//topologicalSort ���������ڳ�ʼ���������鲢���� topologicalSortUtil ��������������󣬴�ӡ������������
 {
    int V = graph->V;
    int visited[V];
    struct Node** stack = (struct Node**)malloc(V * sizeof(struct Node*));
    int stackIndex = 0;

    for (int i = 0; i < V; ++i)
        visited[i] = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
    }

    printf("Topological Sort:\n");
    while (stackIndex > 0) {
        stackIndex--;
        printf("%d ", stack[stackIndex]->data);
        free(stack[stackIndex]);
    }

    free(stack);
}

int main() 
//main ����������һ������ͼ������ӱߡ�Ȼ����� topologicalSort ���������������򣬲���ӡ��������
{
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
