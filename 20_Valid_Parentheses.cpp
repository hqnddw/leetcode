//
// Created by hqnddw on 2019/7/5.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{')
                stack.push(c);
            else {
                if (stack.empty()) return false;
                if (c == ')' && stack.top() != '(') return false;
                if (c == ']' && stack.top() != '[') return false;
                if (c == '}' && stack.top() != '{') return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};

//int main() {
//    Solution solution;
//    string s = "{()[]}";
//    cout << solution.isValid(s) << endl;
//}