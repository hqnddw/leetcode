//
// Created by hqnddw on 2020/5/7.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

//暴力
class Solution1 {
public:
    int nthUglyNumber(int n) {
        int res = 0;
        int count = 0;
        while (true) {
            count += helper(res);
            if (count == n)
                return res;
            res++;
        }
    }

    bool helper(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};

//动态规划
class Solution2 {
public:
    int nthUglyNumber(int n) {
        if (n == 0)
            return -1;
        if (n == 1)
            return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[i] == dp[p2] * 2) p2++;
            if (dp[i] == dp[p3] * 3) p3++;
            if (dp[i] == dp[p5] * 5) p5++;
        }
        return dp[n - 1];
    }
};

//set
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int> pq;
        if (n == 0) return 0;
        if (n == 1)return 1;
        pq.push(1);
        int count = 1;
        while (count < n) {
            int res = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == res)
                pq.pop();
            pq.push(res * 2);
            pq.push(res * 3);
            pq.push(res * 5);
            count++;
        }
        return pq.top();
    }
};