//
// Created by hqnddw on 2019/11/14.
//
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> s1;
    stack<int> s2;

    void push(int value) {
        s1.push(value);
        if (s2.empty() || value < s2.top()) {
            s2.push(value);
        }
    }

    void pop() {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};