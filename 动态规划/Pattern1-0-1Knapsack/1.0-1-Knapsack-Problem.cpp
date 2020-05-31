//
// Created by hqnddw on 2020/5/11.
//
#include <vector>
#include <iostream>

using namespace std;
/*
有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
问最多能装入背包的总价值是多大?

 样例 1:
    输入: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
    输出: 9
    解释: 装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9
*/

//递归法
class Solution1 {
public:
    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapSack(int W, int wt[], int val[], int n) {
        //base case
        if (n == 0 || W == 0)
            return 0;
        if (wt[n - 1] > W)
            return knapSack(W, wt, val, n - 1);
            // Return the maximum of two cases:
            // (1) nth item included
            // (2) not included
        else
            return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                       knapSack(W, wt, val, n - 1));
    }
};

class Solution {
public:
    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= W; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (j >= wt[i - 1])
                    dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
    }
};


int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << Solution().knapSack(W, wt, val, n) << endl;
    return 0;
}