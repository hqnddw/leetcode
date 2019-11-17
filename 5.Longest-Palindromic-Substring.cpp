//
// Created by hqnddw on 2019/10/31.
//
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
    int maxLen = 0;
    int left = 0;

    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        string res;
        for (int i = 0; i < s.size() - 1; ++i) {
            helper(s, i, i);
            helper(s, i, i + 1);
        }
        res = s.substr(left, maxLen);
        return res;
    }

    void helper(string &s, int lo, int hi) {
        while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
            lo--;
            hi++;
        }
        if (maxLen < hi - lo - 1) {
            maxLen = hi - lo - 1;
            left = ++lo;
        }
    }
};

//动态规划
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool >> dp(n, vector<bool>(n, false));
        string res = "";
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if ((s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1])) //动态规划的公式
                    dp[i][j] = true;
                if (dp[i][j] && (res.size() == 0 || j - i + 1 > s.size()))
                    res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};


class Solution3 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res("");
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
                if (dp[i][j] && (res.size() == 0 || j - i + 1 > res.size()))
                    res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};