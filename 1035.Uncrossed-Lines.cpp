//
// Created by yida on 2020/5/25.
//
#include <vector>

using namespace std;

//递归
class Solution1 {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        return helper(A, 0, B, 0);
    }

    int helper(vector<int> &A, int i, vector<int> &B, int j) {
        if (i == A.size() || j == B.size())
            return 0;
        if (A[i] == B[j])
            return 1 + helper(A, i + 1, B, j + 1);
        else
            return max(helper(A, i + 1, B, j), helper(A, i, B, j + 1));
    }
};


//备忘录
class Solution2 {
public:
    vector<vector<int>> memo;

    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        memo.resize(A.size(), vector<int>(B.size(), -1));
        return helper(A, 0, B, 0);
    }

    int helper(vector<int> &A, int i, vector<int> &B, int j) {

        if (i == A.size() || j == B.size())
            return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (A[i] == B[j])
            memo[i][j] = 1 + helper(A, i + 1, B, j + 1);
        else
            memo[i][j] = max(helper(A, i + 1, B, j),
                             helper(A, i, B, j + 1));
        return memo[i][j];
    }
};


//dp
class Solution {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                if (A[i-1] == B[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[A.size()][B.size()];
    }
};