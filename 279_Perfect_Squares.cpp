//
// Created by hqnddw on 2019/7/4.
//
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

//动态规划
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
//任意整数都可表示为4个整数的平方
//class Solution {
//public:
//    int numSquares(int n) {
//        if (isSquare(n))
//            return 1;
//        while (n % 4 == 0) {
//            n /= 4;
//        }
//        if (n % 8 == 7)
//            return 4;
//        int temp = (int) sqrt(n);
//        for (int i = 1; i <= n; ++i) {
//            if (isSquare(n - i * i))
//                return 2;
//        }
//        return 3;
//    }
//
//    bool isSquare(int n) {
//        long long temp = (int) sqrt(n);
//        return temp * temp == n;
//    }
//};


//int main() {
//    Solution s;
//    cout << s.numSquares(7) << endl;
//}