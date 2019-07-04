//
// Created by hqnddw on 2019/6/27.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// state equations
//P[i][j] = P[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'), if p[j - 1] != '*';
//P[i][j] = P[i][j - 1] || P[i - 1][j], if p[j - 1] == '*'.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        if (n > 30000) return false; // the trick
        vector<bool> cur(m + 1, false);
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*';
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m];
    }
};


//贪婪算法
class Solution1 {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        int star = -1, match = 0;
        int i = 0, j = 0;
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                star = j;
                match = i;
                j++;
            } else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            } else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

//int main() {
//    Solution s;
//    bool b = s.isMatch("aa", "a");
//    cout << b << endl;
//}