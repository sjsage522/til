#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int id;
    int avail;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// ���� �Լ�
HeapType *create() {
    return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ �Լ�
void init(HeapType *h) {
    h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �߰��Ѵ�.
// ���� �Լ�
void insert_min_heap(HeapType *h, element item) {
    int i;
    i = ++(h->heap_size);

    // Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
    while((i != 1) && (item.avail < h->heap[i/2].avail)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item; // ���ο� ��带 ����
}

// ���� �Լ�
element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size) {
        // ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
        if((child < h->heap_size) && (h->heap[child].avail > h->heap[child + 1].avail))
            child++;
        if(temp.avail < h->heap[child].avail) break;
        // �� �ܰ� �Ʒ��� �̵�
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

#define JOBS 7
#define MACHINES 3

int main() {
    int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 };   // �۾��� ���ĵǾ� �ִٰ� ����
    element m = { 0, 0 };
    HeapType *h;
    init(h);

    // ���⼭ avail ���� ��谡 ��� �����ϰ� �Ǵ� �ð��̴�.
    for (int i=0; i<MACHINES; i++) {
        m.id = i+1;
        m.avail = 0;
        insert_min_heap(h, m);
    }
    // �ּ� �������� ��踦 ������ �۾��� �Ҵ��ϰ� ��밡�� �ð��� ���� ��Ų �Ŀ�
    // �ٽ� �ּ� ������ �߰��Ѵ�.
    for (int i=0; i<JOBS; i++) {
        m = delete_min_heap(h);
        printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ��Ѵ�.\n", i, m.avail, m.avail + jobs[i]-1, m.id);
        m.avail += jobs[i];
        insert_min_heap(h, m);
    }
    return 0;
}