//
// Created by hqnddw on 2019/10/19.
//
#include <stack>

using namespace std;

//使用二个栈
class MyQueue1 {
public:
    stack<int> stack1;
    stack<int> stack2;

    /** Initialize your data structure here. */
    MyQueue1() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        a = stack2.top();
        stack2.pop();
        return a;
    }

    /** Get the front element. */
    int peek() {
        int a;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        a = stack2.top();
        return a;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};


//使用一个栈
class MyQueue {
public:
    stack<int> s;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        helper(x);
    }

    void helper(int x) {
        if (s.empty()) {
            s.push(x);
        } else {
            int data = s.top();
            s.pop();
            helper(x);
            s.push(data);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a = s.top();
        s.pop();
        return a;
    }

    /** Get the front element. */
    int peek() {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};
