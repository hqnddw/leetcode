//
// Created by hqnddw on 2020/9/19.
//
#include <stdlib.h>
#include   <stdio.h>
#include <string.h>

struct test {
    int a;
    char b[0];
};

int main() {
    //分配时根据实际需要的数据长度进行分配
    struct test *p = (struct test *) malloc(sizeof(struct test) + 100);
    strcpy(p->b, "test");
    printf("%s\n", p->b);
    free(p);
}