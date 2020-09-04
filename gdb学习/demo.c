//
// Created by lwl on 2020/8/16.
//

//
// Created by lwl on 2020/7/13.
//

#include<stdio.h>
#include <malloc.h>

int func(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int res = 0;
    for (int i = 0; i < 100; ++i) {
        res += i;
    }
    printf("result[1-100]: %d\n", res);
    printf("result[1-250]: %d", func(250));
}
