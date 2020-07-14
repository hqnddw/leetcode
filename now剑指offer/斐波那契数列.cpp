//
// Created by hqnddw on 2019/11/7.
//

class Solution1 {
public:
    int Fibonacci(int n) {
        int a = 0;
        int b = 1;
        if (n == 0)
            return 0;
        while (--n) {
            b = a + b;
            a = b - a;
        }
        return b;
    }
};


class Solution2 {
public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};