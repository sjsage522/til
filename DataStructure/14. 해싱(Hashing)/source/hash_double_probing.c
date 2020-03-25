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
            fprinrf(stderr, "탐색키가 중복되었습니다\n");
            exit(1);
        }
        i = (hash_value + inc*inc) % TABLE_SIZE;
        inc = inc + 1;
        if(i == hash_value) {
            fprintf(stderr, "테이블이 가득찼습니다\n");
            exit(1);
        }
    }
    ht[i] = item;
}