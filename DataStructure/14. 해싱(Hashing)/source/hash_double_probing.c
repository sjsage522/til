#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 13
typedef struct {
    char *key;
} element;

void hash_qp_add(element item, element ht[]) {
    int i, hash_value, inc = 0;
    hash_value = i = hash_function(item.key);

    while(!empty(ht[i])) {
        if(equal(item, ht[i])) {
            fprinrf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
            exit(1);
        }
        i = (hash_value + inc*inc) % TABLE_SIZE;
        inc = inc + 1;
        if(i == hash_value) {
            fprintf(stderr, "���̺��� ����á���ϴ�\n");
            exit(1);
        }
    }
    ht[i] = item;
}