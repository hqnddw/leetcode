//
// Created by hqnddw on 2019/7/4.
//
#include <math.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

//dp动态规划
class Solution1 {
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


class Solution2 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int minimum = INT_MAX;
            int j = 1;
            while (i - j * j >= 0) {
                minimum = min(minimum, dp[i - j * j] + 1);
                j++;
            }
            dp[j] = minimum;
        }
        return dp[n];
    }
};

//BFS
class Solution {
public:
    int numSquares(int n) {
        if (n <= 1) return n;
        queue<int> q;
        unordered_set<int> set;
        int level = 0;
        q.push(n);
        while (!q.empty()) {
            int h = q.size();
            level++;
            for (int j = 0; j < h; ++j) {
                int cur = q.front();
                q.pop();
                for (int i = 1; i * i <= cur; ++i) {
                    int next = cur - i * i;
                    if (next == 0)
                        return level;
                    if (!set.count(next)) {
                        q.push(next);
                        set.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};