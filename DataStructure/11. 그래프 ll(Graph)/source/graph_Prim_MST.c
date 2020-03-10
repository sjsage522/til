#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct _GraphType {
    int n;      // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES] = {FALSE};
int distance[MAX_VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
    int v, i;
    for (i=0; i<n; i++)
        if(!selected[i]) {
            v = i;
            break;
        }
    for (i=0; i<n; i++)
        if(!selected[i] && (distance[i] < distance[v])) v = i;
    return v;
}

void prim(GraphType *g, int s) {
    int i, u, v;
    for (u=0; u<g->n; u++)
        distance[u] = INF;
    distance[s] = 0;
    for (i=0; i<g->n; i++) {
        u = get_min_vertex(g->n);
        selected[u] = TRUE;
        if (distance[u] == INF) return;
        printf("정점 %d 추가\n", u);
        for (v=0; v<g->n; v++)
            if(g->weight[u][v] != INF)
                if(!selected[v] && g->weight[u][v] < distance[v])
                    distance[v] = g->weight[u][v];
    }
}

int main() {
    GraphType g = { 7,
    { {0, 29, INF, INF, INF, 10, INF},  // a : 0
      {29, 0, 16, INF, INF, INF, 15},   // b : 1
      {INF, 16, 0, 12, INF, INF, INF},  // c : 2
      {INF, INF, 12, 0, 22, INF, 18},   // d : 3
      {INF, INF, INF, 22, 0, 27, 25},   // e : 4
      {10, INF, INF, INF, 27, 0, INF},  // f : 5
      {INF, 15, INF, 18, 25, INF, 0} }  // g : 6
    };
    prim(&g, 0);                        // a->f->e->d->c->b->g
    return 0;
}