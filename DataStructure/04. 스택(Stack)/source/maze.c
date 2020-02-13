#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;
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

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' }
};
// 위치를 스택에 삽입
void push_loc(StackType *s, int r, int c) {
    if(r < 0 || c < 0) return;
    if(maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

// 미로를 화면에 출력한다.
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for(int r=0; r<MAZE_SIZE; r++) {
        for(int c=0; c<MAZE_SIZE; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    StackType s;

    init_stack(&s);
    here = entry;
    while(maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r-1, c);
        push_loc(&s, r+1, c);
        push_loc(&s, r, c-1);
        push_loc(&s, r, c+1);
        if(is_empty(&s)) {
            printf("실패\n");
            return 0;
        }
        else
            here = pop(&s);
    }
    printf("성공\n");
}