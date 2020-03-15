#include <stdio.h>
// gab ��ŭ ������ ��ҵ��� ���� ����
// ������ ������ first���� last
void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;
    for(i=first+gap; i<=last; i=i+gap) {
        key = list[i];
        for(j=i-gap; j>=first && key<list[j]; j=j-gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n) {    // n = size
    int i, gap;
    for(gap = n/2; gap>0; gap=gap/2) {
        if((gap % 2) == 0) gap++;
        for(i=0; i<gap; i++)            // �κ� ����Ʈ�� ������ gap
            inc_insertion_sort(list, i, n-1, gap);
    }
}  

int main() {
    int list[11] = {10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16};
    shell_sort(list, 11);
    for(int i=0; i<11; i++)
        printf("%d ", list[i]);
}