//
// Created by hqnddw on 2020/9/19.
//
#include <stdio.h>
#include <stdlib.h>

void* my_memcpy(void* dst, const void* src, size_t n)
{
    char *tmp = (char*)dst;
    char *s_src = (char*)src;
    while(n--) {
        *tmp++ = *s_src++;
    }
    return dst;
}