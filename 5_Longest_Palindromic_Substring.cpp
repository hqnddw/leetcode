//
// Created by hqnddw on 2019/6/26.
//
#include <iostream>
#include <string>

using namespace std;
//P(i,j)=(P(i+1,j−1) and S[i]==S[j])

//base cases
//P(i,i)=true
//P(i, i+1) = ( S[i] == S[i+1] )
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int i = 0;
        int max_len = 0;
        int start_id = 0;
        for (i = 0; i < s.size();) {
            if (s.size() - i <= max_len / 2) break;
            int s_left = i;
            int s_right = i;
            while (s_right < s.size() - 1 && s[s_right] == s[s_right + 1])
                s_right++;
            i = s_right + 1;
            while (s_left > 0 && s_right < s.size() - 1 && s[s_left - 1] == s[s_right + 1]) {
                s_left--;
                s_right++;
            }
            int new_len = s_right - s_left + 1;

            if (new_len > max_len) {
                max_len = new_len;
                start_id = s_left;
            }
        }
        return s.substr(start_id, max_len);
    }
};
//class Solution {
//public:
//    // Transform S into T.
//// For example, S = "abba", T = "^#a#b#b#a#$".
//// ^ and $ signs are sentinels appended to each end to avoid bounds checking
//    string preProcess(string s) {
//        int n = s.length();
//        if (n == 0) return "^$";
//        string ret = "^";
//        for (int i = 0; i < n; i++)
//            ret += "#" + s.substr(i, 1);
//
//        ret += "#$";
//        return ret;
//    }
//
//    string longestPalindrome(string s) {
//        string T = preProcess(s);
//        int n = T.length();
//        int *P = new int[n]; //记录以字符S[i]为中心的最长回文子串向左/右扩张的长度（不包括S[i])
//        int center = 0; //id 为已知的 {右边界最大} 的回文子串的中心
//        int mx = 0; // mx=id+p[id],也就是这个子串的右边界
//        for (int i = 1; i < n - 1; i++) {
//            int i_mirror = 2 * center - i; // 等于i'=center-(i-center)
//
//
//
//            // Attempt to expand palindrome centered at i
//            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
//                P[i]++;
//
//            // If palindrome centered at i expand past R,
//            // adjust center based on expanded palindrome.
//            if (i + P[i] > mx) {
//                center = i;
//                mx = i + P[i];
//            }
//        }
//
//        // Find the maximum element in P.
//        int maxLen = 0;
//        int centerIndex = 0;
//        for (int i = 1; i < n - 1; i++) {
//            if (P[i] > maxLen) {
//                maxLen = P[i];
//                centerIndex = i;
//            }
//        }
//        delete[] P;
//
//        return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
//    }
//};

//int main() {
//    Solution s;
//    string s1 = s.longestPalindrome("babcbabcbaccba");
//    cout << s1 << endl;
//}