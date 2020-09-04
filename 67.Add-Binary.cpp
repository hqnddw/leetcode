//
// Created by lwl on 2020/7/29.
//
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int count = 0;
        string res;
        while (i >= 0 || j >= 0 || count) {
            int sum = 0;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            sum += count;
            if (sum <= 1) {
                res += to_string(sum);
                count = 0;
            } else {
                res += to_string(sum - 2);
                count = 1;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};