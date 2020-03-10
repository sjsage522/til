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
    int n; // 정점의 개수
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화
void graph_init(GraphType *g) {
    int v;
    g->n = 0;
    for(v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프 : 정점 개수 초과");
        return;
    } 
    g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType *g, int u, int v) {
    GraphNode *node;
    if(u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프 : 정점 번호 오류");
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

// 스택 초기화 함수
void init(StackType *s) {
    s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

// 위상정렬 수행.
int topo_sort(GraphType *g) {
    int i;
    StackType s;
    GraphNode *node;

    // 모든 정점의 진입 차수를 계산
    int *in_degree = (int*)malloc(g->n * sizeof(int));
    for(i=0; i<g->n; i++)                   // 초기화   
        in_degree[i] = 0;
    for(i=0; i<g->n; i++) {
        node = g->adj_list[i];   // 정점 i에서 나오는 간선들
        while(node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    // 진입 차수가 0인 정점을 스택에 삽입
    init(&s);
    for(i=0; i<g->n; i++) {
        if(in_degree[i] == 0) push(&s, i);
    }

    // 위상 순서를 생성
    while(!is_empty(&s)) {
        int w;
        w = pop(&s);
        printf("정점 %d ->", w); // 정점 출력
        node = g->adj_list[w];   // 각 정점의 진입차수를 변경
        while(node != NULL) {
            int u = node->vertex;
            in_degree[u]--;      // 진입 차수를 감소
            if(in_degree[u] == 0) push(&s, u);
            node = node->link;
        }
    }
    free(in_degree);
    printf("\n");
    return (i==g->n);           // 반환값이 1이면 성공, 0이면 실패
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

     // 정점 0의 인접 리스트 생성
     insert_edge(&g, 0, 2);
     insert_edge(&g, 0, 3);
     // 정점 1의 인접 리스트 생성
     insert_edge(&g, 1, 3);
     insert_edge(&g, 1, 4);
     // 정점 2의 인접 리스트 생성
     insert_edge(&g, 2, 3);
     insert_edge(&g, 2, 5);
     // 정점 3의 인접 리스트 생성
     insert_edge(&g, 3, 5);
     // 정점 4의 인접 리스트 생성
     insert_edge(&g, 4, 5);
     // 위상 정렬
     topo_sort(&g);
     // 동적 메모리 반환 코드 생략
     return 0;
 }