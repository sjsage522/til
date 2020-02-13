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
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)];    
}

// 연산자들의 우선순위를 반환한다.
int prec(char op) {
    switch(op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2; 
    }
    return -1;
}

// 중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[]) {
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for(i=0; i<len; i++) {
        ch = exp[i];
        switch(ch) {
            case '+': case '-': case '*': case '/': case '%': // 연산자
                // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                while(!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                    printf("%c", pop(&s));
                push(&s, ch);
                break;
            case '(': // 왼쪽 괄호
                push(&s, ch);
                break;
            case ')': // 오른쪽 괄호
                top_op = pop(&s);
                // 왼쪽 괄호를 만날때가지 출력
                while(top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default: // 피연산자
                printf("%c", ch);
                break;
        }
    }
    while(is_empty(&s)) // 스택에 저장된 연산자들 출력
        printf("%c", pop(&s));
}

int main() {
    char *s = "(2+3)*4+9";
    printf("중위표기수식 %s \n", s);
    printf("후위표기수식 ");
    infix_to_postfix(s);
    printf("\n");
}