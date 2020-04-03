//
// Created by hqnddw on 2019/11/11.
//
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (q2.empty()) {
            q1.push(x);
        } else q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = 0;
        if (!q1.empty()) {
            while (!q1.empty()) {
                a = q1.front();
                q1.pop();
                if (!q1.empty())
                    q2.push(a);
            }
            return a;
        } else {
            while (!q2.empty()) {
                a = q2.front();
                q2.pop();
                if (!q2.empty())
                    q1.push(a);
            }
            return a;
        }
    }

    /** Get the top element. */
    int top() {
        int a = 0;
        if (!q1.empty()) {
            while (!q1.empty()) {
                a = q1.front();
                q1.pop();
                q2.push(a);
            }
            return a;
        } else {
            while (!q2.empty()) {
                a = q2.front();
                q2.pop();
                q1.push(a);
            }
            return a;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
