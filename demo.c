//
// Created by lwl on 2020/7/13.
//

#include<stdio.h>
#include <malloc.h>
#include <string.h>

void func(char *ptr) {
    ptr = (char *) malloc(sizeof(char));
}

int main() {
    char *ptr = NULL;
    func(ptr);
    strcpy(ptr, "hello world");
}