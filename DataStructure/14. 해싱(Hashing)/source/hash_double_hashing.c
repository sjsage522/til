#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 13
typedef struct {
    char *key;
} element;

void hash_dh_add(element item, element ht[]) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);

    while(!empty(ht[i])) {
        if(equal(item, ht[i])) {
            fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
            exit(1);
        }
        i = (i + inc) % TABLE_SIZE;
        if(i == hash_value) {
            fprintf(stderr, "���̺��� ����á���ϴ�\n");
            exit(1);
        }
    }
    ht[i] = item;
}