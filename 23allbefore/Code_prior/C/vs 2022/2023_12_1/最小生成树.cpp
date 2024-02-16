#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[])
//minKey �������ú��������ҵ� key ������ֵ��С�һ�δ��������С�������еĶ��㡣�ú���������������������
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
//printMST ���������ڴ�ӡ��С�������ıߺ�Ȩֵ��
 {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
//primMST ������Prim's �㷨��ʵ�֡��ڸú����У����ȳ�ʼ���������飬parent ���ڴ洢��С��������ÿ������ĸ��ڵ㣬
//key ���ڴ洢����С�������е�ĳ�����㵽���������Ȩֵ��mstSet ���ڱ�Ƕ����Ƿ��Ѿ���������С�������С�
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
//������ main������һ��ͼ���ڽӾ��󣬲����� primMST ������������С����������ӡ���
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
