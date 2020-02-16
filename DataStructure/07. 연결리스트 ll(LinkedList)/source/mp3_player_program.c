#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

DListNode* current;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead) {
    DListNode* p;
    for(p = phead->rlink; p != phead; p = p->rlink) {
        if(p == current)
            printf("<-| #%s# |-> ", p->data);
        else
            printf("<- | %s |-> ", p->data);
    }
    printf("\n");
}

// ��� newnode�� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode *before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    strcpy(newnode->data, data);
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// ��� removed�� �����Ѵ�.
void ddelete(DListNode *head, DListNode *removed) {
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main() {
    char ch;
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");

    current = head->rlink;
    print_dlist(head);

    do {
        printf("\n��ɾ �Է��Ͻÿ�(<, >, q): ");
        ch = getchar();
        if(ch == '<') {
            current = current->llink;
            if(current == head)
                current = current->llink;
        }
        else if(ch == '>') {
            current = current->rlink;
            if(current == head)
                current = current->rlink;
        }
        print_dlist(head);
        getchar();
    } while (ch != 'q');
}