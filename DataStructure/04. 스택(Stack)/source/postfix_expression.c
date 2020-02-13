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

// ���� ǥ�� ���� ��� �Լ�
int eval(char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);
    for(i=0; i<len; i++) {
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0'; // �Է��� �ǿ������̸�
            push(&s, value);
        }
        else {                // �������̸� �ǿ����ڸ� ���ÿ��� ����
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    int result;
    printf("����ǥ������� 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("������� %d\n", result);
}