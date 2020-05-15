//
// Created by hqnddw on 2020/5/6.
//

class Solution {
public:
    int fib(int N) {
        if (N >= 0 && N <= 2)
            return N;
        return fib(N - 1) + fib(N - 2);
    }
};