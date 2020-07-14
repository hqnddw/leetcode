//
// Created by lwl on 2020/7/10.
//
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign = '+';
        int num = 0;
        int tmp;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                switch (sign) {
                    case '+' :
                        stk.push(num);
                        break;
                    case '-' :
                        stk.push(-num);
                        break;
                    case '*':
                        tmp = stk.top();
                        stk.pop();
                        stk.push(tmp * num);
                        break;
                    case '/':
                        tmp = stk.top();
                        stk.pop();
                        stk.push(tmp / num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};