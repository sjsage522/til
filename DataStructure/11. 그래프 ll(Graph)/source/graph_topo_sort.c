#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FLASE 0
#define MAX_VERTICES 50

typedef struct _GraphNode {
    int vertex;
    struct _GraphNode *link;
} GraphNode;

typedef struct _GraphType {
    int n; // ������ ����
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ
void graph_init(GraphType *g) {
    int v;
    g->n = 0;
    for(v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}
// ���� ���� ����
void insert_vertex(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "�׷��� : ���� ���� �ʰ�");
        return;
    } 
    g->n++;
}
// ���� ���� ����
void insert_edge(GraphType *g, int u, int v) {
    GraphNode *node;
    if(u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷��� : ���� ��ȣ ����");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType *s) {
    s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType *s) {
    return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

// �������� ����.
int topo_sort(GraphType *g) {
    int i;
    StackType s;
    GraphNode *node;

    // ��� ������ ���� ������ ���
    int *in_degree = (int*)malloc(g->n * sizeof(int));
    for(i=0; i<g->n; i++)                   // �ʱ�ȭ   
        in_degree[i] = 0;
    for(i=0; i<g->n; i++) {
        node = g->adj_list[i];   // ���� i���� ������ ������
        while(node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    // ���� ������ 0�� ������ ���ÿ� ����
    init(&s);
    for(i=0; i<g->n; i++) {
        if(in_degree[i] == 0) push(&s, i);
    }

    // ���� ������ ����
    while(!is_empty(&s)) {
        int w;
        w = pop(&s);
        printf("���� %d ->", w); // ���� ���
        node = g->adj_list[w];   // �� ������ ���������� ����
        while(node != NULL) {
            int u = node->vertex;
            in_degree[u]--;      // ���� ������ ����
            if(in_degree[u] == 0) push(&s, u);
            node = node->link;
        }
    }
    free(in_degree);
    printf("\n");
    return (i==g->n);           // ��ȯ���� 1�̸� ����, 0�̸� ����
}
 int main() {
     GraphType g;
     graph_init(&g);
     insert_vertex(&g, 0);
     insert_vertex(&g, 1);
     insert_vertex(&g, 2);
     insert_vertex(&g, 3);
     insert_vertex(&g, 4);
     insert_vertex(&g, 5);

     // ���� 0�� ���� ����Ʈ ����
     insert_edge(&g, 0, 2);
     insert_edge(&g, 0, 3);
     // ���� 1�� ���� ����Ʈ ����
     insert_edge(&g, 1, 3);
     insert_edge(&g, 1, 4);
     // ���� 2�� ���� ����Ʈ ����
     insert_edge(&g, 2, 3);
     insert_edge(&g, 2, 5);
     // ���� 3�� ���� ����Ʈ ����
     insert_edge(&g, 3, 5);
     // ���� 4�� ���� ����Ʈ ����
     insert_edge(&g, 4, 5);
     // ���� ����
     topo_sort(&g);
     // ���� �޸� ��ȯ �ڵ� ����
     return 0;
 }