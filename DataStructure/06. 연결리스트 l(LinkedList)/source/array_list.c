#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 // ����Ʈ�� �ִ� ũ��

typedef int element;      // �׸��� ����
typedef struct {
    element array[MAX_LIST_SIZE]; // �迭 ����
    int size;                     // ���� ����Ʈ�� ����� �׸���� ����
} ArraryListType;

// ���� ó�� �Լ�
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArraryListType *L) {
    L->size = 0;
}

// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArraryListType *L) {
    return (L->size == 0);
}

// ����Ʈ�� ���� �������� 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_full(ArraryListType *L) {
    return (L->size == MAX_LIST_SIZE);
}

element get_entry(ArraryListType *L, int pos) {
    if(pos < 0 || pos >= L->size)
        error("��ġ ����");
    return L->array[pos];
}

// ����Ʈ ���
void print_list(ArraryListType *L) {
    int i;
    for(i = 0; i<L->size; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}

void insert_last(ArraryListType *L, element item) {
    if(L->size >= MAX_LIST_SIZE) {
        error("����Ʈ �����÷ο�");
    }
    L->array[L->size++] = item;
}

void insert(ArraryListType *L, int pos, element item) {
    if(!is_full(L) && pos >= 0 && pos <= L->size) {
        for(int i=(L->size - 1); i >= pos; i--) {
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

element delete(ArraryListType *L, int pos) {
    element item;

    if(pos < 0 || pos >= L->size) 
        error("��ġ ����");
    item = L->array[pos];
    for(int i = pos; i < (L->size - 1); i++) {
        L->array[i] = L->array[i+1];
    }
    L->size--;
    return item;
}

int main() {
    // ArrayListType�� �������� �����ϰ� ArrayListType��
    // ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
    ArraryListType list;

    init(&list);
    insert(&list, 0, 10);  print_list(&list);
    insert(&list, 0, 20);  print_list(&list);
    insert(&list, 0, 30);  print_list(&list);
    insert_last(&list, 40);print_list(&list);
    delete(&list, 0);      print_list(&list);
}