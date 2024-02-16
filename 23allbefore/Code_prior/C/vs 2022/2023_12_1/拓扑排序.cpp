#include <stdio.h>
#include <stdlib.h>

struct Node 
//Node 结构体：表示图中的每个节点，包含一个数据成员 data 表示节点的值，以及一个指向下一个节点的指针 next。
{
    int data;
    struct Node* next;
};

struct Graph
//Graph 结构体：表示有向图，包含顶点数 V 和一个指向节点数组的指针 array。节点数组中的每个元素是一个链表，表示与该顶点相邻的其他顶点。
 {
    int V;
    struct Node** array;
};

struct Node* createNode(int data) 
//createNode 函数：用于创建一个新的节点
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) 
//createGraph 函数：用于创建一个新的图，初始化顶点数和邻接表。
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) 
//addEdge 函数：用于向图中添加一条边。
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}

void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Node** stack, int* stackIndex) 
//topologicalSortUtil 函数：是拓扑排序的实际实现。它递归地遍历图中的顶点，将未访问的顶点加入栈中。
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
//topologicalSort 函数：用于初始化访问数组并调用 topologicalSortUtil 进行拓扑排序。最后，打印拓扑排序结果。
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
//main 函数：创建一个有向图，并添加边。然后调用 topologicalSort 函数进行拓扑排序，并打印排序结果。
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
