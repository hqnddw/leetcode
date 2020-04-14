#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> s;

    MinStack() {

    }

    void push(int x) {
        if (s.empty())
            s.push(make_pair(x, x));
        else {
            int m = min(s.top().second, x);
            s.push(make_pair(x, m));
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

