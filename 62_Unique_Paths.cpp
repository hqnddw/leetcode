//
// Created by hqnddw on 2019/6/29.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//使用二维数组存储
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

//使用一维数组存储
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};


//
//int main() {
//    Solution1 s;
//    cout<<s.uniquePaths(3, 7)<<endl;
//    return 0;
//}
