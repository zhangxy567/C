#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[])
//minDistance 函数：该函数用于找到距离数组 dist[] 中的最小值，
//其中 sptSet[] 表示已经包括在最短路径树中的顶点。函数通过遍历所有顶点，找到未包含在最短路径树中的顶点中距离最小的一个。
 {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[]) 
//printSolution 函数：该函数用于打印最终计算得到的最短路径结果。它将每个顶点和其对应的最短距离打印出来
{
    printf("Vertex \tDistance\n");
    for (int i = 0; i < V; i++)
        printf("%d \t%d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) 
//dijkstra 函数：这是实际的 Dijkstra 算法函数。它初始化距离数组 dist[] 和最短路径树集合 sptSet[]，
//然后通过迭代更新最短路径信息，直到所有顶点都包含在最短路径树中。在每次迭代中，它选择一个顶点（u）并更新与其相邻的顶点的最短路径。
{
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist);
}

int main()
//main 函数：在这里，定义了一个带有权重的图 graph，并调用了 dijkstra 函数来计算从源点0到其他顶点的最短路径。
 {
    int graph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 2, 5, 0},
        {0, 2, 0, 0, 4},
        {0, 5, 0, 0, 3},
        {0, 0, 4, 3, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
