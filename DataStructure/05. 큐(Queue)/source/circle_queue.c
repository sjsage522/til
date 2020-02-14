#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ( (q->rear + 1) % MAX_QUEUE_SIZE == q->front );
}

void queue_print(QueueType *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element item) {
    if(is_full(q))
        error("queue is full.\n");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if(is_empty(q))
        error("queue is empty.\n");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q) {
    if(is_empty(q))
        error("queue is empty.\n");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q) {
    return (q->rear - q->front); 
}

int main() {
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--������ �߰� �ܰ�--\n");
    while(!is_full(&queue)) {
        printf("������ �Է��Ͻÿ�: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("count : %d, queue is full.\n", get_count(&queue));

    printf("--������ ���� �ܰ�--\n");
    while(!is_empty(&queue)) {
        element = dequeue(&queue);
        printf("������ ���� : %d \n", element);
        queue_print(&queue);
    }
    printf("ť�� ��������Դϴ�.\n");
}
