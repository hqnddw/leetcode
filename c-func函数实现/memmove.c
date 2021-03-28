//
// Created by hqnddw on 2020/9/19.
//
#include <stdio.h>
#include <stdlib.h>

void *my_memmove(void *dst, const void *src, size_t n) {
    char *s_dst;
    char *s_src;
    s_dst = (char *) dst;
    s_src = (char *) src;
    if (s_dst > s_src && (s_src + n > s_dst)) {      //第二种内存覆盖的情形。
        // 从后往前复制，防止出现内存覆盖的情形
        s_dst = s_dst + n - 1;
        s_src = s_src + n - 1;
        while (n--) {
            *s_dst-- = *s_src--;
        }
    } else {
        while (n--) {
            *s_dst++ = *s_src++;
        }
    }
    return dst;
}