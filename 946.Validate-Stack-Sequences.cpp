//
// Created by hqnddw on 2019/10/21.
//
#include <vector>
#include <stack>

using namespace std;

//贪心算法
class Solution1 {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int pt = 0;
        int n = pushed.size();
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            s.push(pushed[i]);
            while (!s.empty() && pt < n && s.top() == popped[pt]) {
                s.pop();
                pt++;
            }
        }
        return pt == n;
    }
};


class Solution2 {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        if (pushed.empty() && popped.empty()) return true;
        stack<int> s;
        int j = 0;
        for (int i : pushed) {
            s.push(pushed[i]);
            while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};