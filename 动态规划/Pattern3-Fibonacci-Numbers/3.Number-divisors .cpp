//
// Created by yida on 2020/5/21.
//

#include <bits/stdc++.h>

using namespace std;

// 任何一个合数都可以写成几个质数相乘的形式
int divCount(int n)
{
    // sieve method for prime calculation
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    for (int p = 2; p * p < n; p++)
        if (hash[p] == true)
            for (int i = p * 2; i < n; i += p)
                hash[i] = false;

    // Traversing through all prime numbers
    int total = 1;
    for (int p = 2; p <= n; p++) {
        if (hash[p]) {

            // calculate number of divisor
            // with formula total div =
            // (p1+1) * (p2+1) *.....* (pn+1)
            // where n = (a1^p1)*(a2^p2)....
            // *(an^pn) ai being prime divisor
            // for n and pi are their respective
            // power in factorization
            int count = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}
