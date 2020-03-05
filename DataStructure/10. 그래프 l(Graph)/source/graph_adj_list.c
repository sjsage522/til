#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct _GraphNode {
    int vertex;
    struct _GraphNode *link;
} GraphNode;

typedef struct _GraphType {
    int n;      // ������ ����
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ
void init(GraphType *g) {
    int v;
    g->n = 0;
    for(v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// ���� ���� ����
void insert_vertax(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES ) {
        fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
        return;
    } 
    g->n++;
}

// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void inset_edge(GraphType *g, int u, int v) {
    GraphNode *node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷��� : ���� ��ȣ ����");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType *g) {
    for(int i=0; i<g->n; i++) {
        GraphNode *p = g->adj_list[i];
        printf("���� %d�� ���� ����Ʈ ", i);
        while(p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
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
    inset_edge(g, 0, 1);
    inset_edge(g, 1, 0);
    inset_edge(g, 0, 2);
    inset_edge(g, 2, 0);
    inset_edge(g, 0, 3);
    inset_edge(g, 3, 0);
    inset_edge(g, 1, 2);
    inset_edge(g, 2, 1);
    inset_edge(g, 2, 3);
    inset_edge(g, 3, 2);
    print_adj_list(g);
    free(g);
    return 0;
}