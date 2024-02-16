#include <stdio.h>
#include <limits.h>

#define V 8  // 顶点数

// 定义图的邻接矩阵
int graph[V][V] = {
        {0, 2, 0, 6, 0, 0, 0, 0},
        {2, 0, 3, 8, 5, 0, 0, 0},
        {0, 3, 0, 0, 7, 9, 0, 0},
        {6, 8, 0, 0, 0, 0, 4, 0},
        {0, 5, 7, 0, 0, 0, 0, 1},
        {0, 0, 9, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 3},
        {0, 0, 0, 0, 1, 0, 3, 0}
};

// Prim算法生成最小生成树
void primMST() {
    // ... (同上)

    // 输出最小生成树的边
    printf("Prim算法生成的最小生成树边:\n");
    for (int i = 1; i < V; i++) {
        printf("Edge: %c - %c, Weight: %d\n", parent[i] + 'A', i + 'A', graph[i][parent[i]]);
    }
}

// 计算A居民区到其他居民区的距离
void calculateDistancesFromA() {
    printf("A居民区到其他居民区的距离:\n");
    for (int i = 1; i < V; i++) {
        printf("Distance from A to %c: %d\n", i + 'A', graph[0][i]);
    }
}

// 构建DAG图并求拓扑排序和关键路径
void buildDAGAndTopologicalSort() {
    // TODO: 实现构建DAG图、拓扑排序和关键路径的功能
}

int main() {
    // 调用Prim算法
    primMST();

    // 计算A居民区到其他居民区的距离
    calculateDistancesFromA();

    // 构建DAG图并求拓扑排序和关键路径
    buildDAGAndTopologicalSort();

    return 0;
}
