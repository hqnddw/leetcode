//
// Created by hqnddw on 2019/7/6.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s1;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            if (tokens[i] != "+" && tokens[i] != "-"
                && tokens[i] != "*" && tokens[i] != "/") {
                s1.push(stoi(tokens[i]));
            } else {
                int num1 = s1.top();
                s1.pop();
                int num2 = s1.top();
                s1.pop();
                if (tokens[i] == "+")
                    s1.push(num2 + num1);
                if (tokens[i] == "-")
                    s1.push(num2 - num1);
                if (tokens[i] == "*")
                    s1.push(num2 * num1);
                if (tokens[i] == "/")
                    s1.push(num2 / num1);
            }
        }
        return s1.top();
    }
};