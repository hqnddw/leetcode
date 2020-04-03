//
// Created by hqnddw on 2019/10/6.
//
#include <string>

using namespace std;


class Solution1 {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string res(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = (sum % 10) + '0';
                res[i + j] += sum / 10;
            }
        }
        for (int k = 0; k < res.size(); ++k) {
            if (res[k] != '0')
                return res.substr(k);
        }
        return "0";
    }
};


class Solution2 {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string res(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = sum % 10 + '0';
                res[i + j] += sum / 10 + '0';
            }
        }
        for (int k = 0; k < m + n; ++k) {
            if (res[k] != '0')
                return res.substr(k);
        }
        return "0";
    }
};