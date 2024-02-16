#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[])
//minKey 函数：该函数用于找到 key 数组中值最小且还未包括在最小生成树中的顶点。该函数返回这个顶点的索引。
 {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V])
//printMST 函数：用于打印最小生成树的边和权值。
 {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
//primMST 函数：Prim's 算法的实现。在该函数中，首先初始化三个数组，parent 用于存储最小生成树中每个顶点的父节点，
//key 用于存储从最小生成树中的某个顶点到其他顶点的权值，mstSet 用于标记顶点是否已经包括在最小生成树中。
{
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() 
//主函数 main：创建一个图的邻接矩阵，并调用 primMST 函数来计算最小生成树并打印结果
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
