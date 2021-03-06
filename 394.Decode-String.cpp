//
// Created by yida on 2020/5/22.
//
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

//栈
class Solution1 {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string cur;
        int k = 0;
        for (char c: s) {
            if (isdigit(c)) {
                k = k * 10 + c - '0';
            } else if (c == '[') {
                countStack.push(k);
                stringStack.push(cur);
                cur = "";
                k = 0;
            } else if (c == ']') {
                int count = countStack.top();
                countStack.pop();
                string tmp = stringStack.top();
                stringStack.pop();
                for (int i = 0; i < count; ++i) {
                    tmp += cur;
                }
                cur = tmp;
            } else cur += c;
        }
        return cur;
    }
};

class Solution2 {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(s, pos);
    }

    string helper(string s, int &pos) {
        int n = 0;
        string res;
        for (; pos < s.size(); pos++) {
            if (s[pos] == '[') {
                string str = helper(s, ++pos);
                while (n > 0) {
                    res += str;
                    n--;
                }
            } else if (isdigit(s[pos]))
                n = n * 10 + s[pos] - '0';
            else if (s[pos] == ']')
                return res;
            else res += s[pos];
        }
        return res;
    }
};


class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }

    string helper(string &s, int &i) {
        string res;
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i];
                i++;
            } else {
                int n = 0;
                while (i < s.size() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                i++;
                string tmp = helper(s, i);
                i++;
                while (n) {
                    res + tmp;
                    n--;
                }
            }
        }
        return res;
    }
};