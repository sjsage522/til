#include <stdio.h>

void swap(int *px, int *py) {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main() {
    int a = 1, b = 2;
    printf("swap�� ȣ���ϱ� ��: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("swap�� ȣ���ϱ� ��: a=%d, b=%d\n", a, b);
    return 0;
}