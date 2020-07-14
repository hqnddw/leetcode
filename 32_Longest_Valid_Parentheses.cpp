//
// Created by hqnddw on 2019/6/26.
//
#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;



//To fill dp array we will check every two consecutive characters of the string and if
//1. s[i]==')' and s[i-1]=='(',  i.e. string looks like "......()"
//  ==>  dp[i]=dp[i−2]+2
//2. s[i]==')' and s[i-1]==')',  i.e. string looks like ".......))"
//    if s[i-dp[i-1]-1] == '(' , s[i−dp[i−1]−1]='('
//  ==> dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

//dp动态规划
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int max_len = 0;
        int dp[100000] = {};
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] -1 ]== '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2) >= 0 ?
                            dp[i - dp[i - 1] - 2] : 0) + 2;
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};
//暴力解法
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> stack1;
//        int n = s.length();
//        const char *p = s.c_str();
//        for (int i = 0; i < n; ++i) {
//            if (p[i] == '(')
//                stack1.push('(');
//            else if (!stack1.empty() && stack1.top() == '(')
//                stack1.pop();
//            else return false;
//        }
//        return stack1.empty();
//    }
//
//    int longestValidParentheses(string s) {
//        int n = s.length();
//        int max_len = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 2; j <= n; j += 2) {
//                if (isValid(s.substr(i, j - i)))
//                    max_len = max(j - i, max_len);
//            }
//        }
//        return max_len;
//    }
//};

//int main() {
//    Solution s;
//    int n = s.longestValidParentheses("(()())");
//    cout << n << endl;
//}