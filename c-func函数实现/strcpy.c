//
// Created by lwl on 2020/8/15.
//
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
char *myStrcpy(char *dst, char *src) {
    assert(dst != NULL && src != NULL);
    char *res = dst;
    int n = strlen(src);
    if (dst >= src && dst <= src + n) {
        dst = dst + n - 1;
        src = src + n - 1;
        while (n--) {
            *dst-- = *src--;
        }
    } else {
        while (n--) {
            *dst++ = *src++;
        }
    }
    return res;
}

int main(){
    char* src = "hello,world";
    char *dst = (char*) malloc(strlen(src));
    char* res = myStrcpy(dst, src);
    printf("%s\n", res);
    return 0;
}