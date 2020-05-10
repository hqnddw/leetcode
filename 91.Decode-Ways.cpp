//
// Created by hqnddw on 2020/5/6.
//
#include <vector>
#include <string>

using namespace std;

//O(n) space
class Solution1 {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= s.size(); ++i) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            int tmp = stoi(s.substr(i - 2, 2));
            if (tmp <= 26 && tmp >= 10)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};


//O(1) space
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int first = 1;
        int second = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= s.size(); ++i) {
            int tmp = 0;
            if (s[i - 1] != '0') {
                tmp += second;
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
                tmp += first;
            first = second;
            second = tmp;
        }
        return second;
    }
};
