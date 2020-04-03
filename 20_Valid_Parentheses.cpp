//
// Created by hqnddw on 2019/7/5.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution1 {
public:
    bool isValid(string s) {
        stack<char> s1;
        for (char c :s) {
            if (c == '(' || c == '{' || c == '[')
                s1.push(c);
            else {
                if (!s1.empty()) {
                    char tmp = s1.top();
                    if (tmp == '(' && c == ')') s1.pop();
                    else if (tmp == '[' && c == ']') s1.pop();
                    else if (tmp == '{' && c == '}') s1.pop();
                    else return false;
                } else return false;
            }
        }
        return s1.empty();
    }
};


class Solution2 {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c:s) {
            if (c == '(' || c == '{' || c == '[')
                stack.push(c);
            else if (!stack.empty()) {
                if (c == ')' && stack.top() != '(') return false;
                if (c == ']' && stack.top() != '[') return false;
                if (c == '}' && stack.top() != '{') return false;
                stack.pop();
            } else return false;
        }
        return stack.empty();
    }
};