//
// Created by hqnddw on 2019/7/6.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int n = s.size();
        if (n <= 1) return;
        helper(s, 0);

    }

    void helper(vector<char> &s, int i) {
        if (i > (s.size() - i - 1)) return;
        swap(s[i], s[s.size() - i - 1]);
        helper(s, i + 1);
    }
};

//int main() {
//    Solution s;
//    char str[] = "hello";
//    vector<char> s1(str, str + 5);
//    s.reverseString(s1);
//    for (auto c: s1)
//        cout << c << " ";
//}