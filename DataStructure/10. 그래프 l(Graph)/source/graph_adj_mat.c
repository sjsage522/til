#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct _GraphType {
    int n;      // ������ ����
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ
void init(GraphType *g) {
    int r, c;
    g->n = 0;
    for(r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// ���� ���� ����
void insert_vertax(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
        return;
    }
    g->n++;
}

// ���� ���� ����
void insert_edge(GraphType *g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "�׷��� : ���� ��ȣ ����");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// ���� ��� ��� �Լ�
void print_adj_mat(GraphType *g) {
    for(int i=0; i<g->n; i++) {
        for(int j=0; j<g->n; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4; i++)
        insert_vertax(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    print_adj_mat(g);

    free(g);
    return 0;
}