//
// Created by hqnddw on 2019/10/31.
//
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
    int maximum = 0;
    int m = 0;

    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        for (int i = 0; i <= s.size() / 2; ++i) {
            helper(s, i, i); //odd
            helper(s, i, i + 1);
        }
        return s.substr(m, maximum - 1);
    }

    void helper(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left++;
            right++;
        }
        if (maximum < right - left - 1) {
            maximum = right - left - 1;
            m = left - 1;
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