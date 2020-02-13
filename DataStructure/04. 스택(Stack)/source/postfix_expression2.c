#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
    element *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(sizeof(element) * s->capacity);
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (s->capacity - 1));
}

void push(StackType *s, element item) {
    if(is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, sizeof(element) * s->capacity);
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    return s->data[(s->top)];    
}

// �����ڵ��� �켱������ ��ȯ�Ѵ�.
int prec(char op) {
    switch(op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2; 
    }
    return -1;
}

// ���� ǥ�� ���� -> ���� ǥ�� ����
void infix_to_postfix(char exp[]) {
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for(i=0; i<len; i++) {
        ch = exp[i];
        switch(ch) {
            case '+': case '-': case '*': case '/': case '%': // ������
                // ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
                while(!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                    printf("%c", pop(&s));
                push(&s, ch);
                break;
            case '(': // ���� ��ȣ
                push(&s, ch);
                break;
            case ')': // ������ ��ȣ
                top_op = pop(&s);
                // ���� ��ȣ�� ���������� ���
                while(top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default: // �ǿ�����
                printf("%c", ch);
                break;
        }
    }
    while(is_empty(&s)) // ���ÿ� ����� �����ڵ� ���
        printf("%c", pop(&s));
}

int main() {
    char *s = "(2+3)*4+9";
    printf("����ǥ����� %s \n", s);
    printf("����ǥ����� ");
    infix_to_postfix(s);
    printf("\n");
}