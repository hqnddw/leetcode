//
// Created by hqnddw on 2019/6/20.
//
#include <iostream>
#include <ctime>

using namespace std;

//递归
long fib1(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    else return fib1(n - 1) + fib1(n - 2);
}

//自顶向下
long F[1000] = {0};

long fib2(int n) {

    if (n == 0) {
        F[0] = 1;
        return F[0];
    }
    if (n == 1) {
        F[1] = 1;
        return F[1];
    }
    if (F[n])
        return F[n];//避免重复计算，有值立即返回
    else {
        F[n] = fib2(n - 1) + fib2(n - 2);
        return F[n];
    }
}

//自底向上
int F1[1000000];

long fib3(int n) {
    F1[0] = 1;
    F1[1] = 1;
    for (int i = 2; i <= n; i++) {
        F1[i] = F1[i - 1] + F1[i - 2];
    }
    return F1[n];

}

//int main() {
//    clock_t beg1, end1;
//    long n1;
//    beg1 = clock();
//    n1 = fib1(45);
//    end1 = clock();
//    cout << "n1:" << n1 << endl;
//    cout << "运行时间：" << end1 - beg1 << endl;
//    cout << "-----------------" << endl;
//    clock_t beg2, end2;
//    long n2;
//    beg2 = clock();
//    n2 = fib2(45);
//    end2 = clock();
//    cout << "n2:" << n2 << endl;
//    cout << "运行时间：" << end2 - beg2 << endl;
//    cout << "-----------------" << endl;
//    clock_t beg3, end3;
//    long n3;
//    beg3 = clock();
//    n3 = fib3(45);
//    end3 = clock();
//    cout << "n3:" << n3 << endl;
//    cout << "运行时间：" << end3 - beg3 << endl;
//    cout << "-----------------" << endl;
//    return 0;
//}
