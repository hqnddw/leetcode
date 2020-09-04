//
// Created by lwl on 2020/8/16.
//

#include <stdio.h>

int fib(int n) {
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int res;
    res = fib(8);
    printf("res: %d\n", res);
    return 0;
};