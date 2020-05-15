//
// Created by hqnddw on 2019/7/5.
//
#include <math.h>
#include <iostream>
#include <stack>

using namespace std;

class MinStack1 {
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

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> s;
    MinStack() {

    }

    void push(int x) {
        if (s.empty()){
            s.push(make_pair(x, x));
        } else {
            if (x < s.top().second){
                s.push(make_pair(x, x));
            } else
                s.push(make_pair(x, s.top().second));
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};