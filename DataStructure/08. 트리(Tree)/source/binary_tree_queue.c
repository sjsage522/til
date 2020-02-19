#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    int data;
    struct _TreeNode *left, *right;
} TreeNode;

// ================= 원형큐 코드 시작 =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType; 

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q) {
    return q->front == q->rear;
}

// 포화 상태 검출 함수
int is_full(QueueType *q) {
    return q->front == ( (q->rear + 1) % MAX_QUEUE_SIZE );
}

// 삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q))
        error("큐가 포화상태 입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)) 
        error("큐가 공백상태 입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void level_order(TreeNode *ptr) {
    QueueType q;

    init_queue(&q);

    if(ptr == NULL) return;

    enqueue(&q, ptr); 
    while(!is_empty(&q)) {
        ptr = dequeue(&q);
        printf(" [%d] ", ptr->data);
        if(ptr->left != NULL)
            enqueue(&q, ptr->left);
        if(ptr->right != NULL) 
            enqueue(&q, ptr->right);
    }
}

//          15
//  4                20
// 1               16  25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

int main() {
    printf("레벨 순회=");
    level_order(root);
    printf("\n");
}