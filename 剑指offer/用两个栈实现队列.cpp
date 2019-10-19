//
// Created by hqnddw on 2019/10/19.
//
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    void push(int node) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {
        int a;
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        a = stack2.top();
        stack2.pop();
        return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

