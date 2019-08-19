//
// Created by hqnddw on 2019/7/5.
//
#include <math.h>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    int min = INT_MAX;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin()) s2.push(x);
    }

    void pop() {
        if (s1.top() == getMin()) s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */