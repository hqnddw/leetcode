//
// Created by hqnddw on 2020/10/14.
//
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addNum(string &s1, string &s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 < n2) {
            swap(s1, s2);
        }
        string s3(s1.size() - s2.size(), '0');
        s2 = s3 + s2;
        int b = 0;
        string res;
        for (int i = s1.size() - 1; i >= 1; --i) {
            b += s1[i] - '0' + s2[i] - '0';
            res += (b % 10 + '0');
            b /= 10;
        }
        b += s1[0] - '0' + s2[0] - '0';
        string tmp = to_string(b);
        reverse(tmp.begin(), tmp.end());
        res += tmp;
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution s;
    cout << s.addNum(s1, s2) << endl;
    return 0;
}