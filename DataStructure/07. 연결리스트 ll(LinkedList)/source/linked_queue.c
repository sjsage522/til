#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
} node;

void init(node *head) {
    head->data = 1;
    head->next = head;
    head->prev = head;
}

void insert(node *head, int person) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = person;
    newnode->prev = head;
    newnode->next = head->next;
    head->next->prev = newnode;
    head->next = newnode;
}

node* delete(node *head, node *removed) {
    node *tmp = removed->next;
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    free(removed);
    return tmp;
}

void Josephus(node *head, int K) {
    node *p = head;
    printf("<");
    while(p->next != p) {
        int n = K-1;
        while(n--) {
            p = p->next;
        }
        printf("%d, ", p->data);
        p = delete(head, p);
    }
    printf("%d>", p->data);
}

int main() {
    node *head = (node*)malloc(sizeof(node));
    init(head);
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=N; i>=2; i--) {
        insert(head, i);
    }
    Josephus(head ,K);
}