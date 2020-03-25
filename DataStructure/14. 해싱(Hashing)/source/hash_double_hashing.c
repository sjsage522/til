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
            fprintf(stderr, "탐색키가 중복되었습니다\n");
            exit(1);
        }
        i = (i + inc) % TABLE_SIZE;
        if(i == hash_value) {
            fprintf(stderr, "테이블이 가득찼습니다\n");
            exit(1);
        }
    }
    ht[i] = item;
}