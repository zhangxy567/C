#include <stdio.h>
#include <limits.h>

#define V 8  // ������

// ����ͼ���ڽӾ���
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

// Prim�㷨������С������
void primMST() {
    // ... (ͬ��)

    // �����С�������ı�
    printf("Prim�㷨���ɵ���С��������:\n");
    for (int i = 1; i < V; i++) {
        printf("Edge: %c - %c, Weight: %d\n", parent[i] + 'A', i + 'A', graph[i][parent[i]]);
    }
}

// ����A�������������������ľ���
void calculateDistancesFromA() {
    printf("A�������������������ľ���:\n");
    for (int i = 1; i < V; i++) {
        printf("Distance from A to %c: %d\n", i + 'A', graph[0][i]);
    }
}

// ����DAGͼ������������͹ؼ�·��
void buildDAGAndTopologicalSort() {
    // TODO: ʵ�ֹ���DAGͼ����������͹ؼ�·���Ĺ���
}

int main() {
    // ����Prim�㷨
    primMST();

    // ����A�������������������ľ���
    calculateDistancesFromA();

    // ����DAGͼ������������͹ؼ�·��
    buildDAGAndTopologicalSort();

    return 0;
}
